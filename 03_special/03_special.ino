const float b_temp = 23.5;
const int sensorPin = A0;
float record = 27.5;

void  setup()
{
  Serial.begin(9600);
  for(int n_pin = 3; n_pin < 5; n_pin++)
  {
    pinMode(n_pin, OUTPUT);
    digitalWrite(n_pin, LOW);
  }
}

void loop()
{
  int   sensor_val;
  float voltage;
  float temperature;

  sensor_val = analogRead(sensorPin);
  voltage = (sensor_val / 1023.0) * 5.0;
  temperature = 25 + (voltage - 0.75) * 100;
  
  Serial.print("Sensor Value: ");
  Serial.print(sensor_val);
  Serial.print("\n");
  Serial.print("voltage: ");
  Serial.print(voltage);
  Serial.print("\n");
  Serial.print("degrees in C: ");
  Serial.print(temperature);
  Serial.print("\n");
  Serial.print("CURRENT RECORD: ");
  Serial.print(record);
  Serial.print("\n");
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  if (record - temperature > 0 && record - temperature <= 1)
  {
    digitalWrite(3, HIGH);                                                                                                                                                                                                                                                                                                                                                                                          
    digitalWrite(4, LOW);
  }
  else if (temperature > record)
  {
    record = temperature;
    digitalWrite(3,LOW);
    digitalWrite(4, HIGH);
  }
  delay(500);
}
