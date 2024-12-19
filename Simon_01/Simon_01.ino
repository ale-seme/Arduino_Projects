/*

    Green – 415 Hz – G#4 (true pitch 415.305 Hz)
    Red – 310 Hz – D#4 (true pitch 311.127 Hz)
    Yellow – 252 Hz ‐ B3 (true pitch 247.942 Hz)
    Blue – 209 Hz – G#3 (true pitch 207.652 Hz)

*/

///////////////////////////////////////////////////////////////////////////////////////////////////////
// OVERVIEW
///////////////////////////////////////////////////////////////////////////////////////////////////////







///////////////////////////////////////////////////////////////////////////////////////////////////////
// INCLUDES
///////////////////////////////////////////////////////////////////////////////////////////////////////








///////////////////////////////////////////////////////////////////////////////////////////////////////
// DEFINES MACROS AND COSTANTS
///////////////////////////////////////////////////////////////////////////////////////////////////////

const int BLUE_BUTTON_PIN  = 7;
const int GREEN_BUTTON_PIN  = 6;
const int RED_BUTTON_PIN  = 5;
const int YELLOW_BUTTON_PIN  = 4;

//pins for external output to LEDs

const int BLUE_LED_PIN = 13;
const int GREEN_LED_PIN = 12;
const int RED_LED_PIN = 11;
const int YELLOW_LED_PIN = 10;

const int BUZZER_PIN = 3; // use this one for audio, can support PWM
//tones for colors


const int GREEN_TONE  = 415;
const int RED_TONE    = 310;
const int YELLOW_TONE = 252;
const int BLUE_TONE   = 209;



///////////////////////////////////////////////////////////////////////////////////////////////////////
//GLOBALS
///////////////////////////////////////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////////////////////////////////////
//FUNCTIONS
///////////////////////////////////////////////////////////////////////////////////////////////////////

void setup()
{
  pinMode(BLUE_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);

  pinMode(BLUE_BUTTON_PIN, INPUT);
  pinMode(GREEN_BUTTON_PIN, INPUT);
  pinMode(RED_BUTTON_PIN, INPUT);
  pinMode(YELLOW_BUTTON_PIN, INPUT);

  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(115200);

}



void loop()
{
  if (!digitalRead(BLUE_BUTTON_PIN))
  {
    digitalWrite(BLUE_LED_PIN, HIGH);
    tone(BUZZER_PIN, BLUE_TONE, 500);
    Serial.write("\nBLUE button pressed");
  }
  else
  {
    digitalWrite(BLUE_LED_PIN, LOW);
  }


  if (!digitalRead(GREEN_BUTTON_PIN))
  {
    digitalWrite(GREEN_LED_PIN, HIGH);
    tone(BUZZER_PIN, GREEN_TONE, 500);
    Serial.write("\nGREEN button pressed");
  }
  else
  {
    digitalWrite(GREEN_LED_PIN, LOW);
  }


  if (!digitalRead(RED_BUTTON_PIN))
  {
    digitalWrite(RED_LED_PIN, HIGH);
    tone(BUZZER_PIN, RED_TONE, 500);
    Serial.write("\nRED button pressed");
  }
  else
  {
    digitalWrite(RED_LED_PIN, LOW);
  }

  
  if (!digitalRead(YELLOW_BUTTON_PIN))
  {
    digitalWrite(YELLOW_LED_PIN, HIGH);
    tone(BUZZER_PIN, YELLOW_TONE, 500);
    Serial.write("\nYELLOW button pressed");
  }
  else
  {
    digitalWrite(YELLOW_LED_PIN, LOW);
  }
  delay(100);
}
