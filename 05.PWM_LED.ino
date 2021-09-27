int led = 2;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9000);
}

void loop() {
  int value=analogRead(A0);
  Serial.println(value);
  analogWrite(led,value);
}
