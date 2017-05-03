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

//Uso do TelaCristalLiquido GuaraTeca_Hardware--------------------------*
//versao: 1.0-----------------------------------------------------------*

#include <GuaraTeca_TelaCristalLiquido.h>

/*Pinos
 * RS = 12
 * E = 11
 * D4 = 5
 * D5 = 4
 * D6 = 3
 * D7 = 2
 */

TelaCristalLiquido objct(12, 11, 5, 4, 3, 2);//declaramos o display LCD

void setup() {   
  objct.iniciaTelaCristalLiquido(20, 2);//iniciamos o display LCD, com 20 colunas e 2 linhas
  objct.vaParaHome();
  objct.escreveTela("ola mundo");
  delay(1000);
  objct.limpaTela();
}

void loop() {}
