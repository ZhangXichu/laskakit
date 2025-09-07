
const int led_pin = 9;


void setup() {

  pinMode(led_pin, OUTPUT);

}

void loop() {

  for (int a = 0; a <= 10; a++)
  {
    analogWrite(led_pin, a);
    delay(80);
  }

  for (int a = 10; a >= 0; a--)
  {
    analogWrite(led_pin, a); // brightness of LED
    delay(80);
  }
  delay(800);

}
