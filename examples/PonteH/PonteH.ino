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

//Uso da PonteH GuaraTeca_Hardware--------------------------------------*
//versao: 1.0-----------------------------------------------------------*

#include <GuaraTeca_PonteH.h>

PonteH motor;//declaramos um motor

void setup() {
  motor.iniciaPonteH(3,4,10,5,6,11);//preparamos a PonteH para receber os comandos
  motor.controleDeCorrente(10, 255);//definimos a velocidade do motor, na porta 1, como maxima
  motor.controleDeCorrente(11, 255);//definimos a velocidade do motor, na porta 2, como maxima
}

void loop() {
  motor.sentido1(3, 4);//motor 1 gira no sentido 1
  motor.sentido1(5, 6);//motor 2 gira no sentido 1
  delay(1000);
  motor.trava(3, 4);//motor 1 para
  motor.trava(5, 6);//motor 2 para
  delay(1000);
  motor.sentido2(3, 4);//motor 1 gira no sentido 2
  motor.sentido2(5, 6);//motor 2 gira no sentido 2
  delay(1000);
}
