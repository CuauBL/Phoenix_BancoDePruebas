OBJETIVO: 
Medir la temperatura del motor con los termopares tipo k y con el modulo MAX6675 conectarlo al microcontrolador Arduino

CONEXIONES Y COLORES CABLES:
          GND = NEGRO_____________________PIN Tierra arduino            
          5V = ROJO_______________________PIN 5V arduino
          MISO = NARANJA__________________PIN 4 
          SCK = MORADO____________________PIN 6
          CS1 Y CS2 DEL COLOR QUE SEA_____PIN 5 Y 3


Proceso de SetUp:
La libreria utilizada para el modulo MAX6675 es la MAX6675 library hecha por Adafruit.
Para crear el objeto del termopar se especifica de la siguiente manera
MAX6675 termopar1(1,2,3);
Entre parentesis se colocan los pines en los que ira conectado a arduino. El primero es SCK, segundo CS y el tercero MISO.

La funcion para obtener los datos sensoriados por el sensor es : termopar1.readCelsius(); y termopar1.readFahrenheit();

Return:
Los termopares miden la temperatura y esta puede ser a grados Celsius o Fahrenheit 
Los datos recolectados por el termopar se guardan en variables de tipo flotante.