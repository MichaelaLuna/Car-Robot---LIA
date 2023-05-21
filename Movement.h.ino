
/*----------------------------------------------------------------------- Header file for Movement ---------------------------------------------------------------------------*/

#ifndef MOVEMENT_H      // If not defined
#define MOVEMENT_H      // Define the library

class Movement {
  
private:                // Encapsulation

  int motorA;           // Pin for motor A
  int motorB;           // Pin for motor B
  int motorSpeedA;      // Pin for motor A speed control
  int motorSpeedB;      // Pin for motor B speed control
  int enablePin;        // Pin for motor enable

public:

  Movement();                                                                 // Default Constructor
  Movement(int pinA, int pinB, int pinSpeedA, int pinSpeedB, int pinEnable);  // Constructor with pin assignments

  void Forward();     // Method to move forward
  void Backward();    // Method to move backward
  void Left();        // Method to turn left
  void Right();       // Method to turn right
  void Stop();        // Method to stop 
  void ActionMove();  // Method for ActionMove
  
};                    // End 

#endif               // End of if not defined
