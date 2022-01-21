//Libary for LCD
#include <LiquidCrystal.h>

//Object for my LCD
LiquidCrystal mylcd(7,6,5,4,3,2);

void setup() {
  mylcd.begin(16,2);
}

void loop() {
  //Can alternatively use mylcd.home(); to set cursor to deafult position
  mylcd.setCursor(0,0);
  mylcd.print("Hello, how was your day?");
  //To make the cursor blink
  mylcd.blink();
  delay(1000);
  //Use scrollDisplayLeft when displaying more than 16 characters in a row
  mylcd.scrollDisplayLeft();
}
