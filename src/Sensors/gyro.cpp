#include "gyro.h"

// An MPU9250 object with the MPU-9250 sensor on I2C bus 0 with address 0x68
MPU9250 * gyro = new MPU9250(Wire, 0x68);

int status;
float degreeY = 0;

// Gets gyro's raw readings (rad/s) and integrates them into angles (rad).
// Angles are also converted from rad to degrees. 
void updateGyro() {
  gyro->readSensor();
  degreeY += (gyro->getGyroY_rads() * TIME_STEP * 180) / (1000 * PI);
  
  // Corrections
  if(degreeY < 0)
    degreeY += 360;
  else if (degreeY > 360)
    degreeY -= 360;
}

// Gyro setup function
void startGyro() {
  status = gyro->begin();
}

// Prints current angle on serial monitor
void printGyro() {
    updateGyro();
    Serial.print("angle in Y: ");
    Serial.print(degreeY);
}