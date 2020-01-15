#ifndef US_H
#define US_H

//This code was based on US-Trekking, avaiable on https://github.com/UnbDroid/RoboTrekking-2019/blob/master/Arduino.zip

#include <NewPing.h>

#define SONAR_NUM 2 
#define MAX_DISTANCE 200 // Maximum distance (in cm) to ping.

#define US1_ECHO A2 // us central (ECHO) - analógico
#define US1_TRIG A3 // us central (TRIG) - analógico
#define US2_ECHO A4 // us lateral (ECHO) - analógico
#define US2_TRIG A5 // us lateral (TRIG) - analógico

#ifdef ALFA
float low_pass_filter(float last_val, float new_val);
#endif

#ifdef ALFA
uint8_t value_per_us(float value);
#else
uint8_t value_per_us(unsigned long value);
#endif

#ifdef ALFA
uint8_t mask(float* filtered_us);
#else
uint8_t mask(unsigned long* readings_us);
#endif


void setup_us();
byte read_us(); //WARNING: TO GUARANTEE BEST RESULTS,  29ms should be the shortest delay between pings (keep the delay inside the loop)
void teste_us();

#endif