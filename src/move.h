#ifndef MOVE_H
#define MOVE_H
#define MA1 23  //motor esquerdo (IN1) - digital
#define MA2 25  //motor esquerdo (IN2) - digital
#define MB1 27  //motor direito (IN3) - digital
#define MB2 29  //motor direito (IN4) - digital
#define ENA 3   //pwm motor esquerdo (ENA) - pwm
#define ENB 2   //pwm motor direito (ENB)- pwm

#define PWM 6/12 //Retificando o valor pwm para ficar no máximo 6V 

#define KP 0.02
#define KI 0.1
#define KD 0.1

#define RETO_TIME   50
#define GIRO_TIME   50 //60
#define MEDIO_PWM    120
#define MINIMO_PWM    95
#define TRANCO_PWM    250
#define ERRO_GIRO   5.0

#define LADO 1

unsigned long now,last_update;
int desvia_pot[2];
int err_desvia;

void setup_move();

void frente(int); //Recebe inteiro para pwm (0 - 255)
void segue_reto(int[], int*, float, float); //Move com PID
void para(int);
void tras();
void gira_esquerda();
void gira_direita();
void girar_angulo(float);
void liga(int, int); //Primeiro argumento 0 para ENA e 1 para ENB, segundo potência do pwm (0 - 255)
void motor(int, int, int); //Primeiro argumento -> entrada da potência no M
void desvio();
void teste_move(); //Função para testar as outras funções de move.h
void teste_giro(); //Função para testar as outras funções de move.h

#endif