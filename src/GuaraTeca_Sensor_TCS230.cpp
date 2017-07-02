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

#include <GuaraTeca_Sensor_TCS230.h>

TCS230::TCS230(){}

void TCS230::iniciaTCS230(uint8_t out, uint8_t S0, uint8_t S1, uint8_t S2, uint8_t S3){
    this->_S0 = S0;
    this->_S1 = S1;
    this->_S2 = S2;
    this->_S3 = S3;
    this->_out = out;

    pinMode(_S0, OUTPUT);
    pinMode(_S1, OUTPUT);
    pinMode(_S2, OUTPUT);
    pinMode(_S3, OUTPUT);
    pinMode(_out, INPUT);
}
void TCS230::filtroVermelho(){
    digitalWrite(_S2, LOW);
    digitalWrite(_S3, LOW);
}
void TCS230::filtroVerde(){
    digitalWrite(_S2, HIGH);
    digitalWrite(_S3, HIGH);
}
void TCS230::filtroAzul(){
    digitalWrite(_S2, LOW);
    digitalWrite(_S3, HIGH);
}
void TCS230::filtroNulo(){
    digitalWrite(_S2, HIGH);
    digitalWrite(_S3, LOW);
}
void TCS230::frequencia(uint8_t OPT){
    switch(OPT){
        case 1://2%
            digitalWrite(_S0, LOW);
            digitalWrite(_S1, HIGH);
        break;
        case 2://20%
            digitalWrite(_S0, HIGH);
            digitalWrite(_S1, LOW);
        break;
        case 3://100%
            digitalWrite(_S0, HIGH);
            digitalWrite(_S1, HIGH);
        break;
        default://0%
            digitalWrite(_S0, LOW);
            digitalWrite(_S1, LOW);
    }
}
float TCS230::leitura(){
    return pulseIn(_out, LOW);
}
