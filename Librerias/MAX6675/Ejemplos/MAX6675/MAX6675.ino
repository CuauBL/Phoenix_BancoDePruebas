/*
        Este codigo se utilizo para probar los dos termopares tipo k 
        con sus respectivos modulos MAX6675
 */


unsigned long Timer = 1000; 
unsigned long Time1 = 0;

//MODULO MAX6675
#include <max6675.h>
byte SCk = 6;            //SCK Y MISO son el mismo para los dos modulos Max
byte SO = 4;             
byte CS1 = 5;
byte CS2 = 3;          

float Temperatura1;
float Temperatura2;

MAX6675 termopar1(SCk,CS1,SO);          //Creando los objetos para cada termopar
MAX6675 termopar2(SCk,CS2,SO);

void setup() {
   Serial.begin(9600);
}

void loop() {
      if(millis() - Time1 > Timer){
         Time1 = millis();
         Temperatura1 = termopar1.readCelsius();
         Serial.print("Temperatura modulo 1: ");
         Serial.print(Temperatura1);
         Serial.print("\t");
         Temperatura2 = termopar2.readCelsius();
         Serial.print("Temperatura modulo 2: ");
         Serial.println(Temperatura2);
      }
}
