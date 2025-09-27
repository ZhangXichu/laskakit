const int photocell_pin = A0;

int sensor_val = 0;

const int buzzer_pin = 9;


void setup() {
  pinMode(buzzer_pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensor_val = analogRead(photocell_pin);

  Serial.println("Sensor value: ");
  Serial.println(sensor_val);

  digitalWrite(buzzer_pin, HIGH);
  delay(sensor_val);
  digitalWrite(buzzer_pin, LOW);
  delay(sensor_val);

}
