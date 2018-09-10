//Copyright 2017 Joaquim Flávio Almeida Quirino Gomes, Dêmis Carlos ----*
//Fonseca Gomes, Marcos Dias da Conceição e Diego de Castro Rodrigues---*
//----------------------------------------------------------------------*
//Este arquivo é parte da Biblioteca de Funções Guarateca---------------*
//A Guarateca é um software livre; você pode redistribuí-lo e/ou--------* 
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

#include <GuaraTeca_Hardware.h>

//MotorShield V1____________________________________________________________
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
            comando[5] = 1;
            comando[4] = 0;
        break;
        case 2:
            comando[6] = 1;
            comando[3] = 0;
        break;
        case 3:
            comando[2] = 1;
            comando[0] = 0;
        break;
        case 4:
            comando[7] = 1;
            comando[1] = 0;
        break;
    }
    converteComando();//atualiza o estado dos motores da motor shield.
}
void MotorShield::sentido2(uint8_t conexao){
    switch(conexao){
        case 1:
            comando[5] = 0;
            comando[4] = 1;
        break;
        case 2:
            comando[6] = 0;
            comando[3] = 1;
        break;
        case 3:
            comando[2] = 0;
            comando[0] = 1;
        break;
        case 4:
            comando[7] = 0;
            comando[1] = 1;
        break;
    }
    converteComando();//atualiza o estado dos motores da motor shield.
}
void MotorShield::trava(uint8_t conexao){
    switch(conexao){
        case 1:
            comando[5] = 1;
            comando[4] = 1;
        break;
        case 2:
            comando[6] = 1;
            comando[3] = 1;
        break;
        case 3:
            comando[2] = 1;
            comando[0] = 1;
        break;
        case 4:
            comando[7] = 1;
            comando[1] = 1;
        break;
    }
    converteComando();//atualiza o estado dos motores da motor shield.
}
void MotorShield::desliga(uint8_t conexao){
    switch(conexao){
        case 1:
            comando[5] = 0;
            comando[4] = 0;
        break;
        case 2:
            comando[6] = 0;
            comando[3] = 0;
        break;
        case 3:
            comando[2] = 0;
            comando[0] = 0;
        break;
        case 4:
            comando[7] = 0;
            comando[1] = 0;
        break;
    }
    converteComando();//atualiza o estado dos motores da motor shield.
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
/*Removido devido alto custo de memoria
int MotorShield::identificadorDeComando(){
    int  i, aux = 1, temp = 0;
    for(i = 7; i >= 0 ; i--){
        if(comando[i] == 1){
            temp += aux;
        }
        aux *= 2;
    }
    return temp;
}*/
void MotorShield::converteComando(){
    boolean verifica;//bit de controle

    digitalWrite(_dir_latch, LOW);//desliga latch
    digitalWrite(_dir_clk,   LOW);//desabilita o clock

    for(unsigned char i=0x0; i<0x08; i++)//loop finito para enviar os 8 bits
    {
       digitalWrite(_dir_clk, LOW);//clock em low

       if(comando[i]) verifica = HIGH;
       else verifica = LOW;

       digitalWrite(_dir_ser, verifica);//Habilita saída de dados conforme condição acima
       digitalWrite(_dir_clk, HIGH);
    }

    digitalWrite(_dir_clk, LOW);
    digitalWrite(_dir_latch, HIGH);
}

//PonteH_____________________________________________________________________________
void inicia_PonteH(uint8_t IN1A, uint8_t IN2A, uint8_t A_PWM, uint8_t IN1B, uint8_t IN2B, uint8_t B_PWM){
    pinMode(IN1A , OUTPUT);//define o A1 como saida.
    pinMode(IN2A , OUTPUT);//define o A2 como saida.
    pinMode(IN1B , OUTPUT);//define o B1 como saida.
    pinMode(IN2B , OUTPUT);//define o B2 como saida.
    pinMode(A_PWM, OUTPUT);//define o A_PWM como saida.
    pinMode(B_PWM, OUTPUT);//define o B_PWM como saida.
}
void sentido1_PonteH(uint8_t IN1, uint8_t IN2){
    digitalWrite(IN1, HIGH);//define o P1 como ativo.
    digitalWrite(IN2,  LOW);//define o P2 como desativado.
}
void sentido2_PonteH(uint8_t IN1, uint8_t IN2){
    digitalWrite(IN1,  LOW);//define o P1 como desativado.
    digitalWrite(IN2, HIGH);//define o P2 como ativo.
}
void trava_PonteH(uint8_t IN1, uint8_t IN2, uint8_t PWM){
    digitalWrite(IN1, HIGH);//define o P1 como ativo.
    digitalWrite(IN2, HIGH);//define o P2 como ativo.

    controleDeCorrente_PonteH(PWM, HIGH);//define a corrente no PWM como maxima.
}
void desliga_PonteH(uint8_t IN1, uint8_t IN2, uint8_t PWM){
    digitalWrite(IN1, LOW);//define o P1 como desativado.
    digitalWrite(IN2, LOW);//define o P2 como desativado.

    controleDeCorrente_PonteH(PWM, LOW);//define a corrente no PWM como minima.
}
void controleDeCorrente_PonteH(uint8_t PWM, float corrente){
    analogWrite(PWM, corrente);//define a corrente que saira para o motor; Conecte em um pino PWM.
}

//TB6612FNG______________________________________________________________________
void inicia_TB6612FNG(uint8_t IN1A, uint8_t IN2A, uint8_t A_PWM, uint8_t IN1B, uint8_t IN2B, uint8_t B_PWM, uint8_t STBY){
    pinMode(IN1A , OUTPUT);//define o A1 como saida.
    pinMode(IN2A , OUTPUT);//define o B2 como saida.
    pinMode(IN1B , OUTPUT);//define o B1 como saida.
    pinMode(IN2B , OUTPUT);//define o B2 como saida.
    pinMode(A_PWM, OUTPUT);//define o A_PWM como saida.
    pinMode(B_PWM, OUTPUT);//define o B_PWM como saida.
    pinMode(STBY , OUTPUT);//define o STBY como saida.
}
void sentido1_TB6612FNG(uint8_t IN1, uint8_t IN2){
    digitalWrite(IN1, LOW );//define o IN1 como LOW.
    digitalWrite(IN2, HIGH);//define o IN2 como HIGH.
}
void sentido2_TB6612FNG(uint8_t IN1, uint8_t IN2){
    digitalWrite(IN1, HIGH);//define o IN1 como HIGH.
    digitalWrite(IN2, LOW );//define o IN2 como LOW.
}
void trava_TB6612FNG(uint8_t IN1, uint8_t IN2, uint8_t PWM, uint8_t STBY){
    digitalWrite(IN1 , LOW );//define o IN1 como HIGH.
    digitalWrite(IN2 , LOW );//define o IN2 como HIGH.
    digitalWrite(STBY, HIGH);//desabilita o standby.

    controleDeCorrente_TB6612FNG(PWM, HIGH);//define a corrente no PWM como maxima.
}
void desliga_TB6612FNG(uint8_t IN1, uint8_t IN2, uint8_t PWM, uint8_t STBY){
    digitalWrite(IN1 , LOW );//define o IN1 como LOW.
    digitalWrite(IN2 , LOW );//define o IN2 como LOW.
    digitalWrite(STBY, LOW);//desabilita o standby.

    controleDeCorrente_TB6612FNG(PWM, LOW);//define a corrente do PWM como minima.
}
void controleDeCorrente_TB6612FNG(uint8_t PWM, int corrente){
    analogWrite(PWM, corrente);//define a corrente que saira para o motor; Conecte em um pino PWM.
}
void stby_TB6612FNG(uint8_t STBY, bool estado){
    digitalWrite(STBY, estado ? HIGH : LOW);//desabilita/habilita o standby.
}

//Servo Motor____________________________________________________
void iniciaServo(uint8_t pinoControle){
    pinMode(pinoControle, OUTPUT);
}
void vaPara(uint8_t pinoControle, int angle){
    int tempo = ((0.6+((1.8*angle)/180))*1000);

    for(int ii = 0;ii < 25; ii++){
        digitalWrite(pinoControle, HIGH);
        delayMicroseconds(tempo);
        digitalWrite(pinoControle, LOW);

        for(int i=0;i<((20000-tempo)/tempo);i++){
            delayMicroseconds(tempo);
        }
   }
}



void inicia_7segmentos(uint8_t L1, uint8_t L2, uint8_t L3, uint8_t L4, uint8_t L5, uint8_t L6, uint8_t L7, uint8_t L8){
    pinMode(L1, OUTPUT);
    pinMode(L2, OUTPUT);
    pinMode(L3, OUTPUT);
    pinMode(L4, OUTPUT);
    pinMode(L5, OUTPUT);
    pinMode(L6, OUTPUT);
    pinMode(L7, OUTPUT);
    pinMode(L8, OUTPUT);

    digitalWrite(L1, LOW);
    digitalWrite(L2, LOW);
    digitalWrite(L3, LOW);
    digitalWrite(L4, LOW);
    digitalWrite(L5, LOW);
    digitalWrite(L6, LOW);
    digitalWrite(L7, LOW);
    digitalWrite(L8, LOW);
}

/*
    [L1]
[L6]    [L2]
    [L7]
[L5]    [L3]
    [L4]
  */

void setNumber_7segmentos(int number, uint8_t L1, uint8_t L2, uint8_t L3, uint8_t L4, uint8_t L5, uint8_t L6, uint8_t L7){
    switch(number){
        case 0:
            digitalWrite(L1, HIGH);
            digitalWrite(L2, HIGH);
            digitalWrite(L3, HIGH);
            digitalWrite(L4, HIGH);
            digitalWrite(L5, HIGH);
            digitalWrite(L6, HIGH);
            digitalWrite(L7, LOW);
        break;
        case 1:
            digitalWrite(L1, LOW);
            digitalWrite(L2, HIGH);
            digitalWrite(L3, HIGH);
            digitalWrite(L4, LOW);
            digitalWrite(L5, LOW);
            digitalWrite(L6, LOW);
            digitalWrite(L7, LOW);
        break;
        case 2:
            digitalWrite(L1, HIGH);
            digitalWrite(L2, HIGH);
            digitalWrite(L3, LOW);
            digitalWrite(L4, HIGH);
            digitalWrite(L5, HIGH);
            digitalWrite(L6, LOW);
            digitalWrite(L7, HIGH);
        break;
        case 3:
            digitalWrite(L1, HIGH);
            digitalWrite(L2, HIGH);
            digitalWrite(L3, HIGH);
            digitalWrite(L4, HIGH);
            digitalWrite(L5, LOW);
            digitalWrite(L6, LOW);
            digitalWrite(L7, HIGH);
        break;
        case 4:
            digitalWrite(L1, LOW);
            digitalWrite(L2, HIGH);
            digitalWrite(L3, HIGH);
            digitalWrite(L4, LOW);
            digitalWrite(L5, LOW);
            digitalWrite(L6, HIGH);
            digitalWrite(L7, HIGH);
        break;
        case 5:
            digitalWrite(L1, HIGH);
            digitalWrite(L2, LOW);
            digitalWrite(L3, HIGH);
            digitalWrite(L4, HIGH);
            digitalWrite(L5, LOW);
            digitalWrite(L6, HIGH);
            digitalWrite(L7, HIGH);
        break;
        case 6:
            digitalWrite(L1, HIGH);
            digitalWrite(L2, LOW);
            digitalWrite(L3, HIGH);
            digitalWrite(L4, HIGH);
            digitalWrite(L5, HIGH);
            digitalWrite(L6, HIGH);
            digitalWrite(L7, HIGH);
        break;
        case 7:
            digitalWrite(L1, HIGH);
            digitalWrite(L2, HIGH);
            digitalWrite(L3, HIGH);
            digitalWrite(L4, LOW);
            digitalWrite(L5, LOW);
            digitalWrite(L6, LOW);
            digitalWrite(L7, LOW);
        break;
        case 8:
            digitalWrite(L1, HIGH);
            digitalWrite(L2, HIGH);
            digitalWrite(L3, HIGH);
            digitalWrite(L4, HIGH);
            digitalWrite(L5, HIGH);
            digitalWrite(L6, HIGH);
            digitalWrite(L7, HIGH);
        break;
        case 9:
            digitalWrite(L1, HIGH);
            digitalWrite(L2, HIGH);
            digitalWrite(L3, HIGH);
            digitalWrite(L4, HIGH);
            digitalWrite(L5, LOW);
            digitalWrite(L6, HIGH);
            digitalWrite(L7, HIGH);
        break;
    }
}