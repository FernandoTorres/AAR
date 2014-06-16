/**************************************************************
 * 2 Motores + 2 botones + 1 Sensor
 * ================================
 * 
 * Finalmente ocupare transistores, no se justifica usar un punteH
 * si no se necesita invertir el sentido de giro
 * 
 ***************************************************************/


// Tiempo de gracia para salir de la marca de la cinta
int tiempoGracia = 100; // milisegudos


/*
pinSensor --> Lee la posicion de la cinta usando 
 un pull-down resistor
 
 GND --> 10kohm -|---> pinSensor
                 |---> 5V
 */
int pinSensor = 2;

// Estos pines van a la base de los transistores BC549
// El colector y emisor van a la alimentacion del motor
int pinMotorIzq = 3;
int pinMotorDer = 4;

// Estos pines van a los pulsadores
int pinBotonIzq = 5;
int pinBotonDer = 6;


/***************************
* * Funciones Auxiliares * *
****************************/

void moverIzq(){
  PORTD = B11101111 & (PORTD | B00001000);
  delay( tiempoGracia); // aca esperamos que el sensor marque LOW
  while( digitalRead( pinSensor) == LOW){
    PORTD = B11101111 & (PORTD | B00001000);
  }
  detener(); 
}
void moverDer(){
  PORTD = B11110111 & (PORTD | B00010000);
  delay( tiempoGracia);
  while( digitalRead( pinSensor) == LOW){
    PORTD = B11110111 & (PORTD | B00010000);
  }
  detener();
}
void detener(){
  PORTD &= B11100111; 
}


/****************************
* * Funciones Principales * *
****************************/

void setup(){
  Serial.begin( 9600);
  DDRD = B10011000 & (DDRD | B00011000);
}
void loop(){
  Serial.println( digitalRead( pinSensor));

  if      ( digitalRead( pinBotonIzq) == HIGH){
    moverIzq();
  }
  else if ( digitalRead( pinBotonDer) == HIGH){
    moverDer();
  }
  else{
    detener();
  }
  Serial.flush();
}






