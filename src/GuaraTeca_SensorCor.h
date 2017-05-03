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

#ifndef GuaraTeca_SensorCor_H 
#define GuaraTeca_SensorCor_H 

#if ARDUINO >= 100
    #include "Arduino.h"
#endif

/*
    Mapeamento de estado dos pinos para filtros do sensor de cor

    -> 0 == LOW
    -> 1 == HIGH

    Pino : S0 | S1 --> frequencia de saida  |   Pino : S2 | S3 --> Filtro
        0  |  0 --> Desligado            |          0  |  0 --> Vermelho____Red
        0  |  1 --> 2%                   |          0  |  1 --> Azul________Blue
        1  |  0 --> 20%                  |          1  |  0 --> sem filtro
        1  |  1 --> 100%                 |          1  |  1 --> Verde_______Green
*/
class SensorCor{    
    public:
        SensorCor();//construtor da classe SensorCor.
        void iniciaSensorCor(uint8_t out, uint8_t S0, uint8_t S1, uint8_t S2, uint8_t S3);//metodo para preparar o hardware para os devidos comandos

        void filtroVermelho();//metodo para ativar o filtro de cor vermelha.
        void filtroVerde();//metodo para ativar o filtro de cor verde.
        void filtroAzul();//metodo para ativar o filtro de cor azul.
        void filtroNulo();//metodo para desativar os filtros de cor.
        void frequencia(uint8_t OPT);//define a frequencia de operação do pino.
        float leitura();//metodo para retornar o valor lido pelo sensor.
    private:
        uint8_t _S0;//pino de controle de frequencia, S0;
        uint8_t _S1;//pino de controle de frequencia, S1;
        uint8_t _S2;//pino de controle de filtros, S2;
        uint8_t _S3;//pino de controle de filtros, S3;
        uint8_t _out;//pino de leitura do sensor;
};
#endif 
