#include <Servo.h>

Servo standServo;

const int buttonPin = 2;  // Deploy stand button
const int speedPin = A0;  // Potentiometer simulating bike speed
int buttonState = 0;
int speedValue = 0;

void setup() {
  standServo.attach(9);
  pinMode(buttonPin, INPUT_PULLUP); // Use internal pull-up resistor
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  speedValue = analogRead(speedPin); // 0 to 1023

  // Convert speedValue to simulated km/h (just for testing)
  float speedKmh = map(speedValue, 0, 1023, 0, 100);

  Serial.print("Speed: ");
  Serial.print(speedKmh);
  Serial.println(" km/h");

  if (buttonState == LOW && speedKmh < 5) {
    // Deploy stand
    standServo.write(90); // Move servo to deployed position
    Serial.println("Stand Deployed ✅");
  } else {
    // Retract stand
    standServo.write(0); // Move servo to retracted position
    Serial.println("Stand Retracted ❌");
  }

  delay(200);
}
