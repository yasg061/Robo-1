int dirm = 2;
int pulm = 3;
int dirmd = 5;
int pulmd = 6;
int pushButton = 8;
const int ledPin = 13;
volatile int value;
char c;


void setup() {
  pinMode(pulm, OUTPUT);
  pinMode(dirm, OUTPUT);
  pinMode(pulmd, OUTPUT);
  pinMode(dirmd, OUTPUT);
  pinMode(pushButton, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  value = digitalRead(pushButton);

  if(value==HIGH){
    Serial.begin(9600);
    digitalWrite(ledPin, HIGH);
    delay(1000);

    if(Serial.available()){
    c = Serial.read();
    
    //-------------UP PEDAL---------------
    //-- UP PEDAL ACTIVATED
    if(c == 'A'){
    
      digitalWrite(dirm, HIGH);
       
      for(int j=0; j<35; j++){
      digitalWrite(pulm, HIGH);
      delayMicroseconds(6500);
      digitalWrite(pulm, LOW);
        }
      } 
    
    //-- UP PEDAL DISABLED
      else if( c== 'B' ){

      digitalWrite(dirm, LOW);

      
      for(int i=0; i<35; i++){
        digitalWrite(pulm, HIGH);
        delayMicroseconds(6500);
        digitalWrite(pulm, LOW);
       }
      }

    //------------DOWN PEDAL----------------
    //-- DOWN PEDAL DISABLED
      else if(c=='C'){
 
      digitalWrite(dirmd, LOW);
    
      for(int j=0; j<35; j++){
        digitalWrite(pulmd, HIGH);
        delayMicroseconds(6500);
        digitalWrite(pulmd, LOW);
      }
    }
    
    //-- DOWN PEDAL ACTIVATED
    else if(c=='D'){
      
        digitalWrite(dirmd, HIGH);
      
        for(int i=0; i<35; i++){
          digitalWrite(pulmd, HIGH);
          delayMicroseconds(6500);
          digitalWrite(pulmd, LOW);
        }
     }
   } 
    }
    else{
      digitalWrite(ledPin, LOW);
      Serial.end();
      
    }
}
