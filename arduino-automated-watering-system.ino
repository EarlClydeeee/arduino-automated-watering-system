#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN A3
#define DHTTYPE DHT11

int water;
int h;
int t;

unsigned long lastDHTUpdate = 0;
const unsigned long dhtInterval = 2000;

LiquidCrystal_I2C lcd(0x27, 16, 4);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(3, OUTPUT);  // relay
  pinMode(6, INPUT);   // soil sensor

  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.clear();

  dht.begin();
}

void loop() { 
  water = digitalRead(6);

  // Row 1 & 2: Soil sensor + pump status
  if (water == HIGH) {
    digitalWrite(3, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Soil: DRY       ");
    lcd.setCursor(0, 1);
    lcd.print("Pump: ON        ");
  } else {
    digitalWrite(3, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Soil: WET       ");
    lcd.setCursor(0, 1);
    lcd.print("Pump: OFF       ");
  }

  // Row 3 & 4: DHT11 temperature and humidity (standalone, updates on its own interval)
  if (millis() - lastDHTUpdate >= dhtInterval) {
    lastDHTUpdate = millis();

    h = dht.readHumidity();
    t = dht.readTemperature();

    lcd.setCursor(0, 2);
    lcd.print("Temp: ");
    lcd.print(t);
    lcd.print("C       ");

    lcd.setCursor(0, 3);
    lcd.print("Humidity: ");
    lcd.print(h);
    lcd.print("%     ");

    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %, Temp: ");
    Serial.print(t);
    Serial.println(" C");
  }

  delay(100);
}