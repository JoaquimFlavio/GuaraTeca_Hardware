/* 
 * Guarateca_Hardware *** by *** Guarabots___________
 * 
 * [atuador: Buzzer]
 * 
 * Utilização das funçoes de manipulação de auto
 * falantes, buzzer, caixas de som... O exemplo a
 * seguir tocará uma "musiquinha" bem conhecida!
 * 
 * Autor: Joaquim Flávio A Q Gomes___________________
 * Data: 06/2018_____________________________________
 */

//Inclusão da biblioteca.
#include <GuaraTeca_Hardware.h> 

//Definimos em qual pino estará o atuador.
#define pinoBuzzer 11

//Definimos as notas que serão emitidas.
int c = 261;
int d = 294;
int e = 329;
int f = 349;
int g = 391;
int gS = 415;
int a = 440;
int aS = 455;
int b = 466;
int cH = 523;
int cSH = 554;
int dH = 587;
int dSH = 622;
int eH = 659;
int fH = 698;
int fSH = 740;
int gH = 784;
int gSH = 830;
int aH = 880;

void setup() {
  /*
   * Inicializamos o manipulação de auto falantes na 
   * porta previamente definida.
   */ 
  inicia_Buzzer(pinoBuzzer);
}

void loop() {
  /*
   * Tocamos as notas previamente definidas no script,
   * durante os tempos definidos (em ms), na porta 
   * previamente definida.
   */
  beep(pinoBuzzer, a, 500);
  beep(pinoBuzzer, a, 500);
  beep(pinoBuzzer, a, 500);
  beep(pinoBuzzer, f, 350);
  beep(pinoBuzzer, cH, 150);

  beep(pinoBuzzer, a, 500);
  beep(pinoBuzzer, f, 350);
  beep(pinoBuzzer, cH, 150);
  beep(pinoBuzzer, a, 1000);

  beep(pinoBuzzer, eH, 500);
  beep(pinoBuzzer, eH, 500);
  beep(pinoBuzzer, eH, 500);
  beep(pinoBuzzer, fH, 350);
  beep(pinoBuzzer, cH, 150);

  beep(pinoBuzzer, gS, 500);
  beep(pinoBuzzer, f, 350);
  beep(pinoBuzzer, cH, 150);
  beep(pinoBuzzer, a, 1000);

  beep(pinoBuzzer, aH, 500);
  beep(pinoBuzzer, a, 350);
  beep(pinoBuzzer, a, 150);
  beep(pinoBuzzer, aH, 500);
  beep(pinoBuzzer, gSH, 250);
  beep(pinoBuzzer, gH, 250);

  beep(pinoBuzzer, fSH, 125);
  beep(pinoBuzzer, fH, 125);
  beep(pinoBuzzer, fSH, 250);

  delay(250);//Pausa na execução do codigo, de 250ms.

  beep(pinoBuzzer, aS, 250);
  beep(pinoBuzzer, dSH, 500);
  beep(pinoBuzzer, dH, 250);
  beep(pinoBuzzer, cSH, 250);

  beep(pinoBuzzer, cH, 125);
  beep(pinoBuzzer, b, 125);
  beep(pinoBuzzer, cH, 250);
  
  delay(250);//Pausa na execução do codigo, de 250ms.
  
  beep(pinoBuzzer, f, 125);
  beep(pinoBuzzer, gS, 500);
  beep(pinoBuzzer, f, 375);
  beep(pinoBuzzer, a, 125);

  beep(pinoBuzzer, cH, 500);
  beep(pinoBuzzer, a, 375);
  beep(pinoBuzzer, cH, 125);
  beep(pinoBuzzer, eH, 1000);

  beep(pinoBuzzer, aH, 500);
  beep(pinoBuzzer, a, 350);
  beep(pinoBuzzer, a, 150);
  beep(pinoBuzzer, aH, 500);
  beep(pinoBuzzer, gSH, 250);
  beep(pinoBuzzer, gH, 250);

  beep(pinoBuzzer, fSH, 125);
  beep(pinoBuzzer, fH, 125);
  beep(pinoBuzzer, fSH, 250);
  
  delay(250);//Pausa na execução do codigo, de 250ms.
  
  beep(pinoBuzzer, aS, 250);
  beep(pinoBuzzer, dSH, 500);
  beep(pinoBuzzer, dH, 250);
  beep(pinoBuzzer, cSH, 250);

  beep(pinoBuzzer, cH, 125);
  beep(pinoBuzzer, b, 125);
  beep(pinoBuzzer, cH, 250);
  
  delay(250);//Pausa na execução do codigo, de 250ms.
  
  beep(pinoBuzzer, f, 250);
  beep(pinoBuzzer, gS, 500);
  beep(pinoBuzzer, f, 375);
  beep(pinoBuzzer, cH, 125);

  beep(pinoBuzzer, a, 500);
  beep(pinoBuzzer, f, 375);
  beep(pinoBuzzer, c, 125);
  beep(pinoBuzzer, a, 1000);
}
