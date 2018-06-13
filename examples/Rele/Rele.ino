/* 
 * Guarateca_Hardware *** by *** Guarabots___________
 * 
 * [atuador: Rele]
 * 
 * Utilização das funçoes de manipulação do rele.
 * 
 * Autor: Joaquim Flávio A Q Gomes___________________
 * Data: 06/2018_____________________________________
 */

//Inclusão da biblioteca.
#include <GuaraTeca_Hardware.h> 

//Definimos em qual pino estará o atuador.
#define pinoRele 11

void setup() {
  /*
   * Inicializamos o manipulação do rele na porta 
   * previamente definida.
   */ 
  inicia_Rele(pinoRele);
}

void loop() {
  //Ligamos o LED, na porta previamente definida
  estado_Rele(pinoRele, 1);
  delay(50);//Pausa na execução do codigo, de 50ms.
  //Desligamos o LED, na porta previamente definida
  estado_Rele(pinoRele, 0);
  delay(50);//Pausa na execução do codigo, de 50ms.
}
