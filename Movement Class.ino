
/* This program is used to make the Car Robot to move with five directions: Forward, Backward, Left, Right & Stop. 
   This has been possible by learning how to set the two as a function and by learning how to call them.
 
 
--------------------------------------------------------- This is the Class ----------------------------------------------------- */


#define motorA 7          // Define motorA to this pin#
#define motorB 8          // Define motorB to this pin#
#define motorSpeedA 5     // Define motorSpeedA to this pin#
#define motorSpeedB 6     // Define motorSpeedB to this pin#
#define enablePin 3       // Define enablePin to this pin#

class Movement {

private:                // Encapsulation

  int motorA;           // Pin for motor A
  int motorB;           // Pin for motor B
  int motorSpeedA;      // Pin for motor A speed control
  int motorSpeedB;      // Pin for motor B speed control
  int enablePin;        // Pin for motor enable

public:

  Movement(){}                                                                                           // Default constructor
  Movement(int pinA, int pinB, int pinSpeedA, int pinSpeedB, int pinEnable)                              // Constructor definition for the Movement class
    : motorA(pinA), motorB(pinB), motorSpeedA(pinSpeedA), motorSpeedB(pinSpeedB), enablePin(pinEnable) { 
  
  for (int i = 1; i < 9; i++) {  // Set pins 1 to 8 as output
    pinMode(i, OUTPUT);         
  }
  pinMode(enablePin, OUTPUT);    // Set enable pin as output
}


void Forward() {
  digitalWrite(motorA, HIGH);      // Set motor A direction forward
  digitalWrite(motorB, HIGH);      // Set motor B direction forward
  analogWrite(motorSpeedA, 70);    // Set motor A speed to 70
  analogWrite(motorSpeedB, 70);    // Set motor B speed to 70
  digitalWrite(enablePin, HIGH);   // Enable the motors
}
  
  void Backward() {
  digitalWrite(motorA, 0);        // Set motorA pin LOW
  digitalWrite(motorB, 0);        // Set motorB pin LOW
  analogWrite(motorSpeedA, 70);   // Set motorSpeedA to 70
  analogWrite(motorSpeedB, 70);   // Set motorSpeedB to 70
  digitalWrite(enablePin, HIGH);  // Set enablePin HIGH to enable the motors
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

  void ActionMove(){
     Forward();                    // Move forward
     delay(3000);                  // Delay for 3 seconds
     Stop();                       // Stop
     delay(3000);                  // Delay for 3 seconds
     Backward();                   // Move backward
     delay(3000);                  // Delay for 3 seconds
     Stop();                       // Stop
     delay(3000);                  // Delay for 3 seconds      
} 
      
};                                 // End of Class

#define motorA 7          // Define motorA to this pin#
#define motorB 8          // Define motorB to this pin#
#define motorSpeedA 5     // Define motorSpeedA to this pin#
#define motorSpeedB 6     // Define motorSpeedB to this pin#
#define enablePin 3       // Define enablePin to this pin#

Movement move(motorA, motorB, motorSpeedA, motorSpeedB, enablePin); // Initialize the object with the corresponding pin numbers

void setup() {            // Run the code once
}                         // End of setup

void loop() {             // Run the code in loop
  move.ActionMove();      // Run the action
}                         // End of loop
