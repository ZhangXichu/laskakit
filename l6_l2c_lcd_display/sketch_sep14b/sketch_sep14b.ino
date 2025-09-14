#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>


char msg1[] = "greet 1    ";
char msg2[] = "greet 2    ";
int delay_time = 500;

size_t str_len = strlen(msg1); 

LiquidCrystal_I2C lcd(0x27, 16, 2);
 
void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  lcd.clear();
  lcd.setCursor(15, 0);

  for (int i = 0; i < str_len; i++)
  {
    lcd.scrollDisplayLeft();
    lcd.print(msg1[i]);
    delay(delay_time);
  }

  lcd.clear();
  lcd.setCursor(15, 1);

  for (int i = 0; i < str_len; i++)
  {
    lcd.scrollDisplayLeft();
    lcd.print(msg2[i]);
    delay(delay_time);
  }

  lcd.clear();
}
