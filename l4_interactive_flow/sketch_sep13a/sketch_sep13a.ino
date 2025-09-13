int led_num = 5;
byte led_pin[] = {2, 3, 4, 5, 6};
int led_delay;
int direction = 1;
int current_led = 0;
unsigned long change_time;
int pot_pin = A0;

void setup() {

  Serial.begin(9600);

  for (int i = 0; i < led_num; i++)
  {
    pinMode(led_pin[i], OUTPUT);
  }
  change_time = millis();

}

void loop() {

 int raw = analogRead(pot_pin); // 0 to 1023
 led_delay = map(raw, 0, 1023, 30, 800);   // map to 30 to 800

 Serial.println(String("led_delay = ") + led_delay);
 Serial.println(String("millis() - change_time = ") + (millis() - change_time));

 if ((millis() - change_time) > led_delay)
 {
  change_led();
  change_time = millis();
 }

 // delay(500);
}


void change_led()
{
  for (int i = 0; i < led_num; i++)
  {
    digitalWrite(led_pin[i], HIGH);
  }

  digitalWrite(led_pin[current_led], LOW); // active low

  current_led += direction;

  if (current_led == led_num - 1)
  {
    direction = -1;
  }

  if (current_led == 0)
  {
    direction = 1;
  }
}