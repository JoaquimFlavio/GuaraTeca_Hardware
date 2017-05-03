//Copyright 2017 Joaquim Flávio Almeida Quirino Gomes, Dêmis Carlos ----*
//Fonseca Gomes, Marcos Dias da Conceição e Diego de Castro Rodrigues---*
//----------------------------------------------------------------------*
//Este arquivo é parte da Biblioteca de Funções GuaráTeca---------------*
//A GuaráTeca é um software livre; você pode redistribuí-lo e/ou--------* 
//modificá-lo sob os termos da Licença Pública Geral GNU como publicada-*
//pela Fundação do Software Livre (FSF); na versão 3 da Licença,--------*
//ou (a seu critério) qualquer versão posterior.------------------------*
//
//Este programa é distribuído na esperança de que possa ser útil,-------* 
//mas SEM NENHUMA GARANTIA; sem uma garantia implícita de ADEQUAÇÃO-----*
//a qualquer MERCADO ou APLICAÇÃO EM PARTICULAR. Veja a-----------------*
//Licença Pública Geral GNU para mais detalhes.-------------------------*
//
//Você deve ter recebido uma cópia da Licença Pública Geral GNU junto---*
//com este programa. Se não, veja <http://www.gnu.org/licenses/>--------*
#ifndef GuaraTeca_Bluethoth_H
#define GuaraTeca_Bluethoth_H

#if ARDUINO >= 100
    #include "Arduino.h"
#endif

#include <SoftwareSerial.h>

//Classes para controle de comunicadores---------------------------------------------------------------------
class Bluethoth{
    public:
        Bluethoth(uint8_t pino1, uint8_t pino2);//construtor da classe SensorRefletancia.
        /*void enviaT(char texto[255]);
        char recebeT();*/
        void enviaNum(int numero);
        int recebeNum();
};

#endif
