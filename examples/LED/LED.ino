/* 
 * Guarateca_Hardware *** by *** Guarabots___________
 * 
 * [atuador: Light Emisor Diod - LED]
 * 
 * Utilização das funçoes de manipulação do LED.
 * 
 * Autor: Joaquim Flávio A Q Gomes___________________
 * Data: 06/2018_____________________________________
 */
//Inclusão da biblioteca.
#include <GuaraTeca_Hardware.h> 

//Definimos em qual pino estará o atuador.
#define pinoLed 11

void setup() {
  /*
   * Inicializamos o manipulação do LED na porta 
   * previamente definida.
   */ 
  inicia_Led(pinoLed);
}

void loop() {
  //Ligamos o LED, na porta previamente definida
  estado_Led(pinoLed, 1);
  delay(50);//Pausa na execução do codigo, de 50ms.
  //Desligamos o LED, na porta previamente definida
  estado_Led(pinoLed, 0);
  delay(50);//Pausa na execução do codigo, de 50ms.
}
