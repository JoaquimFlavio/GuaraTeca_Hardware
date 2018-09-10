/* 
 * Guarateca_Hardware *** by *** Guarabots___________
 * 
 * [atuador: TB6612FNG]
 * 
 * Utilização das funçoes da ponte H, que permite o 
 * controle de até 2 motores DC.
 * 
 * Autor: Joaquim Flávio A Q Gomes___________________
 * Data: 07/2018_____________________________________
 */

//Inclusão da biblioteca.
#include <GuaraTeca_Hardware.h> 

//Definimos os pinos ao qual a ponte H esta conectado
#define A_1 12
#define A_2 11
#define VA 13 //pino de veocidade
#define B_1 6
#define B_2 5
#define VB 7 //pino de veocidade
#define STBY 9

void setup() {
  //Inicializamos as portas de controle da ponte H.
  inicia_TB6612FNG(A_1, A_2, VA, B_1, B_2, VB, STBY);
   /*
   * Habilitamos o uso do lado A e B da ponte H dupla, com 
   * velocidade total. A velocidade é definida em um intervalo
   * de 0~255 onde 0 é a tensão minima e 255 a tensão maxima.
   */
   stby_TB6612FNG(STBY, HIGH);
   controleDeCorrente_TB6612FNG(VA, 255);
   controleDeCorrente_TB6612FNG(VB, 255); 
}

void loop() {
   /*
   * Realizamos o controle de direção de cada motor de forma
   * independente, utilizando as funçoes de sentido1 e sentido2
   * que permite alterar a direção de rotação do motor na porta
   * informada, vale ressaltar que sempre informe ambas as portas
   * do lado corresponde ao motor na TB6612FNG.
   */
  sentido1_TB6612FNG(A_1, A_2);
  sentido1_TB6612FNG(B_1, B_2);
  delay(150);//Pausa na execução do codigo, de 150ms.
  sentido1_TB6612FNG(A_1, A_2);
  sentido2_TB6612FNG(B_1, B_2);
  delay(150);//Pausa na execução do codigo, de 150ms.
  sentido2_TB6612FNG(A_1, A_2);
  sentido1_TB6612FNG(B_1, B_2);
  delay(150);//Pausa na execução do codigo, de 150ms.
  sentido2_TB6612FNG(A_1, A_2);
  sentido2_TB6612FNG(B_1, B_2);
  delay(150);//Pausa na execução do codigo, de 150ms.
  /*
   * Forçamos a parada do motor (freio), com a utilização
   * desta função o motor irá travar de forma imediata e 
   * permanecerá travado até segunda ordem!
   *                 !!!Atenção!!!
   * A utilização dessa função despende de alto consumo 
   * energetico no sistema!
   */
  trava_TB6612FNG(A_1, A_2, VA, STBY);
  trava_TB6612FNG(B_1, B_2, VB, STBY);
  delay(150);//Pausa na execução do codigo, de 150ms.
  controleDeCorrente_TB6612FNG(VA, 255);
  controleDeCorrente_TB6612FNG(VB, 255);
  /*
   * Diferentemente da função trava, a função desliga 
   * proporciona o desligamento total do motor, de modo 
   * que ele nao atue no movimento de rotação do motor.
   * A exemplo: a função desliga seria algo semelhante 
   * ao neutro de um carro/moto....
   * A função desliga não gasta a energia do sistema.
   */
  desliga_TB6612FNG(A_1, A_2, VA, STBY);
  desliga_TB6612FNG(B_1, B_2, VB, STBY);
  delay(150);//Pausa na execução do codigo, de 150ms.
  controleDeCorrente_TB6612FNG(VA, 255);
  controleDeCorrente_TB6612FNG(VB, 255);
}
