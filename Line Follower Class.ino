/* The Car Robot kit has a program of its own programmed to it to do a line follower. It has been possible because of the photoelectric sensor 
   connected below it. Yet, the program that is installed to it is complicated. That is why I created a much simpler program using my fundamentals 
                                    from this class to make my Car Robot follow a line on its own.
 

--------------------------------------------------------------- This is the Class -------------------------------------------------------------*/


#include <Arduino.h>      // Include the Arduino header file

class LineFollower {

  private:                // Encapsulation
  
    int motorA;           // Pin for motor A
    int motorB;           // Pin for motor B
    int motorSpeedA;      // Pin for motor A speed control
    int motorSpeedB;      // Pin for motor B speed control
    int enablePin;        // Pin for motor enable
    int readPin1;         // Pin for reading sensor 1
    int readPin2;         // Pin for reading sensor 2
    int readPin3;         // Pin for reading sensor 3


  public:
    LineFollower();                                                                                                          // Default Constructor
    LineFollower(int readPin1, int readPin2, int readPin3, int pinA, int pinB, int pinSpeedA, int pinSpeedB, int pinEnable)  // Constructor definition for the LineFollower class
    : readPin1(readPin1), readPin2(readPin2), readPin3(readPin3), motorA(pinA), motorB(pinB),
      motorSpeedA(pinSpeedA), motorSpeedB(pinSpeedB), enablePin(pinEnable) {}

void Forward() {
  digitalWrite(motorA, HIGH);      // Set motor A direction forward
  digitalWrite(motorB, HIGH);      // Set motor B direction forward
  analogWrite(motorSpeedA, 70);    // Set motor A speed to 70
  analogWrite(motorSpeedB, 70);    // Set motor B speed to 70
  digitalWrite(enablePin, HIGH);   // Enable the motors
}

void Stop() {
  digitalWrite(motorA, HIGH);      // Set motor A direction forward
  digitalWrite(motorB, HIGH);      // Set motor B direction forward
  analogWrite(motorSpeedA, 0);     // Set motor A speed to 0 
  analogWrite(motorSpeedB, 0);     // Set motor B speed to 0 
  digitalWrite(enablePin, HIGH);   // Enable the motors
}

void Left() {
  digitalWrite(motorA, HIGH);      // Set motor A direction forward
  digitalWrite(motorB, LOW);       // Set motor B direction backward
  analogWrite(motorSpeedA, 70);    // Set motor A speed to 70
  analogWrite(motorSpeedB, 70);    // Set motor B speed to 70
  digitalWrite(enablePin, HIGH);   // Enable the motors
}

void Right() {
  digitalWrite(motorA, LOW);       // Set motor A direction backward
  digitalWrite(motorB, HIGH);      // Set motor B direction forward
  analogWrite(motorSpeedA, 70);    // Set motor A speed to 70
  analogWrite(motorSpeedB, 70);    // Set motor B speed to 70
  digitalWrite(enablePin, HIGH);   // Enable the motors
}

void init() {
  Serial.begin(9600);              // Initialize serial communication

  pinMode(motorA, OUTPUT);         // Set motor A pin as output
  pinMode(motorB, OUTPUT);         // Set motor B pin as output
  pinMode(motorSpeedA, OUTPUT);    // Set motor A speed control pin as output
  pinMode(motorSpeedB, OUTPUT);    // Set motor B speed control pin as output
  pinMode(enablePin, OUTPUT);      // Set motor enable pin as output
}

void ActionLineF() {
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

};                                     // End of Class

#define motorA 7          // Define motorA to this pin#
#define motorB 8          // Define motorB to this pin#
#define motorSpeedA 5     // Define motorSpeedA to this pin#
#define motorSpeedB 6     // Define motorSpeedB to this pin#
#define enablePin 3       // Define enablePin to this pin#
#define readPin1 A0       // Define read1 to this pin#
#define readPin2 A1       // Define read2 to this pin#
#define readPin3 A2       // Define read3 to this pin#

LineFollower line (readPin1, readPin2, readPin3, motorA, motorB, motorSpeedA, motorSpeedB, enablePin); // Initialize the object with the corresponding pin numbers

void setup() {                          // Run the code once
 Line.init                              // Method for Initialization
}

void loop() {                           // Run the code in loop
  Line.ActionLineF();                   // Run action
}
