#include "wifi.h"
#include "globals.h"     // For DEBUG
#include <WiFiManager.h> // WiFiManager for WiFi setup

void setupWiFi() {
  WiFiManager wifiManager;
  wifiManager.autoConnect("VideoMixer-OSC-AP");
}