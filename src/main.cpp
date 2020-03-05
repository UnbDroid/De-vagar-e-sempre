#include <Arduino.h>
#include <move.h>
#include <Sensors/ir.h>
#include <Sensors/us.h>
#include <Sensors/gyro.h>
#include <Sensors/cor.h>

//bool inicio = false;
static int prev_a, a = 1, cont = 5;
unsigned long val_us[2];
int cont_b_b;
int controle[2];
int err_controle;
float last_angle;
//int cor_vista;

void setup()
{
  Serial.begin(9600);
  setup_move();
  setup_ir();
  setup_cor();
  para(1000);
  setup_us();
  startGyro();
  cont_b_b = 0;
  controle[0] = MEDIO_PWM;
  controle[1] = MEDIO_PWM;
  err_controle = 0;
}

void loop() {
  //cor_vista = cor();
  cont--;
  if(!cont) {
    read_us(val_us);
    Serial.print("Leitura: ");
    Serial.print(val_us[0]);
    Serial.print("lixo: ");
    Serial.println(val_us[1]);
    if(val_us[0] <= 20 && val_us[0] != 0){
      para(2000);
      do {
        read_us(val_us);
        if( val_us[0] > 18) {
          motor(250, 250, RETO_TIME/1.5);
          motor(115, 85,10);
          para(300);
        } else if (val_us[0] < 17) {
          motor(-250, -250, RETO_TIME/1.5);
          motor(-115, -85, 10);
          para(300);
        }

      } while(val_us[0] < 17 || val_us[0] > 18 );
      desvio();
    }
    cont = 5;
  }
  prev_a = a;
  a = ir_read();
  last_angle = getGyro();
  Serial.println(a);
  if(cont_b_b < 5){
    switch (a) {
      case 0: //Branco nos dois
        ++cont_b_b;
        led(0, 0);
        //if (prev_a != 0) 
        motor(270, 250, RETO_TIME);
        motor(115, 85, 10);
        para(300);
        break;
      case 1: //Preto na direita
        cont_b_b = 0;
        led(0, 1);
        para(300);
        //if(ir_read() != 1) break;
        motor(250, -250, GIRO_TIME);
        motor(140,-90, GIRO_TIME);
        para(200);
        break;
      case 2: //Preto na esquerda
        cont_b_b = 0;
        led(1, 0);
        para(200);
        //if(ir_read() != 2) break;
        motor(-250, 250, GIRO_TIME);
        motor(-90,140,GIRO_TIME);
        para(200);
        break;
      case 3: //Preto nos dois
        cont_b_b = 0;
        led(1, 1);
        if(prev_a == 1) {


        motor(250, -250, GIRO_TIME);
        motor(140,-90, GIRO_TIME);
        para(200);
          
        } else if(prev_a == 2) {

        motor(-250, 250, GIRO_TIME);
        motor(-90,140,GIRO_TIME);
        para(200);

        } else {
          motor(-260, -200, RETO_TIME);
          motor(-150,-80,10);
          para(300);
        }
        break;
      default:
        motor(0, 0, 3000);
        break;
    }
  }
  else{
    para(100);
    a = ir_read();
    //cor_vista = cor();
    motor(TRANCO_PWM, TRANCO_PWM, 5);
    //while(a == 0 || cor_vista != OUTRA_COR){
    while(a == 0){
      segue_reto(controle, &err_controle, 0, last_angle);
      a = ir_read();
      //cor_vista = cor();
      read_us(val_us);
      if(val_us[0] <= 20 && val_us[0] != 0){
        para(20);
        break;
      }
    }
    cont_b_b = 0;
  }
}
/*
void loop () {
  teste_cor();
}*/
