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

#include <GuaraTeca_MotorShield.h>

MotorShield::MotorShield(){}

void MotorShield::iniciaMotorShield(){
    pinMode(_dir_clk,   OUTPUT);//saída para clock
    pinMode(_dir_ser,   OUTPUT);//saída para dados
    pinMode(_dir_latch, OUTPUT);//saída para latch
    pinMode(_dir_en,    OUTPUT);//saída para enable
    pinMode(_PMW1, OUTPUT);//saída para pwm motor1
    pinMode(_PMW2, OUTPUT);//saída para pwm motor2
    pinMode(_PMW3, OUTPUT);//saída para pwm motor3
    pinMode(_PMW4, OUTPUT);//saída para pwm motor4

    digitalWrite(_dir_en, LOW);//seta a variavel como de baixa energia ou desabilitado
    analogWrite(_PMW1, 0);//seta a corrente do pino PMW1, como 0
    analogWrite(_PMW2, 0);//seta a corrente do pino PMW2, como 0
    analogWrite(_PMW3, 0);//seta a corrente do pino PMW3, como 0
    analogWrite(_PMW4, 0);//seta a corrente do pino PMW4, como 0
}

void MotorShield::sentido1(uint8_t conexao){
    switch(conexao){
        case 1:
            comando[2] = 0;
            comando[3] = 1;
        break;
        case 2:
            comando[1] = 0;
            comando[4] = 1;
        break;
        case 3:
            comando[5] = 1;
            comando[7] = 0;
        break;
        case 4:
            comando[0] = 1;
            comando[6] = 0;
        break;
    }
    converteComando(identificadorDeComando());//atualiza o estado dos motores da motor shield.
}
void MotorShield::sentido2(uint8_t conexao){
    switch(conexao){
        case 1:
            comando[2] = 1;
            comando[3] = 0;
        break;
        case 2:
            comando[1] = 1;
            comando[4] = 0;
        break;
        case 3:
            comando[5] = 0;
            comando[7] = 1;
        break;
        case 4:
            comando[0] = 0;
            comando[6] = 1;
        break;
    }
    converteComando(identificadorDeComando());//atualiza o estado dos motores da motor shield.
}
void MotorShield::trava(uint8_t conexao){
    switch(conexao){
        case 1:
            comando[2] = 1;
            comando[3] = 1;
        break;
        case 2:
            comando[1] = 1;
            comando[4] = 1;
        break;
        case 3:
            comando[5] = 1;
            comando[7] = 1;
        break;
        case 4:
            comando[0] = 1;
            comando[6] = 1;
        break;
    }
    converteComando(identificadorDeComando());//atualiza o estado dos motores da motor shield.
}
void MotorShield::desliga(uint8_t conexao){
    switch(conexao){
        case 1:
            comando[2] = 0;
            comando[3] = 0;
        break;
        case 2:
            comando[1] = 0;
            comando[4] = 0;
        break;
        case 3:
            comando[5] = 0;
            comando[7] = 0;
        break;
        case 4:
            comando[0] = 0;
            comando[6] = 0;
        break;
    }
    converteComando(identificadorDeComando());//atualiza o estado dos motores da motor shield.
}
void MotorShield::controleDeCorrente(uint8_t conexao, unsigned char corrente){
    switch(conexao){
        case 1:
            analogWrite(_PMW1, corrente);
        break;
        case 2:
            analogWrite(_PMW2, corrente);
        break;
        case 3:
            analogWrite(_PMW3, corrente);
        break;
        case 4:
            analogWrite(_PMW4, corrente);
        break;
    }
}

int MotorShield::identificadorDeComando(){
    int  i, aux = 1, temp = 0;
    for(i = 7; i >= 0 ; i--){
        if(comando[i] == 1){
            temp += aux;
        }
        aux *= 2;
    }
    return temp;
}
void MotorShield::converteComando(unsigned char identificador){
    boolean verifica;//bit de controle

    digitalWrite(_dir_latch, LOW);//desliga latch
    digitalWrite(_dir_clk,   LOW);//desabilita o clock

    for(unsigned char i=0x0; i<0x08; i++)//loop finito para enviar os 8 bits
    {
       digitalWrite(_dir_clk, LOW);//clock em low

       if(identificador & (1<<i)) verifica = HIGH;
       else verifica = LOW;

       digitalWrite(_dir_ser, verifica);//Habilita saída de dados conforme condição acima
       digitalWrite(_dir_clk, HIGH);
    }

    digitalWrite(_dir_clk, LOW);
    digitalWrite(_dir_latch, HIGH);
}
