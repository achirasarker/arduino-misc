#include <Keypad.h>
#include <Servo.h>

//According to the library, these variables should be defined as byte
const byte numRows = 4; 
const byte numCols = 3;
//Signal pin of servo connected to pin 9 of arduino
int servoPin = 9;
//Potentiometer connected to pin A0 of arduino
int pot = A0;

//Map out the keypad buttons in a 2D array
char keymap[numRows][numCols] = { 
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

//Store pins of arduino that keypad rows & cols are connected to within an array
//E.g.Keypad row 1 connected to pin 2 on arduino
byte rowPins[numRows] = {2,3,4,5};
byte colPins[numCols] = {6,7,8};

//Object myKeypad of class Keypad and pass all params of keypad in it
Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);
//Object myServo of class Servo
Servo myServo;

void setup() {
  //Initiate serial communication with buad rate of 9600
  Serial.begin(9600); 
  //Using attach func, define servoPin
  myServo.attach(servoPin);
  //Set pot pin as input for serial data
  pinMode(pot, INPUT);
}

void loop() {
  char keypressed = myKeypad.getKey();
  if(keypressed!=NO_KEY)
  {
    //Print key that's pressed on serial monitor
   Serial.println(keypressed); 
  }

  int potValue = analogRead(pot); //Store readings
  int mapped = map(potValue, 0, 1023, 0, 180); //Pin name, initial value of pin, max value, min of range, max of range ->max angle)
  Serial.println(mapped); 
  //Change angle of servo using write command, add delays in between 
  myServo.write(mapped);
}
