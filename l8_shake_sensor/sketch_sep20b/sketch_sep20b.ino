const int led_pin = 13;
const int tilt_pin = 2;


void setup() {
  pinMode(led_pin, OUTPUT);
  pinMode(tilt_pin, INPUT_PULLUP);
}

void loop() {
  int digital_val = digitalRead(tilt_pin);

  delay(300);

  if (HIGH == digital_val) // not tilted
  {
    digitalWrite(led_pin, HIGH);
  } else {
    digitalWrite(led_pin, LOW);
  }

}
