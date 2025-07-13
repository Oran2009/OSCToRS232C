#include "display.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setupDisplay() {
  // Initialize the display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 allocation failed");
    for (;;)
      ; // Don't proceed, loop forever
  }

  // Clear the buffer
  display.clearDisplay();

  // Set text size and color
  display.setTextSize(2);
  display.setTextColor(WHITE);

  // Display initial message
  display.setCursor(0, 0);
  display.println("Connecting to WiFi...");
  display.display();
}

void updateDisplay(const String &message) {
  // Clear the display
  display.clearDisplay();

  // Set cursor to the top left corner
  display.setCursor(0, 0);

  // Print the message
  display.println(message);

  // Update the display
  display.display();
}