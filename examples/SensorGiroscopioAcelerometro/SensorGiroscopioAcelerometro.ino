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

//Uso do sensor_Giroscopio GuaraTeca_Hardware---------------------------*
//versao: 1.0-----------------------------------------------------------*

#include <GuaraTeca_SensorGiroscopioAcelerometro.h>

SensorGiroscopioAcelerometro objct;//declaramos o sensor giroscopio

void setup() {   
  Serial.begin(9600);
  objct.iniciaSensorGiroscopioAcelerometro();//iniciamos o sensor giroscopio nas portas A4 e A5
}

void loop() {
  Serial.print("Ax: ");
  Serial.print(objct.AcelerometroX());//imprimimos a leitura do eixo X do acelerometro
  Serial.print(" Ay: ");
  Serial.print(objct.AcelerometroY());//imprimimos a leitura do eixo Y do acelerometro
  Serial.print(" Az: ");
  Serial.print(objct.AcelerometroZ());//imprimimos a leitura do eixo Z do acelerometro
  Serial.print(" Gx: ");
  Serial.print(objct.GiroscopioX());//imprimimos a leitura do eixo X do Giroscopio
  Serial.print(" Gy: ");
  Serial.print(objct.GiroscopioY());//imprimimos a leitura do eixo Y do Giroscopio
  Serial.print(" Gz: ");
  Serial.print(objct.GiroscopioZ());//imprimimos a leitura do eixo Z do Giroscopio
  Serial.print(" temp: ");
  Serial.println(objct.temperatura());//imprimimos a leitura de temperatura
}
