#include <LiquidCrystal.h>
//Object for my LCD
LiquidCrystal mylcd(2, 3, 4, 5, 6, 7);

int gas = A0;
int water = A1;
int fire = 9;
int buzzer = 8;

void setup() {
  Serial.begin(9600);
  mylcd.begin(16,2);
  pinMode(gas, INPUT);
  pinMode(water, INPUT);
  pinMode(fire, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int gasData = analogRead(gas);
  int waterData = analogRead(water);
  int fireData = digitalRead(fire);
  Serial.print("Gas data:");
  Serial.println(gasData);
  Serial.print("Water data:");
  Serial.println(waterData);
  Serial.print("Fire data:");
  Serial.println(fireData);
  delay(500);

  //All good
  if( (gasData<=700) && (waterData<=300) && (fireData==0) )
  {
    mylcd.clear();
    mylcd.setCursor(0,0);
    mylcd.print("No Hazards Detected");
    mylcd.setCursor(0,1);
    mylcd.print("You are safe, all good!");
    delay(500);
  }
  else 
  {
    tone(buzzer, 500); //Turns on buzzer and sets frequency
    delay(100); //Keep buzzer on for 100ms
    noTone(buzzer); //Turns off buzzer
    mylcd.clear();
    mylcd.setCursor(0,0);
    mylcd.print("WARNING! Hazards Detected!");
    mylcd.setCursor(0,1);

    if( (gasData>700) && (waterData>300) && (fireData==1) ) //All detected
      mylcd.print("GAS WATER FIRE!"); 
    else if ( (gasData>700) && (waterData>300) && (fireData==0) ) //Gas and water detected
      mylcd.print("GAS WATER!");
    else if ( (gasData<=700) && (waterData>300) && (fireData==1) ) //Water and fire detected
      mylcd.print("WATER FIRE!");
    else if ( (gasData>700) && (waterData<=300) && (fireData==1) ) //Gas and fire detected
      mylcd.print("GAS FIRE!");
    else if ( (gasData>700) && (waterData<=300) && (fireData==0) ) //Gas detected
      mylcd.print("GAS!");
    else if ( (gasData<=700) && (waterData>300) && (fireData==0) ) //Water detected
      mylcd.print("WATER!");
    else if ( (gasData<=700) && (waterData<=300) && (fireData==1) ) //Fire detected
      mylcd.print("FIRE!");
  }
  
}
