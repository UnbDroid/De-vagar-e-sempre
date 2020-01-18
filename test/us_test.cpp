#include <Arduino.h>
#include "us.h"

unsigned long valUS[2]={0,0};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  setup_us();
}

void loop() {
  // put your main code here, to run repeatedly:
    read_us(valUS);

    Serial.print("Leitura 1 main: ");
    Serial.println(valUS[0]);
    Serial.print("Leitura 2 main: ");
    Serial.println(valUS[1]);
    delay(3000);
  
}