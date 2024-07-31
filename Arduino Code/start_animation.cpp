#include <Arduino.h>
#include <LiquidCrystal.h>
#include "start_animation.h"

// Define the custom characters
byte zero[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
byte one[] = {
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000
};
byte two[] = {
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000
};
byte three[] = {
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100
};
byte four[] = {
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110
};
byte five[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

// Define the LCD instance
extern LiquidCrystal lcd;

void setupAnimation() {
  lcd.createChar(0, zero);
  lcd.createChar(1, one);
  lcd.createChar(2, two);
  lcd.createChar(3, three);
  lcd.createChar(4, four);
  lcd.createChar(5, five);
}

void quickProgressBar() {
  for (int line = 0; line < 2; line++) {
    for (int i = 0; i < 16; i++) {
      lcd.setCursor(i, line);
      lcd.write(5); // Custom character for progress
      delay(20);
    }
  }
  delay(300); // Keep the bar displayed for a short while
}

void startAnimation() {
  setupAnimation();
  quickProgressBar();
}
