#include "commands.h"
#include "display.h"
#include "globals.h"
#include "wifi.h"
#include <Arduino.h>
#include <ArduinoOSCWiFi.h>
#include <WiFiManager.h>

// Globals
bool DEBUG = true;

// RS232C serial port (to video mixer via MAX3232)
HardwareSerial &RS232C_SERIAL = Serial1;
#define RS232C_BAUD 9600

// OSC settings
const int OSC_PORT = 54321; // Port to listen for OSC

void handleOSC();

void setup() {
  Serial.begin(9600);
  RS232C_SERIAL.begin(RS232C_BAUD, SERIAL_7O1);
  // Serial.swap();

  setupDisplay(); // Initialize the display

  // Initialize and connect to WiFi
  setupWiFi();  
  updateDisplay("IP:\n\n" + WiFi.localIP().toString());

  handleOSC();  // Set up OSC handlers

  if (DEBUG) {
    Serial.println("Setup complete, debug mode ON");
  }
}

void loop() { OscWiFi.update(); }

void handleOSC() {
  // map OSC addresses to RS232C commands
  OscWiFi.subscribe(OSC_PORT, "/source1", [](const OscMessage &m) {
    Serial.println("Received /source1 OSC message");
    setCmdNoReplace(MX30_A_BUS_SOURCE_1);
    sendCmd(RS232C_SERIAL);
  });
  OscWiFi.subscribe(OSC_PORT, "/source2", [](const OscMessage &m) {
    Serial.println("Received /source2 OSC message");
    setCmdNoReplace(MX30_A_BUS_SOURCE_2);
    sendCmd(RS232C_SERIAL);
  });
  // Add more OSC address handlers as needed
}