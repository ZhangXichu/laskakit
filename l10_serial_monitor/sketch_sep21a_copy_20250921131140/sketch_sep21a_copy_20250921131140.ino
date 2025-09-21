const int blue_pin = 2;
const int yellow_pin = 3;
const int red_pin = 4;
String user_in = "";

void setup() {
  pinMode(blue_pin, OUTPUT);
  pinMode(yellow_pin, OUTPUT);
  pinMode(red_pin, OUTPUT);

  Serial.begin(9600);
  Serial.print("Input color of LED: ");
}

void loop() {
  if (Serial.available() > 0)
  {
    user_in = "";
    while (Serial.available() > 0) 
    {
      user_in += char(Serial.read());
      delay(2);
    }
    Serial.println(user_in);
  }

  if (user_in == "red")
  {
    digitalWrite(red_pin, HIGH);
    digitalWrite(blue_pin, LOW);
    digitalWrite(yellow_pin, LOW);
  } else if (user_in == "yellow") 
  {
    digitalWrite(yellow_pin, HIGH);
    digitalWrite(blue_pin, LOW);
    digitalWrite(red_pin, LOW);
  } else if (user_in == "blue") 
  {
    digitalWrite(blue_pin, HIGH);
    digitalWrite(yellow_pin, LOW);
    digitalWrite(red_pin, LOW);
  } else 
  {
    digitalWrite(blue_pin, LOW);
    digitalWrite(yellow_pin, LOW);
    digitalWrite(red_pin, LOW);
  }

}
