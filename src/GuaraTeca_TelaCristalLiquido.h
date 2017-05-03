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

#ifndef GuaraTeca_TelaCristalLiquido_H 
#define GuaraTeca_TelaCristalLiquido_H 

#if ARDUINO >= 100
    #include "Arduino.h"
#endif
//#include <Others\LiquidCrystal\src\LiquidCrystal.h>
#include <LiquidCrystal.h>

class TelaCristalLiquido : public LiquidCrystal{
    public:
        TelaCristalLiquido(uint8_t RS, uint8_t E, 
                           uint8_t D4, uint8_t D5, uint8_t D6, uint8_t D7, 
                           uint8_t D0, uint8_t D1, uint8_t D2, uint8_t D3);//construtor da classe TelaCristalLiquido, modo 8 bits.
        TelaCristalLiquido(uint8_t RS, uint8_t E, 
                           uint8_t D4, uint8_t D5, uint8_t D6, uint8_t D7);//construtor da classe TelaCristalLiquido, modo 4 bits.

        void iniciaTelaCristalLiquido(int C, int L);//metodo para iniciar o display
        void escreveTela(char x[]);//metodo de escrita no display
        void escreveTela2(int x);//metodo de escrita no display
        void limpaTela();//metodo de limpeza do display

        void vaParaHome();//metodo para posicaonar o cursor em 0, 0
        void vaParaDireita();//metodo para mover toda a LINHA para a direita em 1 casa
        void vaParaEsquerda();//metodo para mover toda a LINHA para a esquerda em 1 casa
        void posicaoCursor(int C, int L);//metodo para posicionar o cursor onde for desejado
        void estadoLigado();//exibi textos no display
        void estadoDesligado();//esconde os textos do display
        void pisca();
        void paraPiscar();

    private:

        uint8_t _RS;
        uint8_t _E;
        uint8_t _D4;
        uint8_t _D5;
        uint8_t _D6;
        uint8_t _D7;
        uint8_t _D0;
        uint8_t _D1;
        uint8_t _D3;
        uint8_t _D2;
        uint8_t C;
        uint8_t L;
};
#endif