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

#include <GuaraTeca_PonteH.h>

PonteH::PonteH(){}

void PonteH::iniciaPonteH(uint8_t P1, uint8_t P2, uint8_t P3, uint8_t P4, uint8_t P5, uint8_t P6){
    pinMode(P1, OUTPUT);//define o P1 como saida.
    pinMode(P2, OUTPUT);//define o P2 como saida.
    pinMode(P3, OUTPUT);//define o P3 como saida.
    pinMode(P4, OUTPUT);//define o P4 como saida.
    pinMode(P5, OUTPUT);//define o P5 como saida.
    pinMode(P6, OUTPUT);//define o P6 como saida.
}
void PonteH::sentido1(uint8_t P1, uint8_t P2){
    digitalWrite(P1, HIGH);//define o P1 como ativo.
    digitalWrite(P2,  LOW);//define o P2 como desativado.
}
void PonteH::sentido2(uint8_t P1, uint8_t P2){
    digitalWrite(P1,  LOW);//define o P1 como desativado.
    digitalWrite(P2, HIGH);//define o P2 como ativo.
}
void PonteH::trava(uint8_t P1, uint8_t P2){
    digitalWrite(P1, HIGH);//define o P1 como ativo.
    digitalWrite(P2, HIGH);//define o P2 como ativo.
}
void PonteH::controleDeCorrente(uint8_t P1, float corrente){
    analogWrite(P1, corrente);//define a corrente que saira para o motor; Conecte em um pino PWM.
}
