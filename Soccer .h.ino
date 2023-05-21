
/*----------------------------------------------------------------------- Header file for Soccer ---------------------------------------------------------------------------*/

#ifndef SOCCER_H        // If not defined
#define SOCCER_H        // Define the library

#include <IRremote.h>   // Include the library for the IRremote
#include <Servo.h>      // Include the library for the servo

class Soccer {
private:
  int receiver;            // Pin for IR receiver
  int motorA;              // Pin for motor A
  int motorB;              // Pin for motor B
  int motorSpeedA;         // Pin for motor A speed control
  int motorSpeedB;         // Pin for motor B speed control
  int enablePin;           // Pin to enable motors
  IRrecv* irrecv;          // Update to a pointer for IR receiver
  decode_results results;  // Variable to store IR decoding results
  Servo servo1;            // Servo motor 1
  Servo servo2;            // Servo motor 2

public:
  Soccer(int receiverPin, int motorAPin, int motorBPin, int motorSpeedAPin, int motorSpeedBPin, int enablePin); // Constructor with pin assignments
  ~Soccer();                                                                                                    // Destructor

  void init();         // Initialize the soccer robot
  void ActionSoccer(); // Perform soccer actions based on IR signals
  void Forward();      // Method to move forward
  void Backward();     // Method to move backward
  void Left();         // Method to turn left
  void Right();        // Method to turn right
  void Boost1();       // Method to activate boost mode 1 
  void Boost2();       // Method to activate boost mode 2 
  void Stop();         // Method to stop
  
}; // End

#endif    // End of if not defined
