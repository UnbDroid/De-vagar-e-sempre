#include <move.h>
#include <Arduino.h>

void setup_move() {
    pinMode(ENA, OUTPUT);
    pinMode(MA1, OUTPUT);
    pinMode(MA2, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(MB1, OUTPUT);
    pinMode(MB2, OUTPUT);
    analogWrite(ENA, 200*PWM);
    analogWrite(ENB, 200*PWM);
}

void frente(int pot){

    analogWrite(ENA, pot*PWM);
    analogWrite(ENB, pot*PWM);
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

void motor(int a, int b){
    if (a > 0) {
        analogWrite(ENA, a*PWM);
        digitalWrite(MA1, false);
        digitalWrite(MA2, true);
    } else if (a < 0 ){
        analogWrite(ENA, -a*PWM);
        digitalWrite(MA1, true);
        digitalWrite(MA2, false);
    } else {
        digitalWrite(MA1, true);
        digitalWrite(MA2, true);
        

    }
    if (b > 0) {
        analogWrite(ENB, b*PWM);
        digitalWrite(MB1, false);
        digitalWrite(MB2, true);
    } else if (b < 0 ){
        analogWrite(ENB, -b*PWM);
        digitalWrite(MB1, true);
        digitalWrite(MB2, false);
    } else {
        digitalWrite(MB1, true);
        digitalWrite(MB2, true);
    }
}

void liga(int a, int pot){ 
    if (a){
        analogWrite(ENA, 0*PWM);
        analogWrite(ENB, pot*PWM);

    } else {
        analogWrite(ENB, 0*PWM);
        analogWrite(ENA, pot*PWM);

    }
        digitalWrite(MA1, false);
        digitalWrite(MA2, true);
        digitalWrite(MB1, false);
        digitalWrite(MB2, true);

}

void teste_move(){
    frente(210);
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