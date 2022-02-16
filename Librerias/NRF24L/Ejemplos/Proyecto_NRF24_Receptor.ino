
#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>
#include<SPI.h>


RF24 radio(8,9);               // nRF24L01 (CE,CSN)
const byte address[6] = "MAX66";        //Direccion o canal por el que se recibira la informacion

typedef struct {
  float Temperatura1;
  float Temperatura2;
}Datos;

Datos datos;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  radio.begin();
  radio.openReadingPipe(0,address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  if(radio.available() ) {     // Is there any incoming data?
    radio.read(&datos, sizeof(datos)); // Read the incoming data
    Serial.print(datos.Temperatura1);
    Serial.print("\t");
    Serial.println(datos.Temperatura2); 
  }
}
