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

//Uso do sensor_Ultrassonico GuaraTeca_Hardware-------------------------*
//versao: 1.0-----------------------------------------------------------*

#include <GuaraTeca_SensorUltrassonico.h>

SensorUltrassonico objct;//declaramos o sensor ultrassonico

void setup() {   
  Serial.begin(9600);
  objct.iniciaSensorUltrassonico(A0, A1);//iniciamos o sensor de refletancia na porta A0(Trig pin) e A1(Echo pin)
}

void loop() {
  Serial.print("Distancia: ");
  Serial.println(objct.leitura(A0, A1));//imprimimos a leitura do sensor na porta A0
}
