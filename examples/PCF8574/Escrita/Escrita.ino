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
}

void loop() {
  /*
   * Utilizamos o metodo "estadoPino(pino, endereço)" para
   * alterar o estado do pino: HIGH/LOW.
   */
  for(int i=0;i<8;i++){
    expansor.estadoPino(i, HIGH);
    delay(500);
    expansor.estadoPino(i, LOW);
    delay(500);
  }
}
