#include <Arduino.h>
#include <move.h>
#include <ir.h>

bool inicio = false;

void setup() {
  Serial.begin(9600);
  setup_move();
  setup_ir();
}


void loop() {
  //teste_move();
  /*frente();
  delay(3000);
  para();
  delay(3000);*/
  //teste_ir();
  if (!inicio) {
    delay(1000);
    frente(250);
    delay(70);
    inicio = true;
  } else {
    int a = ir_read();
    Serial.println(a);
    switch (a) {
      case 0://Branco nos dois
        frente(75);
        break;
      case 1://Preto na direita
        liga(0, 75);
        break;
      case 2://Preto na esquerda
        liga(1, 75);
        break;
      case 3://Preto nos dois
        frente(100);
        break;
      default: //Erroooooooowwwwwww!
        para();
        delay(1000);
        break;
   }
  }
}
