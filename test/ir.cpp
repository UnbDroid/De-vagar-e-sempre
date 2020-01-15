#include <ir.h>
#include <Arduino.h>

void setup_ir() {
    pinMode(IRA, INPUT);
}

int line(int a){
    if(a)
        return (PRETOB <= analogRead(IRB));
    return (PRETOA <= analogRead(IRA));
}
int ir_read(){
    return 2*line(0) + line(1);
}
void teste_ir(){
    for(int i = 0; i <10; i++){
        Serial.println(i);
        line(0)?Serial.println("IRA: PRETO."):Serial.println("IRA: BRANCO.");
        line(1)?Serial.println("IRB: PRETO."):Serial.println("IRB: BRANCO.");
        Serial.print("\n\n1:");
        Serial.print(analogRead(IRA));
        Serial.print("    2:");
        Serial.println(analogRead(IRB));
        Serial.println(ir_read());
        delay(505);
    }
}