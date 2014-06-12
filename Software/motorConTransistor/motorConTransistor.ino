int pin = 3;

char instruction;
int action = 0;

void setup(){
  Serial.begin( 9600);
  pinMode( pin, OUTPUT);
}

void loop(){
  if ( Serial.available() > 0){
    instruction = Serial.read();
    
    if ( instruction == '1'){
      digitalWrite( pin, HIGH);
    }
    else if ( instruction == '0'){
      digitalWrite( pin, LOW);
    }
  }
}
