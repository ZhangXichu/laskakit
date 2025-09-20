int buzzer = 12;

void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {
  unsigned char i;

  while(1)
  {
    for (i = 0; i < 80; i++)
    {
      digitalWrite(buzzer, HIGH);
      delay(3);
      digitalWrite(buzzer, LOW);
      delay(3);
    }

    for (i = 0; i < 80; i++) // other frequency
    {
      digitalWrite(buzzer, HIGH);
      delay(2);
      digitalWrite(buzzer, LOW);
      delay(2);
    }
  }

}
