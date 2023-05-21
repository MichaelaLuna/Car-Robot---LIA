
/*----------------------------------------------------------------------- .cpp file for LineFollower ---------------------------------------------------------------------------*/

#include "LineFollower.h" // Include the "LineFollower.h" header file


LineFollower::LineFollower(int readPin1, int readPin2, int readPin3, int pinA, int pinB, int pinSpeedA, int pinSpeedB, int pinEnable)  // Constructor definition for the LineFollower class
    : readPin1(readPin1), readPin2(readPin2), readPin3(readPin3), motorA(pinA), motorB(pinB),
      motorSpeedA(pinSpeedA), motorSpeedB(pinSpeedB), enablePin(pinEnable) {}

void LineFollower::Forward() {
  digitalWrite(motorA, HIGH);      // Set motor A direction forward
  digitalWrite(motorB, HIGH);      // Set motor B direction forward
  analogWrite(motorSpeedA, 70);    // Set motor A speed to 70
  analogWrite(motorSpeedB, 70);    // Set motor B speed to 70
  digitalWrite(enablePin, HIGH);   // Enable the motors
}

void LineFollower::Stop() {
  digitalWrite(motorA, HIGH);      // Set motor A direction forward
  digitalWrite(motorB, HIGH);      // Set motor B direction forward
  analogWrite(motorSpeedA, 0);     // Set motor A speed to 0 
  analogWrite(motorSpeedB, 0);     // Set motor B speed to 0 
  digitalWrite(enablePin, HIGH);   // Enable the motors
}

void LineFollower::Left() {
  digitalWrite(motorA, HIGH);      // Set motor A direction forward
  digitalWrite(motorB, LOW);       // Set motor B direction backward
  analogWrite(motorSpeedA, 70);    // Set motor A speed to 70
  analogWrite(motorSpeedB, 70);    // Set motor B speed to 70
  digitalWrite(enablePin, HIGH);   // Enable the motors
}

void LineFollower::Right() {
  digitalWrite(motorA, LOW);       // Set motor A direction backward
  digitalWrite(motorB, HIGH);      // Set motor B direction forward
  analogWrite(motorSpeedA, 70);    // Set motor A speed to 70
  analogWrite(motorSpeedB, 70);    // Set motor B speed to 70
  digitalWrite(enablePin, HIGH);   // Enable the motors
}

void LineFollower::init() {
  Serial.begin(9600);              // Initialize serial communication

  pinMode(motorA, OUTPUT);         // Set motor A pin as output
  pinMode(motorB, OUTPUT);         // Set motor B pin as output
  pinMode(motorSpeedA, OUTPUT);    // Set motor A speed control pin as output
  pinMode(motorSpeedB, OUTPUT);    // Set motor B speed control pin as output
  pinMode(enablePin, OUTPUT);      // Set motor enable pin as output
}

void LineFollower::ActionLineF() {
  int analogR = analogRead(readPin1);    // Read value from right sensor
  float rightS = analogR;
  Serial.print("R=");                    
  Serial.println(rightS);                // Print the read value

  int analogM = analogRead(readPin2);    // Read value from middle sensor
  float middleS = analogM;
  Serial.print("M=");
  Serial.println(middleS);               // Print the read value

  int analogL = analogRead(readPin3);    // Read value from left sensor
  float leftS = analogL;
  Serial.print("L=");
  Serial.println(leftS);                // Print the read value

  if (middleS >= 400) {
    Forward();                          // If middle sensor detects the line, move forward
  } else if (rightS >= 400) {
    Right();                            // If right sensor detects the line, turn right
  } else if (leftS >= 400) {
    Left();                             // If left sensor detects the line, turn left
  }

  if (middleS > 1000 && rightS > 1000 && leftS > 1000) {  // If all sensors detect a white surface, stop
    Stop();                             
  }                                    // End of if
}                                      // End of "ActionLineF"
