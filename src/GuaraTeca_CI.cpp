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

SN74HC595::SN74HC595(uint8_t SH_CP, uint8_t ST_CP, uint8_t DS, uint8_t enable){
    this->_SH_CP = SH_CP;
    this->_ST_CP = ST_CP;
    this->_DS    = DS;
}
void SN74HC595::inicia(void){
    pinMode(_SH_CP, OUTPUT);
    pinMode(_ST_CP, OUTPUT);
    pinMode(_DS,    OUTPUT);

    /*if(enable != -1){
        pinMode(enable, OUTPUT);    
        digitalWrite(enable, LOW);
    }*/
}
void SN74HC595::estadoPino(uint8_t pino, uint8_t estado){
  if(estado) buf = buf|(1<<pino);
  else       buf = buf&~(1<<pino);
  
  digitalWrite(_ST_CP, LOW);
  shiftOut(_DS, _SH_CP, MSBFIRST, buf);
  digitalWrite(_ST_CP, HIGH);
}

//CI: PCF8574___________________________________________________________________
PCF8574::PCF8574(uint8_t endereco){
    this->_endereco = endereco;
}
void PCF8574::estadoPino(uint8_t pino, bool estado){
    if (estado) buf = buf|(1<<pino);
    else        buf = buf&~(1<<pino); 
    
    Wire.beginTransmission(_endereco);
    Wire.write(buf);
    Wire.endTransmission(); 
}

byte PCF8574::leitura(void){
  //Solicita 1Byte de dados do endereço informado
  Wire.requestFrom(_endereco, 1);
  if (Wire.available()) return Wire.read();
  return -1;
}

//CI: RTC DS1307_________________________________________________________________
void defineTempo_DS1307(uint8_t endereco, uint8_t segundos, uint8_t minutos, uint8_t horas, uint8_t diadasemana, uint8_t diadomes, uint8_t mes, uint8_t ano){
  Wire.beginTransmission(endereco);
  Wire.write(0x00); //Stop no CI para que o mesmo possa receber os dados

  Wire.write(ConverteParaBCD(segundos));
  Wire.write(ConverteParaBCD(minutos));
  Wire.write(ConverteParaBCD(horas));
  Wire.write(ConverteParaBCD(diadasemana));
  Wire.write(ConverteParaBCD(diadomes));
  Wire.write(ConverteParaBCD(mes));
  Wire.write(ConverteParaBCD(ano));
  
  Wire.write(0x00); //Start no CI
  
  Wire.endTransmission(); 
}

void leitura_DS1307(uint8_t endereco, int vet[7]){
  Wire.beginTransmission(endereco);
  Wire.write(0x00);
  Wire.endTransmission();
  Wire.requestFrom(endereco, 7);
  
  vet[0] = ConverteparaDecimal(Wire.read());
  vet[1] = ConverteparaDecimal(Wire.read());
  vet[2] = ConverteparaDecimal(Wire.read() & 0b111111); 
  vet[3] = ConverteparaDecimal(Wire.read()); 
  vet[4] = ConverteparaDecimal(Wire.read());
  vet[5] = ConverteparaDecimal(Wire.read());
  vet[6] = ConverteparaDecimal(Wire.read());
}

byte ConverteParaBCD(byte val){ //Converte o número de decimal para BCD
  return ( (val/10*16) + (val%10) );
}

byte ConverteparaDecimal(byte val)  { //Converte de BCD para decimal
  return ( (val/16*10) + (val%16) );
}