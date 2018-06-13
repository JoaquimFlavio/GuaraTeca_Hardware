/* 
 * Guarateca_Hardware *** by *** Guarabots___________
 * 
 * [sensor: TTC104]
 * 
 * Utilização das funçoes de manipulação do sensor de
 * temperatura TTC104.
 * 
 * Autor: Joaquim Flávio A Q Gomes___________________
 * Data: 06/2018_____________________________________
 */

//Inclusão da biblioteca.
#include <GuaraTeca_Hardware.h> 

//Definimos em qual pino estará o sensor.
#define pinoSensorTTC104 A0

void setup() {
  //Inicialização do monitor Serial em 9600.
  Serial.begin(9600);
  
  //Inicializamos o sensor de refletancia.
  inicia_TTC104(pinoSensorTTC104);
}

void loop() {
  /*
   * Realizamos a impresão no monitor serial do valor
   * lido pelo sensor de temperaturas.
   */
  Serial.println(leitura_TTC104(pinoSensorTTC104));
  delay(150);//Pausa na execução do codigo, de 150ms.
}
