#include <LiquidCrystal.h>
#include "CountDown.h"
#include "start_animation.h"

const int button = 12;
const int yellow = 11;
const int green = 2;
const int buzzer = A0;  // Define the analog pin as buzzer pin
const int rs = 9, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int buttonState = 0;
bool timerStarted = false;
CountDown CD(CountDown::SECONDS);  // Use seconds as the resolution

void setup() {
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);  // Initialize the analog pin as an output
  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.print("Pomodoro Timer!");

  CD.start(0, 0, 25, 0);  // Start 25-minute timer
}

void loop() {
  buttonState = digitalRead(button);

  if (buttonState == LOW && !timerStarted) {
    CD.start(0, 0, 25, 0);  // Start 25-minute timer in seconds
    timerStarted = true;
    digitalWrite(yellow, LOW);
    digitalWrite(green, HIGH);
    // Beep the buzzer for 0.5 seconds when the timer starts
    tone(buzzer, 1000);  // Start the tone at 1000 Hz
    delay(300);          // Wait for 0.5 seconds
    noTone(buzzer);      // Stop the tone
    startAnimation();    // Call animation function
    lcd.clear();
    lcd.print("Pomodoro started!");

    delay(500);  // Short delay to avoid multiple button presses
  }

  if (timerStarted) {
    lcd.setCursor(0, 1);

    // Calculate remaining time in minutes and seconds
    unsigned long remainingSeconds = CD.remaining();
    unsigned int minutes = remainingSeconds / 60;
    unsigned int seconds = remainingSeconds % 60;

    // Display the remaining time in MM:SS format
    lcd.print("Remaining: ");
    if (minutes < 10) {
      lcd.print('0');
    }
    lcd.print(minutes);
    lcd.print(':');
    if (seconds < 10) {
      lcd.print('0');
    }
    lcd.print(seconds);
    lcd.print("  ");  // Clear any remaining characters

    if (remainingSeconds == 0) {
      timerStarted = false;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Time's up!      ");
      lcd.setCursor(0, 1);
      lcd.print("good job :)     ");

      // Flash yellow LED and beep buzzer
      for (int i = 0; i < 6; i++) {
        digitalWrite(yellow, (i % 2 == 0) ? HIGH : LOW);  // Toggle LED
        if (i % 2 == 0) {
          tone(buzzer, 1000, 300);  // Play tone at 1000 Hz for 300 milliseconds
        } else {
          noTone(buzzer);  // Stop the tone
        }
        delay(300);  // Adjust the delay to control the flashing and beeping duration
      }

      digitalWrite(yellow, LOW);
      noTone(buzzer);  // Ensure buzzer is turned off
      delay(3000);
      lcd.clear();
      lcd.print("Pomodoro Timer!");
    }
  } else {
    lcd.setCursor(0, 1);
    lcd.print("Push to start");
    // Blink green LED
    digitalWrite(green, (millis() % 1000 < 500) ? HIGH : LOW);
    digitalWrite(yellow, HIGH);
    delay(100);
    noTone(buzzer); 
  }
}
