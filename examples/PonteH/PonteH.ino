/* 
 * Guarateca_Hardware *** by *** Guarabots___________
 * 
 * [atuador: ponteH simples/dupla]
 * 
 * Utilização das funçoes da ponte H, que permite o 
 * controle de até 2 motores DC.
 * 
 * Autor: Joaquim Flávio A Q Gomes___________________
 * Data: 06/2018_____________________________________
 */

//Inclusão da biblioteca.
#include <GuaraTeca_Hardware.h> 

//Definimos os pinos ao qual a ponte H esta conectado
#define A1 7
#define A2 6
#define VA 10 //pino de veocidade
#define B1 5
#define B2 4
#define VB 11 //pino de veocidade

void setup() {
  //Inicializamos as portas de controle da motor shield.
  inicia_PonteH(A1, A2, VA, B1, B2, VB);
   /*
   * Habilitamos o uso do lado A e B da ponte H dupla, com 
   * velocidade total. A velocidade é definida em um intervalo
   * de 0~255 onde 0 é a tensão minima e 255 a tensão maxima.
   */
  controleDeCorrente_PonteH(VA, 255);
  controleDeCorrente_PonteH(VB, 255);
}

void loop() {
   /*
   * Realizamos o controle de direção de cada motor de forma
   * independente, utilizando as funçoes de sentido1 e sentido2
   * que permite alterar a direção de rotação do motor na porta
   * informada, vale ressaltar que sempre informe ambas as portas
   * do lado corresponde ao motor na ponteH.
   */
  sentido1_PonteH(A1, A2);
  sentido1_PonteH(B1, B2);
  delay(150);//Pausa na execução do codigo, de 150ms.
  sentido1_PonteH(A1, A2);
  sentido2_PonteH(B1, B2);
  delay(150);//Pausa na execução do codigo, de 150ms.
  sentido2_PonteH(A1, A2);
  sentido1_PonteH(B1, B2);
  delay(150);//Pausa na execução do codigo, de 150ms.
  sentido2_PonteH(A1, A2);
  sentido2_PonteH(B1, B2);
  delay(150);//Pausa na execução do codigo, de 150ms.
  /*
   * Forçamos a parada do motor (freio), com a utilização
   * desta função o motor irá travar de forma imediata e 
   * permanecerá travado até segunda ordem!
   *                 !!!Atenção!!!
   * A utilização dessa função despende de alto consumo 
   * energetico no sistema!
   */
  trava_PonteH(A1, A2);
  trava_PonteH(B1, B2);
  delay(150);//Pausa na execução do codigo, de 150ms.
  /*
   * Diferentemente da função trava, a função desliga 
   * proporciona o desligamento total do motor, de modo 
   * que ele nao atue no movimento de rotação do motor.
   * A exemplo: a função desliga seria algo semelhante 
   * ao neutro de um carro/moto....
   * A função desliga não gasta a energia do sistema.
   */
  desliga_PonteH(A1, A2);
  desliga_PonteH(B1, B2);
  delay(150);//Pausa na execução do codigo, de 150ms.
}
