#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
const int water_sensor = 0;
int water_val = 0;

void setup() {

Serial.begin(9600);
  unsigned long start = millis();

  // wait 3s for Serial
  while (!Serial && millis() - start < 3000) { } 

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Water volum:");

}

void loop() {

  water_val = analogRead(water_sensor);

  int water_percent = map(water_val, 0, 1023, 0, 100);

  lcd.setCursor(6,1);

  lcd.print(water_percent); // how much of the sensor is submerged

  delay(300);

  lcd.setCursor(0,1);

  lcd.print("                ");

}
