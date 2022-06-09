Obetivo: 
Este modulo es un convertidor analogico - digital que pasa a la computadora los datos que
obtiene de las celdas de carga, las cuales estan conectadas cuatro haciendo un puente de wheatstone.

Conexiones:
Los pines de SCK y Data pueden ir conectados a cualquier pin que no este siendo ocupado por 
otro modulo, mientras que la conexion de tierra va a GND del arduino y como se alimenta de 5V
ira conectado al pin de 5v de arduino. El color de los cables de tierra y voltaje son los que ya estan
por estandar, mientras que los colores de las otras conexiones pueden ser el que sea.


Proceso de SetUp:
La libreria que se utilizo fue la "HX711_ADC" hecha por Olav Kallhovd. #include "HX711.h"
Los parametros iniciales son el de CALIBRACION, el cual se obtiene del codigo de calibracion del hx711.
El parametro de CALIBRACION se establece con la funcion .set_scale(CALIBRACION);.
Tambien se aplicara la funcion de tara: .tare();, despues de haber establecido la calibracion-
Necesaria una libreria propietaria, una función especifica,parametros iniciales, puerto COM, etc.


Return:
El modulo le pasa a la computadora la masa que se obtiene en Kg pero con este se puede obtener
la fuerza en NEWTON, solo bastaria que pongamos la operacion en el codigo. La variable donde se guarda
la informacion es de tipo float. Para obtener los datos se utiliza la funcion .get_units(),decimales.

