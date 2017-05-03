//Copyright 2017 Joaquim Fl�vio Almeida Quirino Gomes, D�mis Carlos ----*
//Fonseca Gomes, Marcos Dias da Concei��o e Diego de Castro Rodrigues---*
//----------------------------------------------------------------------*
//Este arquivo � parte da Biblioteca de Fun��es Guar�Teca---------------*
//A Guar�Teca � um software livre; voc� pode redistribu�-lo e/ou--------*
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

#include <GuaraTeca_Servo.h>

Servo::Servo(){}

void Servo::iniciaServo(uint8_t pinoControle){
    pinMode(pinoControle, OUTPUT);
}
void Servo::vaPara(uint8_t pinoControle, int angle){
    localizacao = angle;
    int tempo = ((0.6+((1.8*angle)/180))*1000);

    for(int ii = 0;ii < 25; ii++){
        digitalWrite(pinoControle, HIGH);
        delayMicroseconds(tempo);
        digitalWrite(pinoControle, LOW);

        for(int i=0;i<((20000-tempo)/tempo);i++){
            delayMicroseconds(tempo);
        }
   }
}
void Servo::direita(uint8_t pinoControle, int x){
    digitalWrite(pinoControle, HIGH);
    delay(x);
    digitalWrite(pinoControle, LOW);
}
void Servo::esquerda(){}
//return  map( this->readMicroseconds()+1, SERVO_MIN(), SERVO_MAX(), 0, 180);
