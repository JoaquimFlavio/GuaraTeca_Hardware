/* 
 * Guarateca_Hardware *** by *** Guarabots___________
 * 
 * [CI: PCF8574 e semelhantes]
 * 
 * Utilização das funçoes de manipulação do registrador
 * de deslocamento (PCF8574).
 * 
 * !!!!Conectar nas portas I2C do micro-controlador
 * 
 * Autor: Joaquim Flávio A Q Gomes___________________
 * Data: 09/2018_____________________________________
 */
 
//Inclusão da biblioteca.
#include <GuaraTeca_Hardware.h>
//Inclusão da biblioteca para I2C.
#include <Wire.h>

//Declaramos o objeto e definimos seu endereço.
PCF8574 expansor(0x3F);

void setup() {
  //Inicialização do monitor Serial em 9600.
  Serial.begin(9600);
  //Inicializamos a biblioteca para I2C.
  Wire.begin();
  /*
   * Utilizamos o metodo "leitura(void)" para realizar a 
   * leitura do estado de todos os pinos.
   * Esse metodo retorna um byte com todos os pinos lidos.
   */
  Serial.println(expansor.leitura(), BIN);
  /*
   * O metodo "leitura(void)" tambem armazena o estado dos
   * pino de forma individual, em um vetor do tipo "bool"
   * cada posição deste vetor representa necessariamente o
   * pino lido. ex: a leitura do pino 0 sera armazenada em 
   * "expansor.porta[0]".
   */
  for(int i=0;i<8;i++){
    Serial.println(expansor.porta[i]?"HIGH":"LOW");
  }
}

void loop() {
  expansor.leitura();
  Serial.println("Leitura dos pinos: ");
  for(int i=0;i<8;i++){
    Serial.println(expansor.porta[i]?"HIGH":"LOW");
  }
}
