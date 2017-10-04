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

//CI: 74HC595___________________________________________________________________
void inicia_74HC595(uint8_t SH_CP, uint8_t DS, uint8_t ST_CP, uint8_t enable){
    pinMode(SH_CP,  OUTPUT);
    pinMode(DS,     OUTPUT);
    pinMode(ST_CP,  OUTPUT);
    if(enable != -1){
        pinMode(enable, OUTPUT);    
        digitalWrite(enable, LOW);
    }
}
void converteComando_74HC595(byte identificador, uint8_t SH_CP, uint8_t DS, uint8_t ST_CP){
    bool verifica;//bit de controle

    digitalWrite(ST_CP, LOW);//desliga latch
    digitalWrite(SH_CP,   LOW);//desabilita o clock

    for(unsigned char i=0x0; i<0x08; i++)//loop finito para enviar os 8 bits
    {
       digitalWrite(SH_CP, LOW);//clock em low

       if(identificador & (1<<i)) verifica = HIGH;
       else verifica = LOW;

       digitalWrite(DS, verifica);//Habilita saída de dados conforme condição acima
       digitalWrite(SH_CP, HIGH);
    }

    digitalWrite(SH_CP, LOW);
    digitalWrite(ST_CP, HIGH);
}

void estado_74HC595(uint8_t enablePin, bool enable){
    digitalWrite(enablePin, enable ? HIGH : LOW);
}