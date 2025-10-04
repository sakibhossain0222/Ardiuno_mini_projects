#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Change 0x27 if your LCD address is different

int leds[] = {3, 4, 5, 6, 7}; // LED pins
int buzzer = 8;
int totalTime = 10; // total time in seconds
int interval = 2;   // interval per LED in seconds

void setup() {
  // Setup pins
  for (int i = 0; i < 5; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(buzzer, OUTPUT);

  // Setup LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Timer Started");
}

void loop() {
  // Countdown LEDs
  for (int i = 0; i < 5; i++) {
    delay(interval * 1000);       // wait 2 sec
    digitalWrite(leds[i], HIGH);  // turn on next LED
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Time Passed:");
    lcd.setCursor(0,1);
    lcd.print((i+1)*interval);
    lcd.print(" sec");
  }



    for (int i = 10; i >= 1; i--) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Time: ");
      lcd.print(11 - i); // Display 1 when i=10, 2 when i=9, etc.
      delay(1000); // Wait 1 second
    }
    // After countdown, you can display a message or repeat
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Done!");
    while (true) {} // Stop further execution
}
