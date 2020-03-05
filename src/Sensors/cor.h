#ifndef COR_H
#define COR_H

#define TCS_OUT 5 //4 e 5
#define TCS_S2 43 //37 e 43
#define TCS_S3 41 //39 e 41
#define led_R 7
#define led_G 8
#define led_B 9

#define MEDIANA 7
#define ALPHA 0.01
#define DP_BRANCO 15
#define M_BRANCO 250
#define M_PRETO 170
#define DP_PRETO 10
#define BRANCO 1
#define PRETO 2
#define OUTRA_COR 0

void setup_cor();

int mediana();

void le_sensor(int); 
/*Atualiza os valores de cores[3], onde cores[0] = R, cores[1] = G e cores[2] = B
Recebe a porta OUT do sensor TCS230*/

int media_dp(); 
//Retorna 1 se é preto ou branco e 0 se é outra cor

void cor(); /*Acende o led RGB de acordo com:
    azul para PRETO
    todas as cores para BRANCO
    vermelho para OUTRA COR*/

void teste_cor();
/*Mostra os valores lidos em RGB

    ***RODAR SEMPRE PARA CALIBRAÇÃO***

    */
#endif
