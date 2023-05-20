/*----------------------------------------------------------------------- .cpp file for IRControl ---------------------------------------------------------------------------*/


#include "IrControl.h"  // Include the "IrControl.h" header file

IrControl::IrControl(int receiverPin, int pinA, int pinB, int pinSpeedA, int pinSpeedB, int pinEnable)    // Constructor definition for the IrControl class
  : receiver(receiverPin), motorA(pinA), motorB(pinB), motorSpeedA(pinSpeedA),
    motorSpeedB(pinSpeedB), enablePin(pinEnable), irrecv(receiver), results() {}
    

void IrControl::init() {          // Method for initialization
  irrecv.enableIRIn();            // Enable the infrared receiver
  
  for (int i = 1; i < 9; i++) {   // Set pins 1 to 8 as OUTPUT
    pinMode(i, OUTPUT);       
  }
  
  pinMode(enablePin, OUTPUT);     // Set the enablePin as OUTPUT
}

void IrControl::ActionIR() {      // Method for the action
  
  digitalWrite(enablePin, HIGH);  // Set the enablePin to HIGH
  
  if (irrecv.decode(&results)) {  // Check if a signal is received
    switch (results.value) {
      case 0xFF629D:              // First case; If this button is pressed
        Forward();                // Call the Forward() function
        break;
      case 0xFFA857:              // Second case; If this button is pressed
        Backward();               // Call the Backward() function
        break;
      case 0xFFC23D:              // Third case; If this button is pressed
        Right();                  // Call the Right() function
        delay(1000);              // Delay for 1 second
        Forward();                // Call the Forward() function
        break;
      case 0xFF22DD:             // Fourth case; If this button is pressed
        Left();                  // Call the Left() function
        delay(1000);             // Delay for 1 second
        Forward();               // Call the Forward() function
        break;
      case 0xFFA25D:             // Fifth case; If this button is pressed
        Stop();                  // Call the Stop() function
        break;
    }
    
    irrecv.resume();             // Prepare for the next signal
  }
}

void IrControl::Forward() {
  digitalWrite(motorA, HIGH);     // Set motorA pin to HIGH
  digitalWrite(motorB, HIGH);     // Set motorB pin to HIGH
  analogWrite(motorSpeedA, 100);  // Set motorSpeedA to 100
  analogWrite(motorSpeedB, 100);  // Set motorSpeedB to 100
}

void IrControl::Backward() {
  digitalWrite(motorA, LOW);      // Set motorA pin to LOW
  digitalWrite(motorB, LOW);      // Set motorB pin to LOW
  analogWrite(motorSpeedA, 100);  // Set motorSpeedA to 100
  analogWrite(motorSpeedB, 100);  // Set motorSpeedB to 100
}

void IrControl::Left() {
  digitalWrite(motorA, HIGH);     // Set motorA pin to HIGH
  digitalWrite(motorB, LOW);      // Set motorB pin to LOW
  analogWrite(motorSpeedA, 100);  // Set motorSpeedA to 100
  analogWrite(motorSpeedB, 100);  // Set motorSpeedB to 100
}

void IrControl::Right() {
  digitalWrite(motorA, LOW);      // Set motorA pin to LOW
  digitalWrite(motorB, HIGH);     // Set motorB pin to HIGH
  analogWrite(motorSpeedA, 100);  // Set motorSpeedA to 100
  analogWrite(motorSpeedB, 100);  // Set motorSpeedB to 100
}

void IrControl::Stop() {
  digitalWrite(motorA, LOW);     // Set motorA pin to LOW
  digitalWrite(motorB, LOW);     // Set motorB pin to LOW
  analogWrite(motorSpeedA, 0);   // Set motorSpeedA to 0 
  analogWrite(motorSpeedB, 0);   // Set motorSpeedB to 0 
}
