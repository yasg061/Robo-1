const int PIN_DIR = 5;
const int PIN_PUL = 6;
const int PIN_DIR2 = 9;
const int PIN_PUL2 = 10;
const int PIN_RELAY = 2;
const int PIN_RELAY2 = 3;
const int PIN_5V = A0;

char value;

void setup() {
  pinMode(PIN_DIR, OUTPUT);
  pinMode(PIN_PUL, OUTPUT);
  pinMode(PIN_DIR2, OUTPUT);
  pinMode(PIN_PUL2, OUTPUT);
  pinMode(PIN_RELAY, OUTPUT);
  pinMode(PIN_RELAY2, OUTPUT);
  pinMode(PIN_5V, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  digitalWrite(PIN_5V, HIGH);
  digitalWrite(PIN_RELAY, LOW);
  digitalWrite(PIN_RELAY2, LOW); 

  
  
    
  if(Serial.available()>0){
    digitalWrite(PIN_RELAY, HIGH);
    digitalWrite(PIN_RELAY2, HIGH);
    
    value = Serial.read();
    
    if(value == 'A'){
      
      digitalWrite(PIN_DIR, HIGH);
      digitalWrite(PIN_PUL, HIGH);
      delayMicroseconds(6500);
      digitalWrite(PIN_PUL, LOW);
      
    } else if(value == 'B'){
      
      digitalWrite(PIN_DIR, LOW);
      digitalWrite(PIN_PUL, HIGH);
      delayMicroseconds(6500);
      digitalWrite(PIN_PUL, LOW);
      
    } else if(value == 'C'){
      
      digitalWrite(PIN_DIR2, HIGH);
      digitalWrite(PIN_PUL2, HIGH);
      delayMicroseconds(6500);
      digitalWrite(PIN_PUL2, LOW);
      
    } else if(value == 'D'){
      
      digitalWrite(PIN_DIR2, LOW);
      digitalWrite(PIN_PUL2, HIGH);
      delayMicroseconds(6500);
      digitalWrite(PIN_PUL2, LOW);
      
    } else{
      
    }
  }
     digitalWrite(PIN_RELAY, LOW);
     digitalWrite(PIN_RELAY2, LOW); 
  
}
