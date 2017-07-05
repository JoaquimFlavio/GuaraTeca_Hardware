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

#ifndef GuaraTeca_PonteH_H 
#define GuaraTeca_PonteH_H
 
#if ARDUINO >= 100
    #include "Arduino.h"
#endif

class PonteH{
    public:
        PonteH();//construtor da classe PonteH
        void iniciaPonteH(uint8_t P1, uint8_t P2, uint8_t P3, uint8_t P4, uint8_t P5, uint8_t P6);//metodo para preparar o hardware para os devidos comandos.
        void sentido1(uint8_t P1, uint8_t P2);//metodo para ativar o motor DC no sentido 1, enviando o pulso positivo para o P1 e o terra para o P2.
        void sentido2(uint8_t P1, uint8_t P2);//metodo para ativar o motor DC no sentido 2, enviando o pulso positivo para o P2 e o terra para o P1.
        void trava(uint8_t P1, uint8_t P2);//metodo para travar o motor, enviando pulso positivo para ambas as portas.
        void controleDeCorrente(uint8_t P1, float corrente);//metodo de controle de corrente passada para o pino de controle da ponteH.
        void desliga(uint8_t P1, uint8_t P2);//metodo para desligar os motores.
};
#endif
