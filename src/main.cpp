#include "commands.h"
#include "display.h"
#include "globals.h"
#include "wifi.h"
#include <Arduino.h>
#include <ArduinoOSCWiFi.h>
#include <WiFiManager.h>

// OSC settings
const int OSC_PORT = 54321;

void handleOSC();

void setup() {
  RS232C_SERIAL.begin(9600, SERIAL_7O1);

  setupDisplay(); // Initialize the display

  // Initialize and connect to WiFi
  setupWiFi();
  updateDisplay("IP:\n\n" + WiFi.localIP().toString());

  handleOSC(); // Set up OSC handlers
}

void loop() { OscWiFi.update(); }

void handleOSC() {
  // map OSC addresses to RS232C commands
  OscWiFi.subscribe(OSC_PORT, "/source1", [](const OscMessage &m) {
    setCmdNoReplace(MX30_A_BUS_SOURCE_1);
    sendCmd();
  });
  OscWiFi.subscribe(OSC_PORT, "/source2", [](const OscMessage &m) {
    setCmdNoReplace(MX30_A_BUS_SOURCE_2);
    sendCmd();
  });
  // Add more OSC address handlers as needed
}