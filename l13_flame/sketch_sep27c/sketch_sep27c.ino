int flame = A0;
int led = 13;
int val = 0;

void setup() {

  pinMode(led, OUTPUT);
  pinMode(flame, INPUT);
  Serial.begin(9600);

}

void loop() {
  val = analogRead(flame);
  Serial.println(val);
  if (val > 30)
  {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}
