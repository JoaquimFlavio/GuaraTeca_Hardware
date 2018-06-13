/* 
 * Guarateca_Hardware *** by *** Guarabots___________
 * 
 * [sensor: Giroscopio GY521-MPU6050 e semelhantes]
 * 
 * Utilização das funçoes de manipulação do sensor 
 * giroscopio/acelerometro I2C (GY521-MPU6050).
 * 
 * !!!!Conectar nas portas I2C do micro-controlador
 * 
 * Autor: Joaquim Flávio A Q Gomes___________________
 * Data: 06/2018_____________________________________
 */

//Inclusão da biblioteca.
#include <GuaraTeca_Hardware.h> 

//Definimos o endereço do sensor no barramento I2C.
#define enderecoPadrao 0x68

//Definimos a variavel que irá armazenar os dados.
int dados[7];

void setup() {
  //Inicialização do monitor Serial em 9600.
  Serial.begin(9600);
   /*
   * Inicializamos o sensor de condutividade em liquidos 
   * e solidos (sensor agua) no endereço previamente 
   * definidodo barramento I2C.
   */ 
  inicia_GY521_MPU6050(enderecoPadrao);
}

void loop() {
  /*
   * Armazenamos no aray os dados do sensor no endereço 
   * previamente definido no barramente I2C.
   */
  obtemDados_GY521_MPU6050(dados, enderecoPadrao);

  //Imprimimos os dados no monitor serial
  Serial.print("AX: ");//Eixo X do acelerometro
  Serial.print(dados[0]);
  Serial.print(" AY: ");//Eixo Y do acelerometro
  Serial.print(dados[1]);
  Serial.print(" AZ: ");//Eixo Z do acelerometro
  Serial.print(dados[2]);
  Serial.print(" | ");
  Serial.print("GX: ");//Eixo X do giroscopio
  Serial.print(dados[4]);
  Serial.print(" GY: ");//Eixo Y do giroscopio
  Serial.print(dados[5]);
  Serial.print(" GZ: ");//Eixo Z do giroscopio
  Serial.print(dados[6]);
  Serial.print(" | ");
  Serial.print("temperatura: ");//Temperatura lida
  Serial.println(dados[3]);
  
  delay(300);//Pausa na execução do codigo, de 300ms.
}
