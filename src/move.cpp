#include <move.h>
#include <Arduino.h>
#include <Sensors/ir.h>
#include <Sensors/gyro.h>

void setup_move() {
    pinMode(ENA, OUTPUT);
    pinMode(MA1, OUTPUT);
    pinMode(MA2, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(MB1, OUTPUT);
    pinMode(MB2, OUTPUT);
    analogWrite(ENA, 200*PWM);
    analogWrite(ENB, 200*PWM);
    now= 0;
    last_update = 0;
    desvia_pot[0] = MEDIO_PWM;
    desvia_pot[1] = MEDIO_PWM;
    err_desvia = 0;
}

void frente(int pot){

    analogWrite(ENA, pot*PWM);
    analogWrite(ENB, pot*PWM);
    digitalWrite(MA1, false);
    digitalWrite(MA2, true);
    digitalWrite(MB1, false);
    digitalWrite(MB2, true);
}

void segue_reto(int pot[] , int *err, float delta, float angulo){
    *err = angulo - getGyro();
    Serial.println(*err);

    pot[0] += *err * KP;
    pot[1] -= *err * KP;

    if(pot[0] < MINIMO_PWM) pot[0] = MINIMO_PWM;
    if(pot[1] < MINIMO_PWM) pot[1] = MINIMO_PWM;
    if(pot[0] > 250) pot[0] = 230;
    if(pot[1] > 250) pot[1] = 230;

    motor(pot[0], pot[1], 0);
}

void tras(){
    digitalWrite(MA1, true);
    digitalWrite(MA2, false);
    digitalWrite(MB1, true);
    digitalWrite(MB2, false);
}

void para(int t){
    digitalWrite(MA1, true);
    digitalWrite(MA2, true);
    digitalWrite(MB1, true);
    digitalWrite(MB2, true);
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

void girar_angulo(float angle){
    float ang_anterior = getGyro(), ang_atual;
    int mult = 1;
    float offset = 0;

    if(angle < 0)
        mult = -1;

    if(ang_anterior + angle < 0){
        offset = 360;
    }

    if(ang_anterior + angle > 360){
        offset = - 360;
    }

    motor(- TRANCO_PWM * mult, TRANCO_PWM * mult, RETO_TIME);
    motor(- MEDIO_PWM * mult, MEDIO_PWM * mult, 10);
    ang_atual = getGyro();
    if(mult > 0){
        while (ang_atual  < angle + ang_anterior){
            delay(20);
            printGyro();
            ang_atual = getGyro();
        }
    }
    else{
        while (ang_atual  > angle + ang_anterior){
            delay(20);
            printGyro();
            ang_atual = getGyro();
        }
    }
    para(100);
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

void desvio() {

    if(!LADO){
        motor(-250,250,GIRO_TIME);
        motor(-100,100,600);
        para(300);

        motor(250, 250, RETO_TIME); 
        motor(80,80, 1500);
        para(200);
        
        motor(250, -250, GIRO_TIME);
        motor(100,-100, 600);
        para(300);

        motor(250, 250, RETO_TIME); 
        motor(80,80, 1500);
        para(200);

        
        motor(250, -250, GIRO_TIME);
        motor(100,-100, 500); //1000                l
        para(300);


        motor(260, 250, RETO_TIME);
        motor(110, 85, 250);
        para(150);

        while(ir_read() != 2) {
            motor(260, 250, RETO_TIME);
            motor(110, 85, 10);
            para(150);

        }
        
    } else {
        girar_angulo(90);

        now = millis();
        float at_angle = getGyro();
        motor(TRANCO_PWM, TRANCO_PWM, 5);
        while(now - last_update > 1600){
            updateGyro();
            segue_reto(&desvia_pot, &err_desvia, 0, at_angle);
            last_update = now;
        }
        desvia_pot[0] = MEDIO_PWM;
        desvia_pot[1] = MEDIO_PWM;
        err_desvia = 0;
        
        girar_angulo(-90);

        now = millis();
        at_angle = getGyro();
        motor(TRANCO_PWM, TRANCO_PWM, 5);
        while(now - last_update > 1500){
            updateGyro();
            segue_reto(&desvia_pot, &err_desvia, 0, at_angle);
            last_update = now;
        }
        desvia_pot[0] = MEDIO_PWM;
        desvia_pot[1] = MEDIO_PWM;
        err_desvia = 0;
 
        girar_angulo(-90);

        at_angle = getGyro();
        motor(TRANCO_PWM, TRANCO_PWM, 5);
        while(ir_read() != 1 && ir_read() != 3) {
            updateGyro();
            segue_reto(&desvia_pot, &err_desvia, 0, at_angle);
            para(150);
        }
        desvia_pot[0] = MEDIO_PWM;
        desvia_pot[1] = MEDIO_PWM;
        err_desvia = 0;
        while (ir_read() != 2)
        { // Não está vendo o da esquerda
            /* code */
            motor(250, -250, GIRO_TIME);
            motor(100,-100, 200);
            para(150);
        }
        /*while(ir_read() != 2 && ir_read() != ) {

        }*/

    }

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

void teste_giro(){
    girar_angulo(90);
    delay(1000);
    girar_angulo(-90);
    delay(1000);
    girar_angulo(-90);
    delay(1000);
    girar_angulo(90);
    delay(1000);
    girar_angulo(180);
    delay(1000);
    girar_angulo(-180);
    delay(1000);
}