int outA1 = 2, outA2 = 3, outB1 = 4, outB2 = 5, enA = 6, enB = 7;

int max_pwm = (6*255)/12;

void setup() {
  // put your setup code here, to run once:
  pinMode(outA1, OUTPUT);
  //digitalWrite(outA1, HIGH);
  
  pinMode(outA2, OUTPUT);
  //digitalWrite(outA2, LOW);

  pinMode(outB1, OUTPUT);
  //digitalWrite(outB1, HIGH);

  pinMode(outB2, OUTPUT);
  //digitalWrite(outB2, LOW);    

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
}


void loop() {
  int i;

  digitalWrite(outA1, HIGH);
  digitalWrite(outA2, LOW);
  digitalWrite(outB1, HIGH);
  digitalWrite(outB2, LOW);  
  for(i = 50;i<max_pwm;i++){
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(100);
  }

  delay(5000);

  digitalWrite(outA1, LOW);
  digitalWrite(outA2, HIGH);
  digitalWrite(outB1, LOW);
  digitalWrite(outB2, HIGH);  
  for(i = 50;i<max_pwm;i++){
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(100);
  }
  
}
