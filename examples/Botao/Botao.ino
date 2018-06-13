/* 
 * Guarateca_Hardware *** by *** Guarabots___________
 * 
 * [sensor: botao]
 * 
 * Utilização das funçoes de manipulação do sensor de
 * toque.
 * 
 * Autor: Joaquim Flávio A Q Gomes___________________
 * Data: 06/2018_____________________________________
 */

//Inclusão da biblioteca
#include <GuaraTeca_Hardware.h>

//definimos em qual pino estará o sensor
#define pinoBotao 5

void setup() {
  //Inicialização do monitor Serial em 9600
  Serial.begin(9600);
  /*
   * Inicializamos o sensor de toque/botão 
   * na porta previamente definida.
   */
  inicia_Botao(pinoBotao);
}

void loop() {
  /*
   * Realizamos a impresão no monitor serial do 
   * valor lido pelo sensortoque/botão.
   */
  Serial.println(estado_Botao(pinoBotao));
  delay(150);//Pausa na execução do codigo, de 150ms
}
