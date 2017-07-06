## Sobre a GuaraTeca_Hardware

ola A GuaraTeca_Hardware é uma sub-biblioteca da biblioteca [Guarateca](https://github.com/JoaquimFlavio/GuaraTeca), focada na programação de estruturas eletronicas e roboticas em nivel mediano. Atraves da utilização de funçoes simples e em portugues essa biblioteca permite um maior aproveitamento do hardware do Arduino em contraposição à uma experiência de programação em alto nivel.

## Instalação

1. **Instalação**
    - Primeiro baixe a biblioteca clicando [aqui](https://codeload.github.com/JoaquimFlavio/GuaraTeca_Hardware/zip/1.2.0)
    - Abra a sua IDE do Arduino, clique em ```Sketch > Incluir Biblioteca > Adicionar biblioteca .ZIP```
    - Procure a biblioteca GuaraTeca_Hardware baixada em arquivo .ZIP em sua pasta de downloads
    - Pronto, agora a sua biblioteca está instalada e pronta para ser utilizada!
    
## Exemplo de uso

```c++
#define funcao Hardware
#include <GuaraTeca.h>

#define porta 1

MotorShield robo;

void setup() {
  robo.iniciaMotorShield();
  robo.controleDeCorrente(1, 255);
}

void loop() {
  robo.sentido1(porta);
  delay(150);
  robo.sentido2(porta);
  delay(150);
  robo.trava(porta);
  delay(150);
}
```

## Aprendendo

Na [documentação oficial da GuaraTeca](http://guarabots.wordpress.com/guarateca) você encontrará tudo o que precisa para dominar a biblioteca.

## Suporte

Caso encontre falhas ou tenha sugestões, não exite em nos contatar em [guarabots@gmail.com](mailto:guarabots@gmail.com?Subject=GuaraTeca) ou [joaquimflavio.quirino@yahoo.com.br](mailto:joaquimflavio.quirino@yahoo.com.br?Subject=GuaraTeca).

## Licença

A GuaraTeca é licenciada sob a [Licença Pública Geral GNU GPL](https://www.gnu.org/licenses/gpl-3.0.html)
