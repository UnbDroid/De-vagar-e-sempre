/*------------------------------------------ Gyroscope Functions ---------------------------------------------*/

// Comments:
// Here we have the Turn function and the angular position calculation.

// Usage:
// To read the current angular position just call UpdateGyro, beware that this function shouldn't be called 
// more than once in 20 milli seconds since it time step is 20.
// The Turn function receives the angle disired. Positive turns right and negative turns left.

// Gyro lib
#include "gyro.h"

void setup() {
  Serial.begin(9600);
  while(!Serial);
  startGyro();
}

void loop() {

  unsigned long now,last_update = 0;

  while(1){
    now = millis();
    if(now - last_update > 20){
      updateGyro();
      printGyro();
      last_update = now;
    }
  }
}

