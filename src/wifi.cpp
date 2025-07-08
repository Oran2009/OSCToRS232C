#include "wifi.h"
#include "globals.h" // For DEBUG

void setupWiFi() {
  WiFiManager wifiManager;
  wifiManager.autoConnect("VideoMixer-OSC-AP");
  if (DEBUG) {
    Serial.println("WiFi connected");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  }
}