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
#include <GuaraTeca_Buzzer.h>

Buzzer::Buzzer(){
    Serial.println("");
}

void Buzzer::iniciaBuzzer(unsigned char pino){
    pinMode(pino, OUTPUT);
}

void Buzzer::beepSimples(unsigned char pino, int tempo){
    digitalWrite(pino, HIGH);
    if (tempo > 0){
        delay(tempo);
        digitalWrite(pino, LOW);
    }
}

void Buzzer::beep(unsigned char speakerPin, int frequencyInHertz, long timeInMilliseconds){
    //digitalWrite(ledPin, HIGH);
    //use led to visualize the notes being played

    int x;
    long delayAmount = (long)(1000000/frequencyInHertz);
    long loopTime = (long)((timeInMilliseconds*1000)/(delayAmount*2));
    for (x=0;x<loopTime;x++){
        digitalWrite(speakerPin,HIGH);
        delayMicroseconds(delayAmount);
        digitalWrite(speakerPin,LOW);
        delayMicroseconds(delayAmount);
    }
    // digitalWrite(ledPin, LOW);
    //set led back to low
    delay(20);
    //a little delay to make all notes sound separate

}

void Buzzer::marcha(unsigned char pino){
    c = 261;
    d = 294;
    e = 329;
    f = 349;
    g = 391;
    gS = 415;
    a = 440;
    aS = 455;
    b = 466;
    cH = 523;
    cSH = 554;
    dH = 587;
    dSH = 622;
    eH = 659;
    fH = 698;
    fSH = 740;
    gH = 784;
    gSH = 830;
    aH = 880;

    beep(pino, a, 500);
    beep(pino, a, 500);
    beep(pino, a, 500);
    beep(pino, f, 350);
    beep(pino, cH, 150);

    beep(pino, a, 500);
    beep(pino, f, 350);
    beep(pino, cH, 150);
    beep(pino, a, 1000);

    beep(pino, eH, 500);
    beep(pino, eH, 500);
    beep(pino, eH, 500);
    beep(pino, fH, 350);
    beep(pino, cH, 150);

    beep(pino, gS, 500);
    beep(pino, f, 350);
    beep(pino, cH, 150);
    beep(pino, a, 1000);

    beep(pino, aH, 500);
    beep(pino, a, 350);
    beep(pino, a, 150);
    beep(pino, aH, 500);
    beep(pino, gSH, 250);
    beep(pino, gH, 250);

    beep(pino, fSH, 125);
    beep(pino, fH, 125);
    beep(pino, fSH, 250);

    delay(250);

    beep(pino, aS, 250);
    beep(pino, dSH, 500);
    beep(pino, dH, 250);
    beep(pino, cSH, 250);

    beep(pino, cH, 125);
    beep(pino, b, 125);
    beep(pino, cH, 250);
    delay(250);
    beep(pino, f, 125);
    beep(pino, gS, 500);
    beep(pino, f, 375);
    beep(pino, a, 125);

    beep(pino, cH, 500);
    beep(pino, a, 375);
    beep(pino, cH, 125);
    beep(pino, eH, 1000);

    beep(pino, aH, 500);
    beep(pino, a, 350);
    beep(pino, a, 150);
    beep(pino, aH, 500);
    beep(pino, gSH, 250);
    beep(pino, gH, 250);

    beep(pino, fSH, 125);
    beep(pino, fH, 125);
    beep(pino, fSH, 250);
    delay(250);
    beep(pino, aS, 250);
    beep(pino, dSH, 500);
    beep(pino, dH, 250);
    beep(pino, cSH, 250);
    //repeat... repeat

    beep(pino, cH, 125);
    beep(pino, b, 125);
    beep(pino, cH, 250);
    delay(250);
    beep(pino, f, 250);
    beep(pino, gS, 500);
    beep(pino, f, 375);
    beep(pino, cH, 125);

    beep(pino, a, 500);
    beep(pino, f, 375);
    beep(pino, c, 125);
    beep(pino, a, 1000);
}

int melodia[] = {660,660,660,510,660,770,380,510,380,320,440,480,450,430,380,660,760,860,700,760,660,520,580,480,510,380,320,440,480,450,430,380,660,760,860,700,760,660,520,580,480,500,760,720,680,620,650,380,430,500,430,500,570,500,760,720,680,620,650,1020,1020,1020,380,500,760,720,680,620,650,380,430,500,430,500,570,585,550,500,380,500,500,500,500,760,720,680,620,650,380,430,500,430,500,570,500,760,720,680,620,650,1020,1020,1020,380,500,760,720,680,620,650,380,430,500,430,500,570,585,550,500,380,500,500,500,500,500,500,500,580,660,500,430,380,500,500,500,500,580,660,870,760,500,500,500,500,580,660,500,430,380,660,660,660,510,660,770,380};
int duracaodasnotas[] = {100,100,100,100,100,100,100,100,100,100,100,80,100,100,100,80,50,100,80,50,80,80,80,80,100,100,100,100,80,100,100,100,80,50,100,80,50,80,80,80,80,100,100,100,100,150,150,100,100,100,100,100,100,100,100,100,100,150,200,80,80,80,100,100,100,100,100,150,150,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,150,150,100,100,100,100,100,100,100,100,100,100,150,200,80,80,80,100,100,100,100,100,150,150,100,100,100,100,100,100,100,100,100,100,100,100,100,60,80,60,80,80,80,80,80,80,60,80,60,80,80,80,80,80,60,80,60,80,80,80,80,80,80,100,100,100,100,100,100,100};

void Buzzer::mario(unsigned char pino){
    //for para tocar as 156 notas começando no 0 ate 156 ++ incrementado
    for (int nota = 0; nota < 156; nota++) {
        int duracaodanota = duracaodasnotas[nota];
        tone(pino, melodia[nota],duracaodanota);
        //pausa depois das notas
        int pausadepoisdasnotas[] = {150,300,300,100,300,550,575,450,400,500,300,330,150,300,200,200,150,300,150,350,300,150,150,500,450,400,500,300,330,150,300,200,200,150,300,150,350,300,150,150,500,300,100,150,150,300,300,150,150,300,150,100,220,300,100,150,150,300,300,300,150,300,300,300,100,150,150,300,300,150,150,300,150,100,420,450,420,360,300,300,150,300,300,100,150,150,300,300,150,150,300,150,100,220,300,100,150,150,300,300,300,150,300,300,300,100,150,150,300,300,150,150,300,150,100,420,450,420,360,300,300,150,300,150,300,350,150,350,150,300,150,600,150,300,350,150,150,550,325,600,150,300,350,150,350,150,300,150,600,150,300,300,100,300,550,575};
        delay(pausadepoisdasnotas[nota]);
    }
    noTone(pino);
}
