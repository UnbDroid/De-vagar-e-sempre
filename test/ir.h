#ifndef IR_H
#define IR_H
#define IRA A0 //A0 do sensor IR esquerda - analógico 
#define IRB A1 //A0 do sensor IR direita - analógico
#define IRAd    26  //D0 do sensor IR esquerda - digital  

#define PRETOA   500
#define PRETOB  180

void setup_ir();

int line(int); 
/*recebe 0 para o IRA ou qualquer outro para IRB e retorna 1 se lê preto ou 0 se lê branco, 
de acordo com a constante definida PRETO.
*/

int ir_read();

void teste_ir();

#endif