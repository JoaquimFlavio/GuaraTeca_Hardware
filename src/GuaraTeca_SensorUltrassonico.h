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

#ifndef GuaraTeca_SensorUltrassonico_H 
#define GuaraTeca_SensorUltrassonico_H 

#if ARDUINO >= 100
    #include "Arduino.h"
#endif

class SensorUltrassonico{
    public:
        SensorUltrassonico();//construtor da classe SensorUltrassonico.
        void iniciaSensorUltrassonico(uint8_t Tp, uint8_t Ep);//metodo para preparar o hardware para os devidos comandos

        float leitura(uint8_t Tp, uint8_t Ep);//metodo para retornar o valor lido pelo sensor.
    private:
        bool next_bug;//variavel auxiliar para corigir erro de hardware do sensor.
};
#endif
