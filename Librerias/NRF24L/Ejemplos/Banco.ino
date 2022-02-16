// MODULO NRF24
#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>

#include <SPI.h>
RF24 banco(8,9);              //(CE,CSN)           //PENDIENTE


const byte address[6]="MAX66";        //Se crea la direccion o canal donde se enviaran los datos


unsigned long Timer = 1000; 
unsigned long Time1 = 0;

//MODULO MAX6675
#include <max6675.h>
byte SCk = 6;            //SCK Y MISO son el mismo para los dos modulos Max
byte SO = 4;
byte CS1 = 5;
byte CS2 = 3;          

typedef struct{                 //Esta es la estructura que se enviara
  float Temperatura1;
  float Temperatura2;
}Data;

MAX6675 termopar1(SCk,CS1,SO); 
MAX6675 termopar2(SCk,CS2,SO);

void setup() {
   Serial.begin(9600);
   //NRF24
   SPI.begin();                      //Se inicializa la comunicacion SPI
   banco.begin();                     //Se inicializa el modulo NRF24
   banco.openWritingPipe(address);
   banco.setPALevel(RF24_PA_MIN);
   banco.stopListening();                 //Aqui dice que actuara como transmisor
  
}


void loop() {
    Data Datos;
      if(millis() - Time1 > Timer){
         Time1 = millis();
         Datos.Temperatura1 = termopar1.readCelsius();
         Datos.Temperatura2 = termopar2.readCelsius();
      }
      ENVIO(Datos);
}

void ENVIO(const Data INF){                            //La informacion que esta recibiendo la esta almacenando en una struct llamada INF y sera constante
      banco.write(&INF, sizeof(INF));                  //Se envia los datos del MAX    
}
