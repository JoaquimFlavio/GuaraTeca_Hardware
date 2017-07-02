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
#include <GuaraTeca_Sensor_HCSR04.h>

HCSR04::HCSR04(){}

void HCSR04::iniciaHCSR04(uint8_t Tp, uint8_t Ep){
    pinMode(Tp, OUTPUT);
    pinMode(Ep, INPUT);
}
float HCSR04::leitura(uint8_t Tp, uint8_t Ep){
    digitalWrite(Tp, LOW);
    delayMicroseconds(2);
    digitalWrite(Tp, HIGH);
    delayMicroseconds(10);
    digitalWrite(Tp, LOW);
    long microsec = pulseIn(Ep, HIGH);
    
    if(next_bug == true){
        return 255;
    }else if((microsec / 27.6233 / 2.0) >= 255.00){
        return 255;
        next_bug = true;
    }else if((microsec / 27.6233 / 2.0) < 255.00 && next_bug == true){
        return (microsec / 27.6233 / 2.0);
        next_bug = false;
    }else{
        return (microsec / 27.6233 / 2.0);
    }
}
