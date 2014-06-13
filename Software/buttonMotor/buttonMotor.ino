/*
 2xPulsador + 1xMotor
 ====================
 
 2 pulsadores controlan la direccion de un motor que gira por
 un tiempo determinado.
 */

/*
v0.2
 ====
 */

int pinDer = 2;// pines para los motores
int pinIzq = 3;

int EN   = 4;// pines para el puenteH
int Auno = 5;
int Ados = 6;

int timeDelay = 500;//tiempo para mover el motor

/*
Funciones auxiliares
 ====================
 */
void moverDer(){
  PORTD = B10111111 & (PORTD | B00110000);
  delay( timeDelay);
  detener();
}

void moverIzq(){
  PORTD = B11011111 & (PORTD | B01010000);
  delay( timeDelay);
  detener();
}

void detener(){
  PORTD &= B10001111;
}


/*
Funciones principales 
 =====================
 */
void setup(){
  Serial.begin( 9600);
  DDRD = B11110011 & (DDRD | B01110000);
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
  Serial.flush();
}

/*
v0.1
 ====
 
 // Variable "registerFlag" que determina si el puente H sera 
 // activado con digitalWrite() o on registros
 int registerFlag = 1; // 0 -> digitalWrite | 1 -> registros
 
 void moverDer( int registerFlag){
 if( registerFlag == 0){
 digitalWrite( EN, HIGH);
 digitalWrite( Auno, HIGH);
 digitalWrite( Ados, LOW);
 }
 else if( registerFlag == 1){ 
 PORTD = B10111111 & (PORTD | B00110000);
 }
 delay( timeDelay);
 detener();
 }
 
 void moverIzq(int registerFlag){
 if( registerFlag == 0){
 digitalWrite( EN, HIGH);
 digitalWrite( Auno, LOW);
 digitalWrite( Ados, HIGH);
 }
 else if( registerFlag == 1){
 PORTD = B11011111 & (PORTD | B01010000);
 }
 delay( timeDelay);
 detener();
 }
 
 void detener(){
 digitalWrite( EN, LOW);
 }
 
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
 Serial.println("Boton Derecho");
 moverDer( registerFlag);
 }
 else if ( digitalRead( pinIzq) == HIGH){
 Serial.println("Boton Izquierdo");
 moverIzq( registerFlag);
 }
 else {
 detener();
 }
 Serial.flush();
 }
 */


