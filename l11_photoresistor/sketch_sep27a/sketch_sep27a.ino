
const int num_led = 4;
const int led_pins[] = {5, 6, 7, 8};

const int led_pin_1 = 5;

const int photocell_pin = A0;
int sensor_val = 0;
int led_level = 0;

void setup() {
  for (int i = 0; i < num_led; i++) {
    pinMode(led_pins[i], OUTPUT);
  }

  Serial.begin(9600);

}

void loop() {
  sensor_val = analogRead(photocell_pin);

  Serial.println(sensor_val);

  led_level = map(sensor_val, 300, 1023, 0, num_led);
  led_level = constrain(led_level, 0, num_led);

  Serial.println("led_level: ");
  Serial.println(led_level);

  for (int i = 0; i < num_led; i++)
  {
    digitalWrite(led_pins[i], (i < led_level) ? HIGH : LOW);
  }

  delay(50);
}
