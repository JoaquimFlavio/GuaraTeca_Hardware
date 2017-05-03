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

//Uso da MotorShield GuaraTeca_Hardware---------------------------------*
//versao: 1.0-----------------------------------------------------------*

#include <GuaraTeca_MotorShield.h>

MotorShield motor;//declaramos um motor

void setup() {
  motor.iniciaMotorShield();//preparamos a motorShield para receber os comandos
  motor.controleDeCorrente(1, 255);//definimos a velocidade do motor, na porta 1, como maxima
}

void loop() {
  motor.sentido1(1);//motor gira no sentido 1
  delay(1000);
  motor.trava(1);//motor para
  delay(1000);
  motor.sentido2(1);//motor gira no sentido 2
  delay(1000);
}
