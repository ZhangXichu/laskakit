const int key_pin = 12; // button pin
const int led_pin = LED_BUILTIN;


void setup() {
  // put your setup code here, to run once:
  pinMode(key_pin, INPUT);
  pinMode(led_pin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(key_pin) == HIGH) // button pressed
  {
    digitalWrite(led_pin, HIGH);
  } else {
    digitalWrite(led_pin, LOW);
  }

}
