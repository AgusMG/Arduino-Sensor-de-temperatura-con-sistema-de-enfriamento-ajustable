// -----Funcion si utilizo un sensor de Temperatura:------------------//

// 1) Incluir librerias
#include <OneWire.h>
#include <DallasTemperature.h>

//2) Declarar el puerto por el que vamos a usar OneWire
#define ONE_WIRE_BUS 6;

//3) Declarar una instancia de esta libreria OneWire
OneWire oneWire(6); //podemos declararla como queramos (en oneWire)

//4) Usaremos la libreria de dallas
DallasTemperature sensor(&oneWire); // Le pasamos la ref con &

//---------------------Salida para el ventilador----------------------//
int ventilador=5;
bool ventilador_activado = false;
int temperatura_limite = 27;
float temperatura;
//--------------------------------------------------------------------//

//--------------------- Salida para los botones-----------------------//
int boton_down=2;
int boton_up=3;
//--------------------------------------------------------------------//

//--------------Variables para la funcion: sube_limite()--------------//
long tiempo_anterior_up;
long diferencia_up;
//--------------------------------------------------------------------//

//--------------Variables para la funcion: baja_limite()--------------//
long tiempo_anterior_down;
long diferencia_down;
//--------------------------------------------------------------------//


void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando Sistema Control Temperatura: ");
  //----Ventilador:------//
  pinMode(ventilador,OUTPUT); 

  // Declararemos las interrupciones:
  pinMode(boton_up,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(boton_up),sube_limite,FALLING);

  pinMode(boton_down,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(boton_down),baja_limite,FALLING);
  

}

long contador1 = 0; // Para crear un delay en la toma de T

void loop() {
if (millis()-contador1 > 1000){  
  contador1 = millis();
  //Usamos la variable sensor(ya declarada anteriormente)
  sensor.requestTemperatures(); //requestTemperatures(); es una funcion de la libreria
  temperatura = sensor.getTempCByIndex(0); //Tengo 1 sensor por lo tanto usamos 0, esto varia
  //Serial.println("La temperatura es: " + String(temperatura)); 

  // Llamamos a la funcion: ventilador_accion
  ventilador_accion();
  }
}

void ventilador_accion(){

    if(temperatura > temperatura_limite){
    digitalWrite(ventilador,HIGH);
    ventilador_activado = true;
    Serial.println("Ventilador activado -> "+ String(temperatura));
  }else{
    digitalWrite(ventilador,LOW);
    ventilador_activado = false;
    Serial.println("Ventilador desactivado -> " + String(temperatura));
  }
}

void sube_limite(){ // Proposito de la funcion: No tener el 'rebote' de interferencia
  diferencia_up = millis()  - tiempo_anterior_up;
  tiempo_anterior_up = millis();
  if (diferencia_up > 250){
      temperatura_limite++;
      Serial.println("Limite ->" + String(temperatura_limite));
  }
}

void baja_limite(){ // Proposito de la funcion: No tener el 'rebote' de interferencia
  diferencia_down = millis()  - tiempo_anterior_down;
  tiempo_anterior_down = millis();
  if (diferencia_down > 250){
      temperatura_limite--;
      Serial.println("Limite ->" + String(temperatura_limite));
  }
}
