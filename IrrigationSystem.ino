int soil = A0;
int relay = 3;

void setup() {
  pinMode(soil, INPUT);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);
  Serial.begin(9600);
}

void loop() {
  int soilValue = analogRead(soil);
  Serial.print("Sensor Data:");
  Serial.println(soilValue);
  delay(1000);

  //When soil is wet, pump is OFF
  //When soil is dry, pump is ON, starts pumping water
  if(soilValue > 250)
    digitalWrite(relay, LOW);
  else 
    digitalWrite(relay, HIGH);
}
