#include <ir.h>
#include <Arduino.h>

void setup_ir() {
    pinMode(IRA, INPUT);
}

int line(int a){
    if(a)
        return (PRETO <= analogRead(IRB));
    return (PRETO <= analogRead(IRA));
}

void teste_ir(){
    for(int i = 0; i <10; i++){
        Serial.println(i);
        line(0)?Serial.println("IRA: PRETO."):Serial.println("IRA: BRANCO.");
        line(1)?Serial.println("IRB: PRETO."):Serial.println("IRB: BRANCO.\n");
        delay(500);
    }
}