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

//Uso do sensor_Cor GuaraTeca_Hardware----------------------------------*
//versao: 1.0-----------------------------------------------------------*

#include <GuaraTeca_SensorCor.h>

SensorCor color;//declaramos um sensor de cor

/*Portas
 * out = 10
 * S0 = 8
 * S1 = 9
 * S2 = 12
 * S3 = 11
 */

/*Frequecia de operação
 * 1 => 2%
 * 2 => 20%
 * 3 => 100%
 * 4 => 0%
 */

void setup() {   
  color.iniciaSensorCor(10, 8, 9, 12, 11);//declaramos sensor de cor
  Serial.begin(9600);
  color.frequencia(3);//definimos a frequencia de operação em 100%
}

void loop() {
  Serial.print("Filtro Vermelho: ");
  color.filtroVermelho();//ativamos o filtro de vermelho
  Serial.print(color.leitura());//imprimimos a leitura

  Serial.print("| Filtro Verde: ");
  color.filtroVerde();//ativamos o filtro de verde
  Serial.print(color.leitura());//imprimimos a leitura

  Serial.print("| Filtro Azul: ");
  color.filtroAzul();//ativamos o filtro de azul
  Serial.print(color.leitura());//imprimimos a leitura

  Serial.print("| Sem Filtro: ");
  color.filtroNulo();//desativamos todos os filtros
  Serial.println(color.leitura());//imprimimos a leitura
}
