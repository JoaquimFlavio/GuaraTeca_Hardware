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

//Uso do sensor_agua GuaraTeca_Hardware---------------------------------*
//versao: 1.0-----------------------------------------------------------*

#include <GuaraTeca_SensorAgua.h>

SensorAgua hidro;//declaramos um sensor de agua

void setup() {
  hidro.iniciaSensorAgua(A0, 2);//declaramos sensor de agua, temos a opção de receber sinal = (analogico) ou (analogico e digital)
  Serial.begin(9600);
}

void loop() {
  if(hidro.leitura(A0, 2) == true){//le o sinal digital do sensor
     Serial.print("leitura: ");
     Serial.println(hidro.leitura(A0));//imprime leitura analogica    
  }else{
    Serial.println("Sem leitura!!!!");
  }
}
