
  int green_target_value = -500;
  int blue_target_value = -500;
  int red_target_value = -500;
  
  const int green_led_pin = 9;
  const int blue_led_pin = 10;
  const int red_led_pin = 11;
  const int target_color_pin = 12;

  const int red_sensor_pin = A0;
  const int green_sensor_pin = A1;
  const int blue_sensor_pin = A2;

  int red_value = 0;
  int green_value = 0;
  int blue_value = 0;

  int red_sensor_value = 0;
  int green_sensor_value = 0;
  int blue_sensor_value = 0;
  
  bool game_started = false;
  bool red_found = false;
  bool blue_found = false;
  bool green_found = false;


void setup()
{
  Serial.begin(9600);

  pinMode(green_led_pin, OUTPUT);
  pinMode(blue_led_pin, OUTPUT);
  pinMode(red_led_pin, OUTPUT);
  pinMode(target_color_pin, INPUT);
  digitalWrite(12, LOW);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  red_sensor_value = analogRead(red_sensor_pin);
  delay(5);
  green_sensor_value = analogRead(green_sensor_pin);
  delay(5);
  blue_sensor_value = analogRead(blue_sensor_pin);

  Serial.print("raw_red: ");
  Serial.print(red_sensor_value);
  Serial.print(" | raw_green: ");
  Serial.print(green_sensor_value);
  Serial.print(" | raw blue: ");
  Serial.print(blue_sensor_value);
  Serial.print("\t");

  red_value = (red_sensor_value)/4;
  green_value = green_sensor_value/4;
  blue_value = blue_sensor_value/4;


    Serial.print("mapped red: ");
    Serial.print(red_value);
    Serial.print(" | mapped_green: ");
    Serial.print(green_value);
    Serial.print(" | mapped_blue: ");
    Serial.print(blue_value);
    if (!game_started)
      Serial.print("\n");
    else
    {
      Serial.print("\t");
      Serial.print("Rbgs target witouth specifying :-) ");
      Serial.print(red_target_value);
      Serial.print(green_target_value);
      Serial.print(blue_target_value);
      Serial.print("\n");
    }

    if (!game_started && digitalRead(12))
    {
      game_started = true;
      red_target_value = red_value;
      green_target_value = green_value;
      blue_target_value = blue_value;
      red_value = blue_value = green_value = 0;
      analogWrite(red_led_pin, 0);
      analogWrite(blue_led_pin, 0);
      analogWrite(green_led_pin, 0);
      Serial.print("GAME STARTS NOW: YOU HAVE 10 SECONDS TO CHANGE THE LIGHT ENVIRONMENT :)\n");
      digitalWrite(12,LOW);
      delay(10000);
    }
  if (game_started)
  {
    if (red_value == red_target_value && !red_found)
    {
      Serial.print("congrats, you found red, now keeping it static\n");
      analogWrite(red_led_pin, red_target_value);
      red_found = true;
      delay(5000);
    }
    if (blue_value == blue_target_value && !blue_found)
    {
      analogWrite(blue_led_pin, blue_target_value);
      Serial.print("congrats, you fount blue, now keeping it static\n");
      blue_found = true;
      delay(5000);
    }
    if (green_value == green_target_value && !green_found)
    {
      analogWrite(green_led_pin, green_target_value);
      Serial.print("congrats, you found green, now keeping it static\n");
      green_found = true;
      delay(5000);
    }
  }
  if (!red_found)
    analogWrite(red_led_pin, red_value);
  if (!green_found)
    analogWrite(green_led_pin, green_value);
  if (!blue_found)
    analogWrite(blue_led_pin, blue_value);
  if (red_found && blue_found && green_found)
  {
    game_started = blue_found = green_found = red_found = false;
    Serial.print("YEAHHH, congrats, you found the rbg combination\n");
    delay(1000);
    Serial.print("Winning combination: Red: ");
    Serial.print(red_target_value);
    Serial.print(" | Blue: ");
    Serial.print(blue_target_value);
    Serial.print(" | Green: ");
    Serial.print(green_target_value);
    Serial.print("\n");
    Serial.print("You will now be able to play another match in 10 seconds\n");


    red_value = blue_value = green_value = 0;
    red_target_value = green_target_value = blue_target_value = -500;
    analogWrite(red_led_pin, 0);
    analogWrite(blue_led_pin, 0);
    analogWrite(green_led_pin, 0);
    delay(10000);
  }
}