/* 
 * Guarateca_Hardware *** by *** Guarabots___________
 * 
 * [atuador: Buzzer]
 * 
 * Utilização das funçoes de manipulação do buzzer.
 * ... O exemplo a seguir tocará uma beep, semelhante
 * ao de um timer de bombas.
 * 
 * Autor: Joaquim Flávio A Q Gomes___________________
 * Data: 06/2018_____________________________________
 */

//Inclusão da biblioteca.
#include <GuaraTeca_Hardware.h> 

//Definimos em qual pino estará o atuador.
#define pinoBuzzer 11

void setup() {
  /*
   * Inicializamos o manipulação de Buzzer na porta 
   * previamente definida.
   */ 
  inicia_Buzzer(pinoBuzzer);
}

void loop() {
  /*
   * Emitimos um beep durante 50ms na porta previamente 
   * definida.
   */
  beepSimples(pinoBuzzer, 50);
  delay(150);//Pausa na execução do codigo, de 150ms.
}
