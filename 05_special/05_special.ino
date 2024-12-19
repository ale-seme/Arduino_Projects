#include <Servo.h>

Servo myServo;

const int potPin = A0;
const int servoPin = 9;
const int buttonPin = 11;
const int greenPin = 12; 
const int redPin = 13;

//VARIABLES

bool servoEnabled = false;
int buttonState = 0;
int lastButtonState = 0;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

int potVal = 0;
int angle = 0;           


void setup() {
  myServo.attach(servoPin);
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, LOW);
}
  

void loop() {

  // Read the button state
  int reading = digitalRead(buttonPin);

  // Check for state change (debounce logic)
  if (reading != lastButtonState) 
  {
    lastDebounceTime = millis(); // Reset debounce timer
  }

  if ((millis() - lastDebounceTime) > debounceDelay)
  {
    // If the button state has changed, toggle the servo state
    if (reading != buttonState) 
    {
      buttonState = reading;

      // Only toggle when button is pressed (LOW to HIGH transition)
      if (buttonState == HIGH) 
      {
        servoEnabled = !servoEnabled; // Toggle the servo state
      }
    }
  }

  // Save the reading for the next iteration
  lastButtonState = reading;

  // Update LED and Servo based on the state
  if (servoEnabled) 
  {
    digitalWrite(redPin, LOW);    // Turn off red LED
    digitalWrite(greenPin, HIGH); // Turn on green LED

    // Read potentiometer and move servo
    potVal = analogRead(potPin);
    Serial.print(potVal);
    Serial.print("\n");
    angle = map(potVal, 0, 1023, 0, 179);
    myServo.write(angle);
    delay(15);                   // Small delay for servo
  }
  else 
  {
    digitalWrite(redPin, HIGH);  // Turn on red LED
    digitalWrite(greenPin, LOW); // Turn off green LED
    myServo.write(0);            // Optionally set the servo to a default position
  }
}
