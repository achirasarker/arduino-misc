//Data pin connected to A0 pin of arduino
int sensor = A0;
//Buzzer + terminal connected to pin 2 of arduino
int buzzer = 2;

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(sensor);
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue); 
  delay(500);
  
  if(sensorValue >= 200)
      //Turn buzzer on
      digitalWrite(buzzer, HIGH);
  else 
      digitalWrite(buzzer, LOW);
}
