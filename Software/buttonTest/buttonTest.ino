/*
Sketch para probar un boton pulsador
 ------------------------------------
 
 */

int pinDer = 2; // lee el estado del pulsador
int pinIzq = 4;

void setup(){
  Serial.begin( 9600);
  pinMode( pinDer, INPUT);
  pinMode( pinIzq, INPUT);
}

void loop(){

  if( digitalRead( pinIzq)){
    Serial.println("Izq");
  }
  else if( digitalRead( pinDer)){
    Serial.println("Der");
  }
}


/*
void loop(){
 Serial.print  ( digitalRead( pinIzq));
 Serial.println( digitalRead( pinDer));
 }
 */



