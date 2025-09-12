const int lowest_pin = 2;
const int highest_pin = 6;

void setup() {

  for (int current_pin = lowest_pin; current_pin <= highest_pin; current_pin++)
  {
    pinMode(current_pin, OUTPUT);
  }

}

void loop() {
  for (int current_pin = lowest_pin; current_pin <= highest_pin; current_pin++)
  {
    digitalWrite(current_pin, HIGH);
    delay(500);
  }

  for (int current_pin = highest_pin; current_pin >= lowest_pin; current_pin--)
  {
    digitalWrite(current_pin, LOW);
    delay(500);
  }

  for (int current_pin = highest_pin; current_pin >= lowest_pin; current_pin--)
  {
    digitalWrite(current_pin, HIGH);
    delay(500);
  }

  for (int current_pin = lowest_pin; current_pin <= highest_pin; current_pin++)
  {
    digitalWrite(current_pin, LOW);
    delay(500);
  }

}
