int buzzer = 5;

void setup() {
  pinMode(buzzer, OUTPUT);
  Serial.begin(9000);
}

void loop() {
  int sensorvalue=analogRead(A0);
  int value = map(sensorvalue, 0,1023, 500,0);
  Serial.println(value);
  analogWrite(buzzer,value);
}
