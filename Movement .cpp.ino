
/*--------------------------------------------------------------- .cpp file for Movement -----------------------------------------------------------------*/

#include "Movement.h"   // Include the "Movement.h" header file
#include <Arduino.h>    // Include the "Arduino.h" header file

// Constructor definition for the Movement class

Movement::Movement(int pinA, int pinB, int pinSpeedA, int pinSpeedB, int pinEnable)                        
    : motorA(pinA), motorB(pinB), motorSpeedA(pinSpeedA), motorSpeedB(pinSpeedB), enablePin(pinEnable) { 
  
  for (int i = 1; i < 9; i++) {  // Set pins 1 to 8 as output
    pinMode(i, OUTPUT);         
  }
  pinMode(enablePin, OUTPUT);    // Set enable pin as output
}

void Movement::Forward() {
  digitalWrite(motorA, HIGH);      // Set motor A direction forward
  digitalWrite(motorB, HIGH);      // Set motor B direction forward
  analogWrite(motorSpeedA, 70);    // Set motor A speed to 70
  analogWrite(motorSpeedB, 70);    // Set motor B speed to 70
  digitalWrite(enablePin, HIGH);   // Enable the motors
}

void Movement::Stop() {
  digitalWrite(motorA, HIGH);      // Set motor A direction forward
  digitalWrite(motorB, HIGH);      // Set motor B direction forward
  analogWrite(motorSpeedA, 0);     // Set motor A speed to 0 
  analogWrite(motorSpeedB, 0);     // Set motor B speed to 0 
  digitalWrite(enablePin, HIGH);   // Enable the motors
}

void Movement::Left() {
  digitalWrite(motorA, HIGH);      // Set motor A direction forward
  digitalWrite(motorB, LOW);       // Set motor B direction backward
  analogWrite(motorSpeedA, 70);    // Set motor A speed to 70
  analogWrite(motorSpeedB, 70);    // Set motor B speed to 70
  digitalWrite(enablePin, HIGH);   // Enable the motors
}

void Movement::Right() {
  digitalWrite(motorA, LOW);       // Set motor A direction backward
  digitalWrite(motorB, HIGH);      // Set motor B direction forward
  analogWrite(motorSpeedA, 70);    // Set motor A speed to 70
  analogWrite(motorSpeedB, 70);    // Set motor B speed to 70
  digitalWrite(enablePin, HIGH);   // Enable the motors
}
void Movement::ActionMove(){
     Forward();                          // Move forward
     delay(3000);                        // Delay for 3 seconds
     Stop();                             // Stop
     delay(3000);                        // Delay for 3 seconds
     Backward();                         // Move backward
     delay(3000);                        // Delay for 3 seconds
     Stop();                             // Stop
     delay(3000);                        // Delay for 3 seconds   
}
