#include <move.h>
#include <Arduino.h>

void setup_move() {
    pinMode(ENA, OUTPUT);
    pinMode(MA1, OUTPUT);
    pinMode(MA2, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(MB1, OUTPUT);
    pinMode(MB2, OUTPUT);
    analogWrite(ENA, 50*PWM);
    analogWrite(ENB, 50*PWM);
}

void frente(){
    digitalWrite(MA1, false);
    digitalWrite(MA2, true);
    digitalWrite(MB1, false);
    digitalWrite(MB2, true);
}

void tras(){
    digitalWrite(MA1, true);
    digitalWrite(MA2, false);
    digitalWrite(MB1, true);
    digitalWrite(MB2, false);
}

void para(){
    digitalWrite(MA1, false);
    digitalWrite(MA2, false);
    digitalWrite(MB1, false);
    digitalWrite(MB2, false);
}

void gira_esquerda(){
    digitalWrite(MA1, true);
    digitalWrite(MA2, false);
    digitalWrite(MB1, false);
    digitalWrite(MB2, true);
}

void gira_direita(){
    digitalWrite(MA1, false);
    digitalWrite(MA2, true);
    digitalWrite(MB1, true);
    digitalWrite(MB2, false);

}

void teste_move(){
    frente();
    delay(3000);
    para();
    delay(1000);
    tras();
    delay(3000);
    para();
    delay(1000);
    gira_esquerda();
    delay(3000);
    para();
    delay(1000);
    gira_direita();
    delay(3000);
    para();
    delay(1000);
}