const int PIN_DIR = 5;
const int PIN_PUL = 6;
const int PIN_DIR2 = 9;
const int PIN_PUL2 = 10;
char value;

void setup() {
  pinMode(PIN_DIR, OUTPUT);
  pinMode(PIN_PUL, OUTPUT);
  pinMode(PIN_DIR2, OUTPUT);
  pinMode(PIN_PUL2, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  
  if(Serial.available()){
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
      
    }else {
      
    }
  }
}
