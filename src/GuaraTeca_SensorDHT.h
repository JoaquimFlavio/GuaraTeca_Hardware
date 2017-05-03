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

#ifndef GuaraTeca_SensorDHT_H 
#define GuaraTeca_SensorDHT_H

#if ARDUINO >= 100
    #include "Arduino.h"
#endif
//#include <Others\DHT_sensor_library\DHT.h>
#include <DHT.h>

#define modelSensor DHT11

class SensorDHT : public DHT{
    public:
        SensorDHT(uint8_t pino, uint8_t modelo_sensor=1);//construtor da classe SensorDHT.

        float leitura_temperatura();//metodo para retornar o valor lido pelo sensor.
        float leitura_umidade();//metodo para retornar o valor lido pelo sensor.
    private:
        uint8_t _pino;//pino de leitura do sensor.
        uint8_t modelo_sensor;//definição da verção do sensor.      
};
#endif