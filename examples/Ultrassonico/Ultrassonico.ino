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

//Definimos em quais pino estará o sensor.
#define TrigPin A0
#define EchoPin A1
//Definimos qual a frequencia de leitura
#define TimeOut 20000

void setup() {
  //Inicialização do monitor Serial em 9600.
  Serial.begin(9600);
  /*
   * Inicializamos o sensor ultrassonico na porta 
   * previamente definida.
   */ 
  inicia_Ultrassonico(TrigPin, EchoPin);
}

void loop() {
  /*
   * Realizamos a impresão no monitor serial do valor
   * lido pelo sensor ultrassonico em centimetros.
   */
  Serial.println(leitura_Ultrassonico(TrigPin, EchoPin));
  delay(50);//Pausa na execução do codigo, de 50ms.
}
