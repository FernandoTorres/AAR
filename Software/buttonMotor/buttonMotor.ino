/*
 2xPulsador + 1xMotor
 ====================
 
 2 pulsadores controlan la direccion de un motor que gira por
 un tiempo determinado.
 */
 
 
int pinDer = 2;
int pinIzq = 3;

int EN   = 4;
int Auno = 5;
int Ados = 6;

int timeDelay = 2000;

void setup(){
  Serial.begin( 9600);
  pinMode(   EN, OUTPUT);
  pinMode( Auno, OUTPUT);
  pinMode( Ados, OUTPUT);
  
  pinMode( pinDer, INPUT);
  pinMode( pinIzq, INPUT);
}

void loop(){

  if ( digitalRead( pinDer) == HIGH){
    moverDer();
  }
  else if ( digitalRead( pinIzq) == HIGH){
    moverIzq();
  }
  else {
    detener();
  }
}

void moverDer(){
  digitalWrite( EN, HIGH);
  digitalWrite( Auno, HIGH);
  digitalWrite( Ados, LOW);
  delay( timeDelay);
  detener();
}

void moverIzq(){
  digitalWrite( EN, HIGH);
  digitalWrite( Auno, LOW);
  digitalWrite( Ados, HIGH);
  delay( timeDelay);
  detener();
}

void detener(){
  digitalWrite( EN, LOW);
}

