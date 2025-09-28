#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27,16,2);
int volt = A0;

void setup() {
  Serial.begin(9600);
  unsigned long start = millis();

  // wait 3s for Serial
  while (!Serial && millis() - start < 3000) { } 

  lcd.init();
  lcd.backlight();
  lcd.setCursor(5,0);
  lcd.print("Voltage:");
}

void loop() {
  // 10-bit ADC: 0..1023. Use 1023.0 for correct scaling
  float val_raw = analogRead(volt);
  float val = val_raw / 1023 * 5.0;

  Serial.print(val);
  Serial.println("V");

  lcd.setCursor(6,1);
  lcd.print(val);
  lcd.print("V");
  delay(300);
}
