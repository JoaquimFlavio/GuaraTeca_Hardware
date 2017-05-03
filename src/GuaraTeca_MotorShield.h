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

#ifndef GuaraTeca_MotorShield_H
#define GuaraTeca_MotorShield_H

#include <Arduino.h>

/*
    Mapeamento do vetor de controle da Classe MotorShield:
        comando[0] ==> Conexão M4, sentido B || 2(+/-)------->
        comando[1] ==> Conexão M2, sentido A || 1(-/+)---->  |
        comando[2] ==> Conexão M1, sentido A || 1(-/+)->  |  |
        comando[3] ==> Conexão M1, sentido B || 2(+/-)->  |  |
        comando[4] ==> Conexão M2, sentido B || 2(+/-)---->  |
        comando[5] ==> Conexão M3, sentido B || 2(+/-)->     |
        comando[6] ==> Conexão M4, sentido A || 1(-/+)-|----->
        comando[7] ==> Conexão M3, sentido A || 1(-/+)->
*/

#define _PMW1       11  //pino de controle de corrente
#define _PMW2       3   //pino de controle de corrente
#define _PMW3       6   //pino de controle de corrente
#define _PMW4       5   //pino de controle de corrente
#define _dir_clk    4   //clock do registrador no digital  4
#define _dir_ser    8   //dados do registrador no digital  8
#define _dir_latch  12  //latch do registrador no digital 12
#define _dir_en     7   //enable do registrador no digital 7

class MotorShield{
    public:
        MotorShield();//construtor da classe MotorShield.
        void iniciaMotorShield();//metodo para preparar o hardware para os devidos comandos
        void sentido1(uint8_t conexao);//metodo para ativar o motor DC no sentido 1, enviando o pulso positivo para o P2 e o terra para o P1.
        void sentido2(uint8_t conexao);//metodo para ativar o motor DC no sentido 1, enviando o pulso positivo para o P1 e o terra para o P2.
        void trava(uint8_t conexao);//metodo para travar o motor, enviando pulso positivo para ambas as portas.
        void controleDeCorrente(uint8_t conexao, unsigned char corrente);//metodo de controle de corrente passada para o pino de controle da MotorShield.
    protected:
        int identificadorDeComando();//funcao para converter as cadeias binarias para a funcao "converteComando".
        void converteComando(unsigned char identificador);//converte os comandos em pulsos para as portas determinadas da MotorShield.
    private:
        int comando[10];//variavel que guarda a cadeia de comandos binarios para a MotorShield.
};
#endif  