#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int water;
LiquidCrystal_I2C lcd(0x27, 16, 4);

void setup() {
  pinMode(3, OUTPUT);  // relay
  pinMode(6, INPUT);   // soil sensor

  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() { 
  water = digitalRead(6);

  if (water == HIGH) {
    digitalWrite(3, LOW);        // relay off → pump off
    lcd.setCursor(0, 0);
    lcd.print("Soil: DRY       ");
    lcd.setCursor(0, 1);
    lcd.print("Pump: ON       ");
  } else {
    digitalWrite(3, HIGH);       // relay on → pump on
    lcd.setCursor(0, 0);
    lcd.print("Soil: WET       ");
    lcd.setCursor(0, 1);
    lcd.print("Pump: OFF        ");
  }

  delay(400);
}