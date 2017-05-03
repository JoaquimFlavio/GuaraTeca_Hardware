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
};
#endif