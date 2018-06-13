/* 
 * Guarateca_Hardware *** by *** Guarabots___________
 * 
 * [sensor: agua]
 * 
 * Utilização das funçoes de manipulação do sensor de
 * condutividade em liquidos e solidos.
 * 
 * Autor: Joaquim Flávio A Q Gomes___________________
 * Data: 06/2018_____________________________________
 */

//Inclusão da biblioteca.
#include <GuaraTeca_Hardware.h> 

//Definimos em qual pino estará o sensor.
#define pinoSensorAgua A0

void setup() {
  //Inicialização do monitor Serial em 9600.
  Serial.begin(9600);
  /*
   * Inicializamos o sensor de condutividade em liquidos 
   * e solidos (sensor agua) na porta previamente definida.
   */ 
  inicia_SensorAgua(pinoSensorAgua);
}

void loop() {
  /*
   * Realizamos a impresão no monitor serial do valor
   * lido pelo sensor de condutividade em liquidos/sensor
   * de agua.
   */
  Serial.println(leitura_SensorAgua(pinoSensorAgua));
  delay(50);//Pausa na execução do codigo, de 50ms.
}
