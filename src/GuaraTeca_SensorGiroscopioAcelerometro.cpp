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

#include <GuaraTeca_SensorGiroscopioAcelerometro.h>

SensorGiroscopioAcelerometro::SensorGiroscopioAcelerometro(){}

void SensorGiroscopioAcelerometro::iniciaSensorGiroscopioAcelerometro(){
    Wire.begin();
    Wire.beginTransmission(0x68);
    Wire.write(0x6B);
    //Inicializa o MPU-6050
    Wire.write(0);
    Wire.endTransmission(true);
}
void SensorGiroscopioAcelerometro::_ObtemDados(){
    Wire.beginTransmission(0x68);
    Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
    Wire.endTransmission(false);

    //Solicita os dados do sensor
    Wire.requestFrom(0x68,14,true);

    //Armazena o valor dos sensores nas variaveis correspondentes
    dadosGiroscopio[0] = Wire.read()<<8|Wire.read(); //0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
    dadosGiroscopio[1] = Wire.read()<<8|Wire.read(); //0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
    dadosGiroscopio[2] = Wire.read()<<8|Wire.read(); //0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
    dadosGiroscopio[3] = Wire.read()<<8|Wire.read(); //0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
    dadosGiroscopio[4] = Wire.read()<<8|Wire.read(); //0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
    dadosGiroscopio[5] = Wire.read()<<8|Wire.read(); //0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
    dadosGiroscopio[6] = Wire.read()<<8|Wire.read(); //0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
}
float SensorGiroscopioAcelerometro::AcelerometroX(){
    return dadosGiroscopio[0];
}
float SensorGiroscopioAcelerometro::AcelerometroY(){
    return dadosGiroscopio[1];
}
float SensorGiroscopioAcelerometro::AcelerometroZ(){
    return dadosGiroscopio[2];
}

float SensorGiroscopioAcelerometro::GiroscopioX(){
    return dadosGiroscopio[4];
}
float SensorGiroscopioAcelerometro::GiroscopioY(){
    return dadosGiroscopio[5];
}
float SensorGiroscopioAcelerometro::GiroscopioZ(){
    return dadosGiroscopio[6];
}

float SensorGiroscopioAcelerometro::temperatura(){
    return dadosGiroscopio[3];
}
