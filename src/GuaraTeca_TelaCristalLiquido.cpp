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

#include <GuaraTeca_TelaCristalLiquido.h>

TelaCristalLiquido::TelaCristalLiquido(uint8_t RS, uint8_t E,
                                       uint8_t D4, uint8_t D5, uint8_t D6, uint8_t D7,
                                       uint8_t D0, uint8_t D1, uint8_t D2, uint8_t D3
                                       ) : LiquidCrystal(RS, E, D4, D5, D6, D7, D3, D2, D1, D0){
    this->_RS = RS;
    this->_E = E;
    this->_D0 = D0;
    this->_D1 = D1;
    this->_D2 = D2;
    this->_D3 = D3;
    this->_D4 = D4;
    this->_D5 = D5;
    this->_D6 = D6;
    this->_D7 = D7;
}
TelaCristalLiquido::TelaCristalLiquido(uint8_t RS, uint8_t E,
                                       uint8_t D4, uint8_t D5, uint8_t D6, uint8_t D7
                                       ) : LiquidCrystal(RS, E, D4, D5, D6, D7){
    this->_RS = RS;
    this->_E = E;
    this->_D4 = D4;
    this->_D5 = D5;
    this->_D6 = D6;
    this->_D7 = D7;
}

void TelaCristalLiquido::iniciaTelaCristalLiquido(int C, int L){
    LiquidCrystal::begin(C, L);
}
void TelaCristalLiquido::escreveTela(char x[]){
    LiquidCrystal::print(x);
}
void TelaCristalLiquido::escreveTela2(int x){
    LiquidCrystal::print(x,1);
}
void TelaCristalLiquido::limpaTela(){
    LiquidCrystal::clear();
}
void TelaCristalLiquido::vaParaHome(){
    LiquidCrystal::home();
}
void TelaCristalLiquido::vaParaDireita(){
    LiquidCrystal::scrollDisplayRight();
}
void TelaCristalLiquido::vaParaEsquerda(){
    LiquidCrystal::scrollDisplayLeft();
}
void TelaCristalLiquido::posicaoCursor(int C, int L){
    LiquidCrystal::setCursor(C, L);
}
void TelaCristalLiquido::estadoLigado(){
    LiquidCrystal::display();
}
void TelaCristalLiquido::estadoDesligado(){
    LiquidCrystal::noDisplay();
}
void TelaCristalLiquido::pisca(){
    LiquidCrystal::blink();
}
void TelaCristalLiquido::paraPiscar(){
    LiquidCrystal::noBlink();
}
/*void TelaCristalLiquido::desenha(uint8_t n, char nome[15]){
    //LiquidCrystal::createChar(n, nome);
}*/
