#include <DHT.h>
#include <DHT_U.h>
#include <SPI.h>
#include <SD.h>

#define SENSOR 3

int TEMP;
int HUM;

#define SSpin 10
File archivo;
DHT dht(SENSOR,DHT11);

void setup() {
  Serial.begin(9600);
  dht.begin();

  Serial.println("Incializando tarjeta...");
  if(!SD.begin(SSpin)){
    Serial.println("Fallo en inicializar...");
    return;
  }
 Serial.println("inicializacion correcta");
 archivo=SD.open("datos.txt", FILE_WRITE);

 if(archivo){
  for (int i=1; i<31; i++){
    TEMP = dht.readTemperature();
    HUM = dht.readHumidity();

    archivo.print(i);
    archivo.print(",");
    archivo.print(TEMP);
    archivo.print(",");
    archivo.println(HUM);

    Serial.print(i);
    Serial.print(",");
    Serial.print(TEMP);
    Serial.print(",");
    Serial.println(HUM);

    delay(1000);
  }
  archivo.close();
  Serial.println("Escritura correcta!");
 }else{
  Serial.println("error en apertur de datos.txt");
 }

}
void loop(){
  
}
