
/*----------------------------------------------------------------------- .cpp file for Soccer ---------------------------------------------------------------------------*/

#include "Soccer.h"  // Include the "Soccer.h" header file

// Constructor definition for the Soccer class

Soccer::Soccer(int receiverPin, int pinA, int pinB, int pinSpeedA, int pinSpeedB, int pinEnable)
  : receiver(receiverPin), motorA(pinA), motorB(pinB), motorSpeedA(pinSpeedA),motorSpeedB(pinSpeedB), 
    enablePin(pinEnable), irrecv(new IRrecv(receiverPin)), servo1(), servo2() {}

Soccer::~Soccer() {   
  delete irrecv;                 // Release the dynamically allocated IRrecv object in the destructor
}

void Soccer::init() {            // Method for Initialization
  irrecv->enableIRIn(); 
  
  for (int i = 1; i < 9; i++) {  // Set pins 1 to 8 as output
    pinMode(i, OUTPUT);
  }
  
  pinMode(enablePin, OUTPUT);    // Set enable pin as output
  
  servo1.attach(11);             // Servo motor is attached to pin11
  servo2.attach(10);             // Servo motor is attached to pin10
}

void Soccer::ActionSoccer() {
  digitalWrite(enablePin, HIGH);   // Activate the motors 

  if (irrecv->decode(&results)) {  // Check if an IR signal is received and decode it
    
    switch (results.value) {
      case 0xFF629D:              // First case; If this button is pressed
        Forward();                // Move forward
        break;
      case 0xFFA857:              // Second case; If this button is pressed
        Backward();               // Move backward
        break;
      case 0xFFC23D:              // Third case; If this button is pressed
        Right();                  // Turn right
        delay(1000);              // Delay for a second
        Forward();                // Move forward
        break;
      case 0xFF22DD:              // Fourth case; If this button is pressed
        Left();                   // Turn left
        delay(1000);              // Delay for a second
        Forward();                // Move forward
        break;
      case 0xFFA25D:              // Fifth case; If this button is pressed
        Stop();                   // Stop the motors
        break;
      case 0xFFE01F:              // Sixth case; If this button is pressed
        servo1.write(90);         // Control servo1 to a specific position (90 degrees)
        servo2.write(0);          // Control servo2 to a specific position (0 degrees)
        break;
      case 0xFF906F:              // Seventh case; If this button is pressed
        servo1.write(0);          // Control servo1 to a specific position (0 degrees)
        servo2.write(180);        // Control servo2 to a specific position (180 degrees)
        break;
      case 0xFF02FD:              // Eigth case; If this button is pressed
        servo1.write(45);         // Control servo1 to a specific position (45 degrees)
        servo2.write(90);         // Control servo2 to a specific position (90 degrees)
        break;
      case 0xFF42BD:              // Ninth case; If this button is pressed
        Forward();                // Move forward
        delay(500);               // Delay for 500 milliseconds
        Stop();                   // Stop the motors
        break;
      case 0xFF4AB5:              // Tenth case; If this button is pressed
        Backward();               // Move backward
        delay(500);               // Delay for 500 milliseconds
        Stop();                   // Stop the motors
        break;
      case 0xFF9867:              // Eleventh case; If this button is pressed
        Boost1();                 // Activate boost mode 1 
        delay(500);               // Delay for 500 milliseconds
        Stop();                   // Stop the motors
        break;
      case 0xFDC4163:             // Twelfth case; If this button is pressed
        Boost2();                 // Activate boost mode 2
        delay(500);               // Delay for 500 milliseconds
        Stop();                   // Stop the motors
        break;
    }

    irrecv->resume();             // Resume the IR receiver to receive the next signal
  }                               // End of if
}                                 // End of Method


  void Soccer::Forward() {
  digitalWrite(motorA, 1);       // Set motorA pin to HIGH 
  digitalWrite(motorB, 1);       // Set motorB pin to HIGH 
  analogWrite(motorSpeedA, 100); // Set motorSpeedA to 100 
  analogWrite(motorSpeedB, 100); // Set motorSpeedB to 100 
}

void Soccer::Backward() {
  digitalWrite(motorA, 0);       // Set motorA pin to LOW 
  digitalWrite(motorB, 0);       // Set motorB pin to LOW 
  analogWrite(motorSpeedA, 100); // Set motorSpeedA to 100 
  analogWrite(motorSpeedB, 100); // Set motorSpeedB to 100 
}

void Soccer::Left() {
  digitalWrite(motorA, 1);       // Set motorA pin to HIGH 
  digitalWrite(motorB, 0);       // Set motorB pin to LOW 
  analogWrite(motorSpeedA, 100); // Set motorSpeedA to 100 
  analogWrite(motorSpeedB, 100); // Set motorSpeedB to 100 
}

void Soccer::Right() {           // Soccer Feature 1
  digitalWrite(motorA, 0);       // Set motorA pin to LOW 
  digitalWrite(motorB, 1);       // Set motorB pin to HIGH 
  analogWrite(motorSpeedA, 100); // Set motorSpeedA to 100 
  analogWrite(motorSpeedB, 100); // Set motorSpeedB to 100 
}

void Soccer::Boost1() {          // Soccer Feature 1
  digitalWrite(motorA, 1);       // Set motorA pin to HIGH 
  digitalWrite(motorB, 1);       // Set motorB pin to HIGH 
  analogWrite(motorSpeedA, 250); // Set motorSpeedA to 250 
  analogWrite(motorSpeedB, 250); // Set motorSpeedB to 250 
}

void Soccer::Boost2() {          // Soccer Feature 2
  digitalWrite(motorA, 0);       // Set motorA pin to LOW to 
  digitalWrite(motorB, 0);       // Set motorB pin to LOW to 
  analogWrite(motorSpeedA, 250); // Set motorSpeedA to 250 
  analogWrite(motorSpeedB, 250); // Set motorSpeedB to 250 
}

void Soccer::Stop() {
  digitalWrite(motorA, 1);      // Set motorA pin to HIGH to turn on
  digitalWrite(motorB, 1);      // Set motorB pin to HIGH to turn on
  analogWrite(motorSpeedA, 0);  // Set motorSpeedA to 0 (stop)
  analogWrite(motorSpeedB, 0);  // Set motorSpeedB to 0 (stop)
}
