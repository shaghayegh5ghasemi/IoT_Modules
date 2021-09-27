int led = 2;
int buzzer = 5;

void setup() {
  pinMode(led, OUTPUT)
  pinMode(buzzer, OUTPUT);
  digitalWrite(led,LOW);
  Serial.begin(9000);
}

void loop() {
  int sensorvalue=analogRead(A0);
  int value = map(sensorvalue, 0,1023, 0,100);
  Serial.println(value);
  if(value>50){
    digitalWrite(led,LOW);
    digitalWrite(buzzer,HIGH);
  }
  else{
    digitalWrite(led,HIGH);
    digitalWrite(buzzer,LOW);
  }
}
