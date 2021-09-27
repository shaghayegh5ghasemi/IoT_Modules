int led2 = 16;
int led1 = 5;
int led0 = 4;

void setup() {
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  reset();
  for(int i = 0; i < 8; ++i){
    if(((i >> 2) % 2) == 1){
      digitalWrite(led2,HIGH);
    }
    else{
      digitalWrite(led2,LOW);
    }
    if(((i >> 1) % 2) == 1){
      digitalWrite(led1,HIGH);
    }
    else{
      digitalWrite(led1,LOW);
    }
    if(((i >> 0) % 2) == 1){
      digitalWrite(led0,HIGH);
    }
    else{
      digitalWrite(led0,LOW);
    }
    delay(2000);
  }
}


void reset(){
  digitalWrite(led2,LOW);
  digitalWrite(led1,LOW);
  digitalWrite(led0,LOW);
}
