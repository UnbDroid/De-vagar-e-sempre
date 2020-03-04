/*------------------------------------------ Gyroscope Functions ---------------------------------------------*/

// Comments:
// Here we have the Turn function and the angular position calculation.

// Usage:
// To read the current angular position just call UpdateGyro, beware that this function shouldn't be called 
// more than once in 20 milli seconds since it time step is 20.
// The Turn function receives the angle disired. Positive turns right and negative turns left.

// Gyro lib
#include "MPU9250/MPU9250.h"

// Iteration step in milli seconds
#define TIME_STEP 20

// Set the turning speed 
#define Turn_Tension 3

// Gets gyro's raw readings (rad/s) and integrates them into angles (rad).
// Angles are also converted from rad to degrees. 
void updateGyro();

// Gyro setup function
void startGyro();

// Prints current angle on serial monitor
void printGyro();
