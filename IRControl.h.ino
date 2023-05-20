

/*----------------------------------------------------------------------- Header file for IRControl ---------------------------------------------------------------------------*/

#ifndef IRCONTROL_H      // If not defined
#define IRCONTROL_H      // Define the library

#include <IRremote.h>    // Include the library for the IRremote
#include <Arduino.h>     // Include the library for the Arduino

class IrControl {
  
  private:                   // Encapsulation
  
    int receiver;            // Pin for IR receiver
    int motorA;              // Pin for motor A
    int motorB;              // Pin for motor B
    int motorSpeedA;         // Pin for motor A speed control
    int motorSpeedB;         // Pin for motor B speed control
    int enablePin;           // Pin for motor enable
    IRrecv irrecv;           // IR receiver object
    decode_results results;  // IR decoding results

  public:                   

    IrControl();                                                                                 // Default Constructor     
    IrControl(int receiverPin, int pinA, int pinB, int pinSpeedA, int pinSpeedB, int pinEnable); // Constructor with pin assignments

    void init();      // Initialize IR control
    void ActionIR();  // Perform action based on received IR signal

    void Forward();   // Method for moving forward
    void Backward();  // Method for going backward
    void Left();      // Method for turning left
    void Right();     // Method for turning right
    void Stop();      // Method for stopping 
    
};  // End

#endif // End of if not defined
