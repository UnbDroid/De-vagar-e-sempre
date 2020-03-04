#include <Arduino.h>
#include <cor.h>

void setup_cor(){
  pinMode(TCS_S2, OUTPUT);
  pinMode(TCS_S3, OUTPUT);
  pinMode(TCS_OUT, INPUT);
  pinMode(led_G, OUTPUT);
  pinMode(led_R, OUTPUT);
  pinMode(led_B, OUTPUT);
  Serial.begin(9600);
}

int mediana(int *medidas) {
  float maximo = 0;
  int indice;
  for (int i = 0; i < 5 ; ++i)  {
    for (int j = 0; j < MEDIANA - i ; ++j) {
      if(medidas[j] > maximo) {
        maximo = medidas[j];
        indice = j;
      }
    }
    if(indice != MEDIANA - 1) {
      maximo = medidas[MEDIANA - 1];
      medidas[MEDIANA - i] = medidas[indice];
      medidas[indice] = maximo;
    }
    maximo = 0;
  }
  return medidas[3];
}
void le_sensor(int tcs){
  //Vermelho
  digitalWrite(TCS_S2,LOW);
  digitalWrite(TCS_S3,LOW);
  delay(100);
  for(int i=1; i<MEDIANA; i++){
    medidas[i] = pulseIn (TCS_OUT, digitalRead(TCS_OUT) == HIGH ? LOW : HIGH);
  }
  cores[0] = (ALPHA)*cores[0] + (1 - ALPHA)*mediana(medidas);

  //Azul
  digitalWrite(TCS_S3,HIGH);
  delay(100);
  for (int i = 0; i < MEDIANA; ++i) {
    medidas[i] = pulseIn(TCS_OUT,digitalRead(TCS_OUT) == HIGH ? LOW : HIGH);
  }
  cores[2] = (ALPHA)*cores[2] + (1 - ALPHA)*mediana(medidas);

  //Verde
  digitalWrite(TCS_S2,HIGH);
  delay(100);
  for (int i = 0; i < MEDIANA ; ++i) {
    medidas[i] = pulseIn(TCS_OUT,digitalRead(TCS_OUT) == HIGH ? LOW : HIGH);
  }
  cores[1] = (ALPHA)*cores[1] + (1 - ALPHA)*mediana(medidas);
  cores[0] = 8000/ cores[0];
  cores[1] = 8000/ cores[1];
  cores[2] = 8000/ cores[2];

}

int media_dp () {
  double m = (cores[0] + cores[1] + cores[2])/3;
  double dp = (sqrt(pow(cores[0] - m, 2) + pow (cores[1] - m, 2) + pow(cores[2] - m, 2)))/3;
  //Início teste
  Serial.print("\t m = ");
  Serial.print(m);
  Serial.print("\t dp = ");
  Serial.println(dp);
  //Fim teste  
  if(dp <= DP_BRANCO && m >= M_BRANCO){
    return BRANCO;
  } else if(dp <= DP_PRETO && m <= M_PRETO){
    return PRETO;
  } else{
    return OUTRA_COR;
  }
}

void teste_cor(){
  le_sensor(TCS_OUT);
  Serial.print("R = ");
  Serial.println(cores[0]);
  Serial.print("G = ");
  Serial.println(cores[1]);
  Serial.print("B = ");
  Serial.println(cores[2]);
  switch(media_dp()) {
    case 0:
        digitalWrite(led_B, LOW);
        digitalWrite(led_G, LOW);
        digitalWrite(led_R, HIGH);
        break;
    case 1:
        digitalWrite(led_B, HIGH);
        digitalWrite(led_G, HIGH);
        digitalWrite(led_R, HIGH);
        break;
    case 2:
        digitalWrite(led_B, LOW);
        digitalWrite(led_G, HIGH);
        digitalWrite(led_R, LOW);
        break;
  }
}
