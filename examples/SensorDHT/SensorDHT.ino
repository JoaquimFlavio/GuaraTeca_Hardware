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

//Uso do sensor_DHT GuaraTeca_Hardware----------------------------------*
//versao: 1.0-----------------------------------------------------------*

#include <GuaraTeca_SensorDHT.h>

SensorDHT objct(A0);//declaramos e iniciamos um sensor DHT11

void setup() {   
  Serial.begin(9600);
}

void loop() {
  Serial.print("temperatura: ");
  Serial.print(objct.leitura_temperatura());//imprimimos a leitura de temperatura do sensor
  Serial.print("| umidade: ");
  Serial.println(objct.leitura_umidade());//imprimimos a leitura de umidade do sensor
}
