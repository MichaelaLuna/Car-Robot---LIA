/*                  The Car Robot from ELEGOO kit has its own remote on the kit already programmed by the
                    creators of it. By this program I created, I was able to use the Infrared remote to control
                    the Car Robot using specifically the buttons that I want and made these respond the way I 
                    programmed it to. 



                                             /*------------- This is the Class -----------------*/ 


#include <IRremote.h>       // Include the library for the IRremote

class IrControl {
  private:
    int receiver;           // Pin for IR receiver
    int MotorA;             // Pin for motor A
    int MotorB;             // Pin for motor B
    int Motor_SpeedA;       // Pin for motor A speed control
    int Motor_SpeedB;       // Pin for motor B speed control
    int EnablePin;          // Pin to enable motors
    IRrecv irrecv;          // IR receiver object
    decode_results results; // Variable to store IR decoding results

  public:
    IrControl(){}                                                                                                   // Default Constructor
    IrControl(int receiverPin, int motorAPin, int motorBPin, int motorSpeedAPin, int motorSpeedBPin, int enablePin) // Constructor with pin assignments
      : receiver(receiverPin), MotorA(motorAPin), MotorB(motorBPin), Motor_SpeedA(motorSpeedAPin),
        Motor_SpeedB(motorSpeedBPin), EnablePin(enablePin), irrecv(receiver), results() {}

    void init() {
      irrecv.enableIRIn();           // Enable IR receiver

      for (int i = 1; i < 9; i++) {  // Set pins 1 to 8 as OUTPUT
        pinMode(i, OUTPUT); 
      }
      pinMode(EnablePin, OUTPUT);    // Set EnablePin as OUTPUT
    }

    void run() {
      digitalWrite(EnablePin, HIGH); // Enable the motors
      
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

  void Forward() {
  digitalWrite(motorA, HIGH);     // Set motorA pin to HIGH
  digitalWrite(motorB, HIGH);     // Set motorB pin to HIGH
  analogWrite(motorSpeedA, 100);  // Set motorSpeedA to 100
  analogWrite(motorSpeedB, 100);  // Set motorSpeedB to 100
}

void Backward() {
  digitalWrite(motorA, LOW);      // Set motorA pin to LOW
  digitalWrite(motorB, LOW);      // Set motorB pin to LOW
  analogWrite(motorSpeedA, 100);  // Set motorSpeedA to 100
  analogWrite(motorSpeedB, 100);  // Set motorSpeedB to 100
}

void Left() {
  digitalWrite(motorA, HIGH);     // Set motorA pin to HIGH
  digitalWrite(motorB, LOW);      // Set motorB pin to LOW
  analogWrite(motorSpeedA, 100);  // Set motorSpeedA to 100
  analogWrite(motorSpeedB, 100);  // Set motorSpeedB to 100
}

void Right() {
  digitalWrite(motorA, LOW);      // Set motorA pin to LOW
  digitalWrite(motorB, HIGH);     // Set motorB pin to HIGH
  analogWrite(motorSpeedA, 100);  // Set motorSpeedA to 100
  analogWrite(motorSpeedB, 100);  // Set motorSpeedB to 100
}

void Stop() {
  digitalWrite(motorA, LOW);     // Set motorA pin to LOW
  digitalWrite(motorB, LOW);     // Set motorB pin to LOW
  analogWrite(motorSpeedA, 0);   // Set motorSpeedA to 0 
  analogWrite(motorSpeedB, 0);   // Set motorSpeedB to 0 
}

};                   // End of class


IrControl myIrControl(9, 7, 8, 5, 6, 3); // Initialize the object with the corresponding pin numbers

void setup() {         // Run the code once
  myIrControl.init();  // Initialization Method
}

void loop() {          // Run the code in loop
  myIrControl.run();   // Run 
}
