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

#ifndef GuaraTeca_SensorGiroscopioAcelerometro_H
#define GuaraTeca_SensorGiroscopioAcelerometro_H

#if ARDUINO >= 100
    #include "Arduino.h"
#endif
#include <Wire.h>


class SensorGiroscopioAcelerometro{
    public:
        SensorGiroscopioAcelerometro();//construtor da classe SensorGiroscopioAcelerometro.
        void iniciaSensorGiroscopioAcelerometro();//metodo para preparar o hardware para os devidos comandos.

        float AcelerometroX();//pino de leitura do sensor Acelerometro, eixo X.
        float AcelerometroY();//pino de leitura do sensor Acelerometro, eixo Y.
        float AcelerometroZ();//pino de leitura do sensor Acelerometro, eixo Z.

        float GiroscopioX();//pino de leitura do sensor Giroscopio, eixo X.
        float GiroscopioY();//pino de leitura do sensor Giroscopio, eixo Y.
        float GiroscopioZ();//pino de leitura do sensor Giroscopio, eixo Z.

        float temperatura();//pino de leitura do sensor de temperatura.
    //protected:
        void _ObtemDados();//metodo interno para leitura do vetor de dados do sensor.
    private:
        int dadosGiroscopio[7];//variavel para armazenar os dados lidos pelo sensor.
};

#endif