
/* -------------------------------------------------------- This is the program in the first Arduino --------------------------------------------*/
  
int LatchPin = 11;          // defines pin for the latch
int ShiftPin = 10;          // defines pin for shift 
int DataInput = 12;         // defines pin for data input 
int digPins[4] = {9,8,7,6}; // has four dedicated common pins to control each digit separately 


const byte digits[10] = {   // defines an array of bytes that represent the pattern to light up each segment of a digit.
  B11111011,  // 0 aed.cgbf
  B00011010,  // 1
  B11110110,  // 2
  B10111110,  // 3
  B00011111,  // 4
  B10111101,  // 5
  B11111101,  // 6
  B10011010,  // 7
  B11111111,  // 8
  B10111111,  // 9
  
}; // End



void setup() { // Run the code once
  
  pinMode (LatchPin ,OUTPUT); // Sets as an output
  pinMode (ShiftPin, OUTPUT); // Sets as an output
  pinMode (DataInput, OUTPUT); // Sets as an output
  pinMode (9, OUTPUT); // Sets as an output
  pinMode (8, OUTPUT); // Sets as an output
  pinMode (7, OUTPUT); // Sets as an output
  pinMode (6, OUTPUT); // Sets as an output

  pinMode(5,OUTPUT);  // Pin 5 is an output
  pinMode(4,OUTPUT);  // Pin 4 is an output
  pinMode(3,OUTPUT);  // Pin 3 is an output
  pinMode(2,OUTPUT);  // Pin 2 is an output
}

void loop () { // Run the code in loop

  digitalWrite(5,HIGH); // LED turns on 
  
  digitalWrite(4,HIGH); // LED turns on 

  digitalWrite(3,HIGH); // LED turns on 

  digitalWrite(2,HIGH); // LED turns on 

  /* ----- The code for 4 Digit 7 Segment ----- */

  digitalWrite (9, LOW);  // Set this off
  digitalWrite (8, HIGH); // Set this on
  digitalWrite (7, HIGH); // Set this on
  digitalWrite (6, HIGH); // Set this on
  digitalWrite (LatchPin, LOW); // Data will pass
  shiftOut(DataInput, ShiftPin, LSBFIRST,digits[2] );
  digitalWrite (LatchPin, HIGH); // Data will not pass
  delay(5); // Delay for 5ms
 
 
  digitalWrite (9, HIGH); // Set this on
  digitalWrite (8, LOW);  // Set this off
  digitalWrite (7, HIGH); // Set this on
  digitalWrite (6, HIGH); // Set this on
  digitalWrite (LatchPin, LOW); // Data will pass
  shiftOut(DataInput, ShiftPin, LSBFIRST, digits[0] );
  digitalWrite (LatchPin, HIGH); // Data will not pass
  delay(5); // Delay for 5ms
  
 
  digitalWrite (9, HIGH); // Set this on
  digitalWrite (8, HIGH); // Set this on
  digitalWrite (7, LOW);  // Set this off
  digitalWrite (6, HIGH); // Set this on
  digitalWrite (LatchPin, LOW); // Data will pass
  shiftOut(DataInput, ShiftPin, LSBFIRST,digits[0]);
  digitalWrite (LatchPin, HIGH); // Data will not pass
  delay(5); // Delay for 5ms

  digitalWrite (9, HIGH); // Set this on
  digitalWrite (8, HIGH); // Set this on
  digitalWrite (7, HIGH); // Set this on
  digitalWrite (6, LOW);  // Set this off
  digitalWrite (LatchPin, LOW); // Data will pass
  shiftOut(DataInput, ShiftPin, LSBFIRST, digits[2]);
  digitalWrite (LatchPin, HIGH);// Data will not pass
  delay(5); // Delay for 5ms



} // End of loop
