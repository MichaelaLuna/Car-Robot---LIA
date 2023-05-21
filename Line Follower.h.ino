
/*----------------------------------------------------------------------- Header file for LineFollower ---------------------------------------------------------------------------*/

#ifndef LINEFOLLOWER_H   // If not defined
#define LINEFOLLOWER_H   // Define the library

#include <Arduino.h>     // Include the Arduino header file

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
    LineFollower(); // Default Constructor
    LineFollower(int read1, int read2, int read3, int pinA, int pinB, int pinSpeedA, int pinSpeedB, int pinEnable);

    void Forward();      // Method for moving forward
    void Stop();         // Method for Stopping
    void Left();         // Method for turning left
    void Right();        // Method for turning right
    void init();         // Method to initialize line follower
    void ActionLineF();  // Method for ActionLineF
    
};          // End

#endif      // End of if not defined
