#include "HX711.h"
 
// Pin de datos y de reloj
byte pinData = 3;            
byte pinClk = 2;
 
HX711 bascula;
 
// Parámetro para calibrar el peso y el sensor
float factor_calibracion = 10000.0; //Este valor del factor de calibración con el que se comienza a calibrar
 
void setup() {
  Serial.begin(9600);
  Serial.println("HX711 programa de calibracion");
  Serial.println("Quita cualquier peso de la bascula");
  Serial.println("Una vez empiece a mostrar informacion de medidas, coloca un peso conocido encima de la bascula");
  Serial.println("Presiona + para incrementar el factor de calibracion");
  Serial.println("Presiona - para disminuir el factor de calibracion");
 
  // Iniciar sensor
  bascula.begin(pinData, pinClk);
 
  // Aplicar la calibración
  bascula.set_scale();
  // Iniciar la tara
  // No tiene que haber nada sobre el peso
  bascula.tare();
 
  // Obtener una lectura de referencia
  long zero_factor = bascula.read_average();            //Esta lectura quiere decir que al poner algo sobre, la lectura que nos regrese
  // Mostrar la primera desviación                      //sera el factor de calibracion para que el peso que nos regrese sea 0
  Serial.print("Zero factor: ");
  Serial.println(zero_factor);      
}
 
void loop() {
 
  // Aplicar calibración
  bascula.set_scale(factor_calibracion);
 
  // Mostrar la información para ajustar el factor de calibración
  Serial.print("Leyendo: ");
  Serial.print(bascula.get_units(), 3);
  Serial.print(" kgs");
  Serial.print(" factor_calibracion: ");
  Serial.print(factor_calibracion);
  Serial.println();
 
  // Obtener información desde el monitor serie
  if (Serial.available())
  {
    char fact = Serial.read();
    if (fact == '+')
      factor_calibracion += 25;
    else if (fact == '-')
      factor_calibracion -= 10;
  }
}
