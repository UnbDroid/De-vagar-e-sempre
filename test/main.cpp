#include <Arduino.h>
#include <move.h>
#include <ir.h>

bool inicio = false;
static int prev_a, a = 1;

void setup()
{
  Serial.begin(9600);
  setup_move();
  setup_ir();
  para(1000);
}

void loop() {
  prev_a = a;
  a = ir_read();
  Serial.println(a);
  switch (a) {
    case 0: //Branco nos dois
      led(0, 0);
      //if (prev_a != 0) 
      motor(260, 250, RETO_TIME);
      motor(110, 85, 10);
      para(300);
      break;
    case 1: //Preto na direita
      led(0, 1);
      para(300);
      //if(ir_read() != 1) break;
      motor(250, -250, GIRO_TIME);
      motor(140,-90, GIRO_TIME);
      para(200);
      break;
    case 2: //Preto na esquerda
      led(1, 0);
      para(300);
      //if(ir_read() != 2) break;
      motor(-250, 250, GIRO_TIME);
      motor(-90,140,GIRO_TIME);
      para(200);
      break;
    case 3: //Preto nos dois
      led(1, 1);
      //para(1000);
      break;
    default:
      motor(0, 0, 3000);
      break;
  }

}
