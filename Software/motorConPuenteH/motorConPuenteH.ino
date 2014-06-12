/* 
 Sketch para mover el motor con puente H
 ---------------------------------------
 
 Para detener se lee               '0' por el serial
 Para mover a la derecha se lee    '1' por el serial
 Para mover a la izquierda se lee  '2' por el serial
 Para dejar libre(?)               '3' por el serial
 */

int EN   = 2;
int Auno = 3;
int Ados = 4;

char instruction;

void setup(){
  Serial.begin( 9600);
  pinMode(   EN, OUTPUT);
  pinMode( Auno, OUTPUT);
  pinMode( Ados, OUTPUT);
}

void loop(){
  if ( Serial.available() > 0){
    instruction = Serial.read();
    Serial.flush();
  }

  if ( instruction == '1'){
    moverDer();
  }
  else if ( instruction == '2'){
    moverIzq();
  }
  else if ( instruction == '0'){
    detener();
  }
  else if ( instruction == '3'){
    libertad();
  }
}

void moverDer(){
  digitalWrite( EN, HIGH);
  digitalWrite( Auno, HIGH);
  digitalWrite( Ados, LOW);
}

void moverIzq(){
  digitalWrite( EN, HIGH);
  digitalWrite( Auno, LOW);
  digitalWrite( Ados, HIGH);
}

void detener(){
  digitalWrite( EN, LOW);
}

void libertad(){
  digitalWrite( EN, HIGH);
  digitalWrite( Auno, HIGH);
  digitalWrite( Ados, HIGH);
}

/*
Referencias:
 http://quarkstream.wordpress.com/2010/01/07/arduino-8-the-h-bridge/
 http://itp.nyu.edu/physcomp/Labs/DCMotorControl
 http://www.olimex.cl/pdf/IC/SN754410.pdf
 http://www.olimex.cl/product_info.php?products_id=212&product__name=Puente_H_SN754410_para_control_de_motores_hasta_1A
 */


