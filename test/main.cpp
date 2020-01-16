#include <Arduino.h>
#include <move.h>
#include <ir.h>

bool inicio = false;

void setup() {
  Serial.begin(9600);
  setup_move();
  setup_ir();
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
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
        motor(80,80);
        digitalWrite(6, LOW);
        digitalWrite(5, LOW);
        break;
      case 1://Preto na direita
        //motor(0,0);
        //delay(10);
        motor(100, -85);
        digitalWrite(6, LOW);
        digitalWrite(5, HIGH);
        delay(3);
        break;
      case 2://Preto na esquerda
        //motor(0,0);
        //delay(20);
        motor(-85, 100);
        digitalWrite(6, HIGH);
        digitalWrite(5, LOW);
        delay(3);
        break;
      case 3://Preto nos dois
        motor(140, 140);
        digitalWrite(6, HIGH);
        digitalWrite(5, HIGH);
        break;
      default: //Erroooooooowwwwwww!
        para();
        delay(1000);
        break;
   }
  }
}
