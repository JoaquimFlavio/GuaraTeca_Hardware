#include <GuaraTeca_Hardware.h>

#define pinoRefletancia A0

void setup() {
  //Inicialização do monitor Serial em 9600.
  Serial.begin(9600);
  /*
   * Inicializamos o sensor de refletancia na 
   * porta previamente definida.
   */ 
  inicia_SensorRefletancia(pinoRefletancia);
}

void loop() {
  /*
   * Realizamos a impresão no monitor serial do valor
   * lido pelo sensor de refltancia.
   */
  Serial.println(leitura_SensorRefletancia(pinoRefletancia));
}
