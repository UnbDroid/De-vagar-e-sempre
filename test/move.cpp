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

void para(int t){
    digitalWrite(MA1, false);
    digitalWrite(MA2, false);
    digitalWrite(MB1, false);
    digitalWrite(MB2, false);
    delay(t);
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

void motor(int a, int b,  int t){
    if (a > 0) {
        analogWrite(ENA, a*PWM);
        digitalWrite(MA1, false);
        digitalWrite(MA2, true);
    } else if (a < 0 ){
        analogWrite(ENA, -a*PWM);
        digitalWrite(MA1, true);
        digitalWrite(MA2, false);
    } else {
        analogWrite(ENA, a*PWM);
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
        analogWrite(ENB, b*PWM);
        digitalWrite(MB1, true);
        digitalWrite(MB2, true);
    }
    delay (t);
}



void liga(int a, int pot){ 
    if (a){
        analogWrite(ENA, 0*PWM);
        analogWrite(ENB, pot*PWM);

    } else {
        analogWrite(ENB, 0*PWM);
        analogWrite(ENA, pot*PWM);

    motor(250, 250, 60);
    }
        digitalWrite(MA1, false);
        digitalWrite(MA2, true);
        digitalWrite(MB1, false);
        digitalWrite(MB2, true);

}

void teste_move(){

  motor(250, 250, RETO_TIME); 
  motor(80,80, 1000);
  para(200); 

  motor(-250, -250, RETO_TIME);
  motor(-80, -80, 1000);
  para(2000);

  motor(-250, 250, GIRO_TIME);
  motor(-100, 100, 1000);
  para(300);

  motor(250, -250, GIRO_TIME);
  motor(100,-100, 1000);
  para(2000);
}