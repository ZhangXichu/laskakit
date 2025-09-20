#define buzzer_pin 5

#define button_1 2
#define button_2 3
#define button_3 4
#define button_4 9

#define led_1 6
#define led_2 7
#define led_3 8
#define led_4 10


uint8_t b1_state, b2_state, b3_state, b4_state = 0;
uint8_t flag = 0;


void setup() {
  Serial.begin(9600);

  pinMode(buzzer_pin, OUTPUT);

  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);

  pinMode(button_1, INPUT_PULLUP);
  pinMode(button_2, INPUT_PULLUP);
  pinMode(button_3, INPUT_PULLUP);
  pinMode(button_4, INPUT_PULLUP);

  digitalWrite(led_1, LOW);
  digitalWrite(led_2, LOW);
  digitalWrite(led_3, LOW);
  digitalWrite(led_4, LOW);
}

void loop() {
  b1_state = digitalRead(button_1);
  b2_state = digitalRead(button_2);
  b3_state = digitalRead(button_3);
  b4_state = digitalRead(button_4);

  digitalWrite(led_1, LOW);
  digitalWrite(led_2, LOW);
  digitalWrite(led_3, LOW);
  digitalWrite(led_4, LOW);

  // Serial.print("Button 1 state: ");
  // Serial.println(b1_state);

  if (b4_state == 0)
  {
    flag = 1;
    digitalWrite(led_4, HIGH);
    delay(200);
  }

  if (flag == 1) {

    if (b1_state == 0)
    {
      digitalWrite(led_1, HIGH);
      alarm();
      flag = 0;
    }

    if (b2_state == 0)
    {
      digitalWrite(led_2, HIGH);
      alarm();
      flag = 0;
    }

    if (b3_state == 0)
    {
      digitalWrite(led_3, HIGH);
      alarm();
      flag = 0;
    }
  }

}


void alarm()
{
    digitalWrite(buzzer_pin, HIGH);
    delay(100);                     // ON for 100 ms
    digitalWrite(buzzer_pin, LOW);
    delay(300);
}