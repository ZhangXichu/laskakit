#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);
  while (!Serial);
  Serial.println("\nI2C scener");
}

void loop() {
 byte error, address;
 int n_devices;

 n_devices = 0;

 for (address = 1; address < 127; address++)
 {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0)
    {
      Serial.print("I2C device found on address 0x");
      if (address < 16) 
      {
        Serial.println("0");
      }
      Serial.println(address, HEX);
      Serial.println(" .");

      n_devices++;
    } else if (error == 4)
    {
      Serial.print("Unknown error on address 0x");
      if (address < 16) 
      {
        Serial.println("0");
      }
      Serial.println(address, HEX);
    }
 } 

 if (n_devices == 0)
 {
   Serial.println("No I2C device found\n");
 } else {
   Serial.println("Donw\n");
 }

 delay(5000);

}
