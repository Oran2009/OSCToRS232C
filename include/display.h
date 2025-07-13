#pragma once
#include <Wire.h>

void setupDisplay();
void updateDisplay(const String &message);

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
