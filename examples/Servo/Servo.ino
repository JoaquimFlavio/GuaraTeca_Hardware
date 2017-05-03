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

//Uso do Servo GuaraTeca_Hardware---------------------------------------*
//versao: 1.0-----------------------------------------------------------*

#include <GuaraTeca_Servo.h>

Servo objct;//declaramos o Servo motor

void setup() {   
  objct.iniciaServo(A0);//iniciamos o servo motor na porta A0
}

void loop() {
  objct.vaPara(A0, 0);//move o eixo do motor na porta A0, para a posição 0 graus
  delay(200);
  objct.vaPara(A0, 45);//move o eixo do motor na porta A0, para a posição 45 graus
  delay(200);
  objct.vaPara(A0, 90);//move o eixo do motor na porta A0, para a posição 90 graus
  delay(200);
  objct.vaPara(A0, 45);//move o eixo do motor na porta A0, para a posição 45 graus
  delay(200);
}
