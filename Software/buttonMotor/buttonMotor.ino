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

// Variable "registerFlag" que determina si el puente H sera 
// activado con digitalWrite() o on registros
int registerFlag = 1; // 0 -> digitalWrite | 1 -> registros

/* Funciones auxiliares */
void moverDer( int registerFlag){
  if( registerFlag == 0){
    digitalWrite( EN, HIGH);
    digitalWrite( Auno, HIGH);
    digitalWrite( Ados, LOW);
  }
  else if( registerFlag == 1){
    PORTD = PORTD | B00110000;
  }
  delay( timeDelay);
  detener();
}

void moverIzq(){
  if( registerFlag == 0){
    digitalWrite( EN, HIGH);
    digitalWrite( Auno, LOW);
    digitalWrite( Ados, HIGH);
  }
  else if( registerFlag == 1){
    PORTD = PORTD | B01010000;
  }
  delay( timeDelay);
  detener();
}

void detener(){
  digitalWrite( EN, LOW);
}

/* Funciones principales */
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
    moverDer( registerFlag);
  }
  else if ( digitalRead( pinIzq) == HIGH){
    moverIzq( registerFlag);
  }
  else {
    detener();
  }
}





