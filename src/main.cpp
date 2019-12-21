#include <Arduino.h>
#include <move.h>
#include <ir.h>

void setup() {
  Serial.begin(9600);
  //setup_move();
  setup_ir();
}

void loop() {
  //teste_move();
  teste_ir();
}
