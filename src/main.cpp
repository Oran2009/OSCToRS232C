#include "commands.h"
#include "globals.h"
#include "wifi.h"
#include <Arduino.h>
#include <ArduinoOSCWiFi.h>
#include <WiFiManager.h>

// Globals
bool DEBUG = true;

// RS232C serial port (to video mixer via MAX3232)
HardwareSerial &RS232C_SERIAL = Serial1;
#define RS232_BAUD 9600

// OSC settings
const int OSC_PORT = 8000; // Port to listen for OSC

void mapOSC();

void setup() {
  Serial.begin(115200);
  setupWiFi();

  RS232C_SERIAL.begin(RS232_BAUD, SERIAL_7O1);

  mapOSC();

  if (DEBUG) {
    Serial.println("Setup complete, debug mode ON");
  }
}

void loop() { OscWiFi.update(); }

void mapOSC() {
  // Example: map OSC addresses to RS232C commands
  OscWiFi.subscribe(OSC_PORT, "/mx/source1", []() {
    setCmdNoReplace(MX30_A_BUS_SOURCE_1);
    sendCmd(RS232C_SERIAL);
  });
  OscWiFi.subscribe(OSC_PORT, "/mx/source2", []() {
    setCmdNoReplace(MX30_A_BUS_SOURCE_2);
    sendCmd(RS232C_SERIAL);
  });
  // Add more OSC address handlers as needed
}