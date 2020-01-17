#ifndef IR_H
#define IR_H
#define IRA A0 //A0 do sensor IR esquerda - analógico 
#define IRB A1 //A0 do sensor IR direita - analógico
#define IRAd    26  //D0 do sensor IR esquerda - digital  

#define PRETOA   220
#define PRETOB  220

#define LEDA    6
#define LEDB    5

void setup_ir();

int line(int); 
/*recebe 0 para o IRA ou qualquer outro para IRB e retorna 1 se lê preto ou 0 se lê branco, 
de acordo com a constante definida PRETO.
*/

void led(bool, bool);

int ir_read();

void teste_ir();

#endif