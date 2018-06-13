/* 
 * Guarateca_Hardware *** by *** Guarabots___________
 * 
 * [atuador: motor-shield]
 * 
 * Utilização das funçoes da motor shield para arduino,
 * que permite o controle de até 4 motores DC.
 * 
 * Autor: Joaquim Flávio A Q Gomes___________________
 * Data: 06/2018_____________________________________
 */

//Inclusão da biblioteca.
#include <GuaraTeca_Hardware.h> 

//Criamos um objeto para controlar os motores.
MotorShield robo;

void setup() {
  //Inicializamos as portas de controle da motor shield.
  robo.iniciaMotorShield();
  /*
   * Habilitamos o uso da porta M1 e M2 da motor shield com 
   * velocidade total. A velocidade é definida em um intervalo
   * de 0~255 onde 0 é a tensão minima e 255 a tensão maxima.
   */
  robo.controleDeCorrente(1, 255);
  robo.controleDeCorrente(2, 255);
}

void loop() {
  /*
   * Realizamos o controle de direção de cada motor de forma
   * independente, utilizando as funçoes de sentido1 e sentido2
   * que permite alterar a direção de rotação do motor na porta
   * informada.
   */
  robo.sentido1(1);
  robo.sentido1(2);
  delay(150);//Pausa na execução do codigo, de 150ms.
  robo.sentido1(1);
  robo.sentido2(2);
  delay(150);//Pausa na execução do codigo, de 150ms.
  robo.sentido2(1);
  robo.sentido1(2);
  delay(150);//Pausa na execução do codigo, de 150ms.
  robo.sentido2(1);
  robo.sentido2(2);
  delay(150);//Pausa na execução do codigo, de 150ms.
  /*
   * Forçamos a parada do motor (freio), com a utilização
   * desta função o motor irá travar de forma imediata e 
   * permanecerá travado até segunda ordem!
   *                 !!!Atenção!!!
   * A utilização dessa função despende de alto consumo 
   * energetico no sistema!
   */
  robo.trava(1);
  robo.trava(2);
  delay(150);//Pausa na execução do codigo, de 150ms.
  /*
   * Diferentemente da função trava, a função desliga 
   * proporciona o desligamento total do motor, de modo 
   * que ele nao atue no movimento de rotação do motor.
   * A exemplo: a função desliga seria algo semelhante 
   * ao neutro de um carro/moto....
   * A função desliga não gasta a energia do sistema.
   */
  robo.desliga(1);
  robo.desliga(2);
  delay(150);//Pausa na execução do codigo, de 150ms.
}
