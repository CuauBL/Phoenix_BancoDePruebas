OBJETIVO:
El modulo NRF24L nos sirve para mantener una comunicacion entre dos o mas dispositivos, 
la ventaja de este modulo sobre otros en la parte de comunicacion, es que el NRF24L pueder ser
tanto transmisor como receptor, en pocas palabras es un "tranceptor". 
En nuestro proyecto nos servira para mandar los datos obtenidos de los sensores a la computadora de tierra
donde se almacenara toda esta info. 


CONEXIONES:
El NRF24L se basa en el protocolo de comunicacion SPI asi que se conectara a los pines correspondientes
a ese protocolo de comunicacion que son los siguientes:
            UNO Y NANO
SCK__________ PIN 13                            
MISO_________ PIN 12
MOSI_________ PIN 11
CS O SS______ Cualquier pin que este disponible
GND _________ PIN GNG
+ ___________ UNO(3.3V)- NANO (Se necesita un regulador Step Down)

Respecto al color de los cables, el de tierra y voltaje seran los estandarizados. Mientras que para los dema
esta indefinido.



PROCESO DE SetUp:
Las librerias qeu se usaron fue NRF24 Y NRF24Network obtenidas de os siguientes links 
respectivamente: https://github.com/nRF24/RF24 y https://github.com/nRF24/RF24Network. 
Estas se incluyen en el codigo y ademas tambien la libreria SPI.
Se crea el objeto colocando entre parentesis los pines en los que se conecto CE Y CSN y se establecen los 
nodos(los otros  modulos)
RF24 base(5,6);

Se crea la parte de la red y cual modulo estara sincronizada con esta.
RF24Network network(base);

Se inicializa la comunicacion SPI, el modulo, la red y se establece la velocidad de datos.
SPI.begin();
objeto.begin();
network.begin(90,nodo);
base.setDataRate(RD24_2MPBS);

ENVIO:
Para enviar se utiliza la siguiente parte, donde se envia una variable guardada, la cual puede ser
cualquiera.
 RF24NetworkHeader header2(node00);                                    // Es la direccion a la que se enviara la informacion
      bool ok  = network.write(header2, &Datos, sizeof(Datos));                


RECEPCION:
Se utiliza la siguiente parte, si se recibe informacion se guarda en una variable 
unsigned long.
network.update();                                       //Se pone para buscar si hay alguna accion en la red
  while(network.available()){                             //Esta es para recibir la informacion desde otro dispositivo
      RF24NetworkHeader header;
      unsigned long Clave;
      network.read(header, &Clave, sizeof(Clave)); 


