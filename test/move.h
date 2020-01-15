#ifndef MOVE_H
#define MOVE_H
#define MA1 22  //motor esquerdo (IN1) - digital
#define MA2 23  //motor esquerdo (IN2) - digital
#define MB1 24  //motor direito (IN3) - digital
#define MB2 25  //motor direito (IN4) - digital
#define ENA 2   //pwm motor esquerdo (ENA) - pwm
#define ENB 3   //pwm motor direito (ENB)- pwm

#define PWM 6/12 //Retificando o valor pwm para ficar no máximo 6V 


void setup_move();

void frente(int); //Recebe inteiro para pwm (0 - 255)
void para();
void tras();
void gira_esquerda();
void gira_direita();
void liga(int, int); //Primeiro argumento 0 para ENA e 1 para ENB, segundo potência do pwm (0 - 255)
void teste_move(); //Função para testar as outras funções de move.h

#endif