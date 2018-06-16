//Copyright 2017 Joaquim Fl�vio Almeida Quirino Gomes, D�mis Carlos ----*
//Fonseca Gomes, Marcos Dias da Concei��o e Diego de Castro Rodrigues---*
//----------------------------------------------------------------------*
//Este arquivo � parte da Biblioteca de Fun��es Guarateca---------------*
//A Guarateca � um software livre; voc� pode redistribu�-lo e/ou--------*
//modific�-lo sob os termos da Licen�a P�blica Geral GNU como publicada-*
//pela Funda��o do Software Livre (FSF); na vers�o 3 da Licen�a,--------*
//ou (a seu crit�rio) qualquer vers�o posterior.------------------------*
//
//Este programa � distribu�do na esperan�a de que possa ser �til,-------*
//mas SEM NENHUMA GARANTIA; sem uma garantia impl�cita de ADEQUA��O-----*
//a qualquer MERCADO ou APLICA��O EM PARTICULAR. Veja a-----------------*
//Licen�a P�blica Geral GNU para mais detalhes.-------------------------*
//
//Voc� deve ter recebido uma c�pia da Licen�a P�blica Geral GNU junto---*
//com este programa. Se n�o, veja <http://www.gnu.org/licenses/>--------*

#include <GuaraTeca_Hardware.h>

//Dpino Funcoes________________________________________
void inicia_pino(uint8_t pino){
    pinMode(pino, OUTPUT);
}
void estado_pino(uint8_t pino, bool estado){
    digitalWrite(pino, estado ? HIGH : LOW);
}
void estado_pino(uint8_t pino, unsigned char PWM){
    analogWrite(pino, PWM);
}
//Buzzer Funcoes__________________________________________________
void inicia_Buzzer(uint8_t pino){
    pinMode(pino, OUTPUT);
}
void beepSimples(uint8_t pino, int tempo){
    digitalWrite(pino, HIGH);
    if (tempo > 0){
        delay(tempo);
        digitalWrite(pino, LOW);
    }
}
void beep(uint8_t speakerpino, int frequencyInHertz, long timeInMilliseconds){
    int x;
    long delayAmount = (long)(1000000/frequencyInHertz);
    long loopTime = (long)((timeInMilliseconds*1000)/(delayAmount*2));
    for (x=0;x<loopTime;x++){
        digitalWrite(speakerpino,HIGH);
        delayMicroseconds(delayAmount);
        digitalWrite(speakerpino,LOW);
        delayMicroseconds(delayAmount);
    }
    delay(20);
}