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

#ifndef GuaraTeca_Hardware_H 
#define GuaraTeca_Hardware_H 

#if ARDUINO >= 100
    #include <Arduino.h>
#endif

#include <Wire.h>

//Sensores_________________________________________________________________________________________
void inicia_SensorAgua(uint8_t pino);//metodo para preparar o hardware para os devidos comandos.
short int leitura_SensorAgua(uint8_t pino);//metodo para retornar o valor lido pelo sensor.

void inicia_SensorRefletancia(uint8_t pino);//metodo para preparar o hardware para os devidos comandos.
int leitura_SensorRefletancia(uint8_t pino);//metodo para retornar o valor lido pelo sensor.

void inicia_GY521_MPU6050(char endereco);//metodo para preparar o hardware para os devidos comandos.
void obtemDados_GY521_MPU6050(int array[], char endereco);//metodo interno para leitura do vetor de dados do sensor.

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
void inicia_TCS230(uint8_t out, uint8_t S0, uint8_t S1, uint8_t S2, uint8_t S3);//metodo para preparar o hardware para os devidos comandos
void filtroCor_TCS230(uint8_t S2, uint8_t S3, char C);//metodo para ativar os filtros de cores do sensor.
void frequencia_TCS230(uint8_t S0, uint8_t S1, uint8_t OPT);//define a frequencia de operação do pino.
int leitura_TCS230(uint8_t out);//metodo para retornar o valor lido pelo sensor.

void inicia_Ultrassonico(uint8_t tp, uint8_t ep);//metodo para preparar o hardware para os devidos comandos
void inicia_Ultrassonico(uint8_t pino);//metodo para preparar o hardware para os devidos comandos
int leitura_Ultrassonico(uint8_t tp, uint8_t ep, unsigned int timeOut = 20000UL);//metodo para retornar o valor lido pelo sensor.
int leitura_Ultrassonico(uint8_t pino, unsigned int timeOut = 20000UL);//metodo para retornar o valor lido pelo sensor.

void inicia_TTC104(uint8_t pin);//metodo para preparar o hardware para os devidos comandos
float leitura_TTC104(uint8_t pin);//metodo para retornar o valor lido pelo sensor.

void inicia_Botao(uint8_t pin);//metodo para preparar o hardware para os devidos comandos.
int estado_Botao(uint8_t pin);//metodo para leitura do botao.

//Atuadores________________________________________________________________________________________
void inicia_pino(uint8_t pino);//metodo para preparar o hardware para os devidos comandos.
void estado_pino(uint8_t pino, bool estado);//metodo para alterar o estado do pino digital (ligado/desligado).
void estado_pino(uint8_t pino, unsigned char PWM);//metodo para inserir um pulso PWM em uma porta PWM (0~255).

void inicia_Buzzer(uint8_t pino);//metodo para preparar o hardware para os devidos comandos.
void beepSimples(uint8_t pino, int tempo);//metodo para ativar o "beep" durante 'X' milissegundos.
void beep(uint8_t speakerPin, int frequencyInHertz, long timeInMilliseconds);//metodo para tocar determinada "tom".

//Motores______________________________________________________________________________________
/*
    Mapeamento de operação logica de uma ponteH

    |==============================================|
    |______INPUT______||__________OUTPUT___________|
    | IN1 | IN2 | PWM || OUT1 | OUT2 |    MODE     |
    |==============================================|
    |  L  |  H  |  H  ||  L   |  H   |     CCW     |
    |  -  |  -  |  L  ||  L   |  L   | short brake |
    |----------------------------------------------| 
    |  H  |  L  |  H  ||  H   |  L   |     CW      |
    |  -  |  -  |  L  ||  L   |  L   | short brake |
    |----------------------------------------------|
    |  H  |  H  |  H  ||HIGH IMPENDCE|    Stop     |
    |----------------------------------------------|
    |  L  |  L  |  L  ||     OFF     |   Standby   |
    |==============================================|
*/

void inicia_PonteH(uint8_t IN1A, uint8_t IN2A, uint8_t A_PWM, uint8_t IN1B, uint8_t IN2B, uint8_t B_PWM);//metodo para preparar o hardware para os devidos comandos.
void controleDeCorrente_PonteH(uint8_t PWM, float corrente);//metodo de controle de corrente passada para o pino de controle.
void sentido1_PonteH(uint8_t IN1, uint8_t IN2);//metodo para ativar o motor DC no sentido 1, enviando o pulso positivo para o P1 e o terra para o P2.
void sentido2_PonteH(uint8_t IN1, uint8_t IN2);//metodo para ativar o motor DC no sentido 2, enviando o pulso positivo para o P2 e o terra para o P1.
void trava_PonteH(uint8_t IN1, uint8_t IN2, uint8_t PWM);//metodo para travar o motor, enviando pulso positivo para ambas as portas.
void desliga_PonteH(uint8_t IN1, uint8_t IN2, uint8_t PWM);//metodo para desligar os motores.


/*
    Mapeamento de operação logica do TB6612FNG

    |===================================================|
    |__________INPUT________|__________OUTPUT___________|
    | IN1 | IN2 | PWM | STB | OUT1 | OUT2 |    MODE     |
    |===================================================|
    |  H  |  H  | H/L |  H  |  L   |  L   | short brake |
    |---------------------------------------------------|
    |  L  |  H  |  H  |  H  |  L   |  H   |     CCW     |
    |     |     |  L  |  H  |  L   |  L   | short brake |
    |---------------------------------------------------| 
    |  H  |  L  |  H  |  L  |  H   |  L   |     CW      |
    |  -  |  -  |  L  |  L  |  L   |  L   | short brake |
    |---------------------------------------------------|
    |  L  |  L  |  H  |  H  |     OFF     |    Stop     |
    |---------------------------------------------------|
    | H/L | H/L | H/L |  L  |     OFF     |   Standby   |
    |===================================================|
*/

void inicia_TB6612FNG(uint8_t IN1A, uint8_t IN2A, uint8_t A_PWM, uint8_t IN1B, uint8_t IN2B, uint8_t B_PWM, uint8_t STBY);//metodo para preparar o hardware para os devidos comandos.
void controleDeCorrente_TB6612FNG(uint8_t PWM, int corrente);//metodo de controle de corrente passada para o pino de controle.
void sentido1_TB6612FNG(uint8_t IN1, uint8_t IN2);//metodo para ativar o motor DC no sentido 1, enviando o pulso positivo para o P1 e o terra para o P2.
void sentido2_TB6612FNG(uint8_t IN1, uint8_t IN2);//metodo para ativar o motor DC no sentido 2, enviando o pulso positivo para o P2 e o terra para o P1.
void trava_TB6612FNG(uint8_t IN1, uint8_t IN2, uint8_t PWM, uint8_t STBY);//metodo para travar o motor, enviando pulso positivo para ambas as portas.
void desliga_TB6612FNG(uint8_t IN1, uint8_t IN2, uint8_t PWM, uint8_t STBY);//metodo para desligar os motores.
void stby_TB6612FNG(uint8_t STBY, bool estado);//metodo para controlar o standby.

/*
    Mapeamento do vetor de controle da Classe MotorShield:
    
        comando[7] ==> Conexão M4, sentido A || 1(-/+)------->
        comando[6] ==> Conexão M2, sentido A || 1(-/+)---->  |
        comando[5] ==> Conexão M1, sentido A || 2(+/-)->  |  |
        comando[4] ==> Conexão M1, sentido B || 2(+/-)->  |  |
        comando[3] ==> Conexão M2, sentido B || 2(+/-)---->  |
        comando[2] ==> Conexão M3, sentido A || 1(-/+)->     |
        comando[1] ==> Conexão M4, sentido B || 1(-/+)-|----->
        comando[0] ==> Conexão M3, sentido B || 2(+/-)->
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
        void desliga(uint8_t conexao);
        void controleDeCorrente(uint8_t conexao, unsigned char corrente);//metodo de controle de corrente passada para o pino de controle da MotorShield.
    protected:
        int identificadorDeComando();//funcao para converter as cadeias binarias para a funcao "converteComando".
        void converteComando( );//converte os comandos em pulsos para as portas determinadas da MotorShield.
    private:
        int comando[8];//variavel que guarda a cadeia de comandos binarios para a MotorShield.
};

//Fase de testes

void iniciaServo(uint8_t pinoControle);
void vaPara(uint8_t pinoControle, int angle);//metodo para posicionar o Servo motor em x graus.
   
//CI_______________________________________________________________________________________________

/*FASE DE TESTES
    SH_CP  ou store  -> Registrador de armazenamento || clock do registrador
    DS     ou data   -> Entrada de dados             || dados do registrador
    ST_CP  ou shift  -> Registrador de deslocamento  || latch do registrador
    OE     ou enable -> Ativa/Desativa saida dados   || enable flipflop do registrador
*/

class SN74HC595{
    public:
        SN74HC595(uint8_t SH_CP, uint8_t ST_CP, uint8_t DS, uint8_t enable = -1);
        void inicia(void);
        void estadoPino(uint8_t pino, uint8_t estado);
    private:
        uint8_t _SH_CP, _ST_CP, _DS;  
        byte buf = 0;  
};

class PCF8574{
    public:
        PCF8574(uint8_t endereco);
        void estadoPino (uint8_t pino, bool estado);
        byte leitura    (void);
    private:
        byte buf = 0;
        uint8_t _endereco;
};

#endif