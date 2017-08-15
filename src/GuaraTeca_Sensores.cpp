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

#include <GuaraTeca_Hardware.h>
#include <Wire.h>

//Sensor Agua Funcoes________________________________________
void inicia_SensorAgua(uint8_t pinoA, uint8_t pinoD){
    if(pinoD == 0){
        pinMode(pinoA, INPUT);
    }else{
        pinMode(pinoA, INPUT);
        pinMode(pinoD, INPUT);
    }
}
short int leitura_SensorAgua(uint8_t pinoA, uint8_t pinoD){
    if(pinoD == 0){
        return analogRead(pinoA);
    }else{
        return digitalRead(pinoD);
    }
}
//Sensor Refletancia Funcoes________________________________________
void inicia_SensorRefletancia(uint8_t pino){
    pinMode(pino, INPUT);
}
int leitura_SensorRefletancia(uint8_t pino){
    return analogRead(pino);
}

//Sensor TCS230___________________________________________________
void inicia_TCS230(uint8_t out, uint8_t S0, uint8_t S1, uint8_t S2, uint8_t S3){
    pinMode(S0, OUTPUT);
    pinMode(S1, OUTPUT);
    pinMode(S2, OUTPUT);
    pinMode(S3, OUTPUT);
    pinMode(out, INPUT);
}
void filtroVermelho_TCS230(uint8_t S2, uint8_t S3){
    digitalWrite(S2, LOW);
    digitalWrite(S3, LOW);
}
void filtroVerde_TCS230(uint8_t S2, uint8_t S3){
    digitalWrite(S2, HIGH);
    digitalWrite(S3, HIGH);
}
void filtroAzul_TCS230(uint8_t S2, uint8_t S3){
    digitalWrite(S2, LOW);
    digitalWrite(S3, HIGH);
}
void filtroNulo_TCS230(uint8_t S2, uint8_t S3){
    digitalWrite(S2, HIGH);
    digitalWrite(S3, LOW);
}
void frequencia_TCS230(uint8_t S0, uint8_t S1, uint8_t OPT){
    switch(OPT){
        case 1://2%
            digitalWrite(S0, LOW);
            digitalWrite(S1, HIGH);
        break;
        case 2://20%
            digitalWrite(S0, HIGH);
            digitalWrite(S1, LOW);
        break;
        case 3://100%
            digitalWrite(S1, HIGH);
            digitalWrite(S0, HIGH);
        break;
        default://0%
            digitalWrite(S0, LOW);
            digitalWrite(S1, LOW);
    }
}
int leitura_TCS230(uint8_t out){
    return pulseIn(out, LOW);
}

//HCSR04_________________________________________________________________
void inicia_HCSR04(uint8_t Tp, uint8_t Ep){
    pinMode(Tp, OUTPUT);
    pinMode(Ep, INPUT);
}
float leitura_HCSR04(uint8_t Tp, uint8_t Ep){
    static bool next_bug;//variavel auxiliar para corigir erro de hardware do sensor.
    digitalWrite(Tp, LOW);
    delayMicroseconds(2);
    digitalWrite(Tp, HIGH);
    delayMicroseconds(10);
    digitalWrite(Tp, LOW);
    long microsec = pulseIn(Ep, HIGH);
    
    if(next_bug == true){
        return 255;
    }else if((microsec / 27.6233 / 2.0) >= 255.00){
        return 255;
        next_bug = true;
    }else if((microsec / 27.6233 / 2.0) < 255.00 && next_bug == true){
        return (microsec / 27.6233 / 2.0);
        next_bug = false;
    }else{
        return (microsec / 27.6233 / 2.0);
    }
}
//Botao Funcoes_______________________________________________________________
void inicia_Botao(uint8_t Pin){
    pinMode(Pin, INPUT_PULLUP);
}
int estado_Botao(uint8_t Pin){
    return digitalRead(Pin);
}
//Giroscopio Funcoes_______________________________________________________________
void inicia_GY521_MPU6050(char endereco){
    Wire.begin();
    Wire.beginTransmission(endereco);
    Wire.write(0x6B);
    //Inicializa o MPU-6050
    Wire.write(0);
    Wire.endTransmission(true);
}
void obtemDados_GY521_MPU6050(int array[], char endereco){
    Wire.beginTransmission(endereco);
    Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
    Wire.endTransmission(false);

    //Solicita os dados do sensor
    Wire.requestFrom(endereco,14,true);

    //Armazena o valor dos sensores nas variaveis correspondentes
    array[0]=Wire.read()<<8|Wire.read(); //0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
    array[1]=Wire.read()<<8|Wire.read(); //0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
    array[2]=Wire.read()<<8|Wire.read(); //0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
    array[3]=Wire.read()<<8|Wire.read(); //0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
    array[4]=Wire.read()<<8|Wire.read(); //0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
    array[5]=Wire.read()<<8|Wire.read(); //0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
    array[6]=Wire.read()<<8|Wire.read(); //0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
}