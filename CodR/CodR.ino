int dirm = 2;
int pulm = 3;
int dirmd = 5;
int pulmd = 6;

void setup() {
  pinMode(pulm, OUTPUT);
  pinMode(dirm, OUTPUT);
  pinMode(pulmd, OUTPUT);
  pinMode(dirmd, OUTPUT);
}

void loop() {
  //--------------ARRIBA-------------------
 
  digitalWrite(dirm, LOW);
  delayMicroseconds(10);

  for(int j=0; j<200; j++){
    digitalWrite(pulm, HIGH);
    delayMicroseconds(1500);
    digitalWrite(pulm, LOW);
  }
  
  delay(1000);
  
  digitalWrite(dirm, HIGH);
  delayMicroseconds(10);

  for(int i=0; i<200; i++){
    digitalWrite(pulm, HIGH);
    delayMicroseconds(1500);
    digitalWrite(pulm, LOW);
  }
  delay(1000);
 
  //---------------ABAJO-------------------

  digitalWrite(dirmd, LOW);
  delayMicroseconds(10);

  for(int j=0; j<50; j++){
    digitalWrite(pulmd, HIGH);
    delayMicroseconds(1500);
    digitalWrite(pulmd, LOW);
  }
  
  delay(1000);
  
  digitalWrite(dirmd, HIGH);
  delayMicroseconds(10);

  for(int i=0; i<200; i++){
    digitalWrite(pulmd, HIGH);
    delayMicroseconds(1500);
    digitalWrite(pulmd, LOW);
  }
  delay(1000);
 
}
