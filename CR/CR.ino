int dirm = 2;
int pulm = 3;
int dirmd = 5;
int pulmd = 6;

void setup() {
  pinMode(pulm, OUTPUT);
  pinMode(dirm, OUTPUT);
  pinMode(pulmd, OUTPUT);
  pinMode(dirmd, OUTPUT);
  Serial.begin(9600);
}

void loop() {
    
   if(Serial.available()){
    char c = Serial.read();
    
    //-------------PEDAL DE ABAJO---------------
    //-- pedal de abajo activado
    if(c == 'A'){
      
      digitalWrite(dirmd, HIGH);
      delayMicroseconds(10);
       
      for(int j=0; j<35; j++){
      digitalWrite(pulmd, HIGH);
      delayMicroseconds(6500);
      digitalWrite(pulmd, LOW);
        }
    } 
    
    //-- pedal de abajo desactivado
    else if( c== 'B' ){
      digitalWrite(dirmd, LOW);
      delayMicroseconds(10);
      
      for(int i=0; i<35; i++){
        digitalWrite(pulmd, HIGH);
        delayMicroseconds(6500);
        digitalWrite(pulmd, LOW);
    }
    }

    //-----------PEDAL DE ARRIBA-----------------
    //-- pedal de arriba desactivado
    else if(c=='C'){
      digitalWrite(dirm, LOW);
      delayMicroseconds(10);
    
      for(int j=0; j<35; j++){
        digitalWrite(pulm, HIGH);
        delayMicroseconds(6500);
        digitalWrite(pulm, LOW);
      }
    }
    
    //-- pedal de arriba activado
    else if(c=='D'){
        digitalWrite(dirm, HIGH);
        delayMicroseconds(10);
      
        for(int i=0; i<35; i++){
          digitalWrite(pulm, HIGH);
          delayMicroseconds(6500);
          digitalWrite(pulm, LOW);
        }
    }
   }
}
