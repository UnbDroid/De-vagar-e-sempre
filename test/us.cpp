#include <us.h>
#include <Arduino.h>

uint8_t us_byte;

NewPing sonar[SONAR_NUM] = {   
    NewPing(US1_TRIG, US1_ECHO, MAX_DISTANCE), 
    NewPing(US2_TRIG, US2_ECHO, MAX_DISTANCE),
};

#ifdef ALFA
float low_pass_filter(float last_val, float new_val)
{
  return ((ALFA)*last_val + (1.0-ALFA)*new_val);
}
#endif

void setup_us() {
  us_byte = 0x00;
}

#ifdef ALFA
uint8_t value_per_us(float value)
#else
uint8_t value_per_us(unsigned long value)
#endif
{
    if (value<50.0 && value >1.0)
        return 0x00;
    else if (value>50.0 && value <100.0)
        return 0x01;
    else if (value>100.0 && value<150.0)
        return 0x02;
    else
        return 0x03;
}

#ifdef ALFA
uint8_t mask(float* filtered_us)
#else
uint8_t mask(unsigned long* readings_us)
#endif
{
    uint8_t aux = 0x00;
    us_byte = 0x00;
    for (int8_t i = 3; i >= 0 ; i--)
    {
        #ifdef ALFA
        aux = value_per_us(filtered_us[i]);
        #else
        aux = value_per_us(readings_us[i]);
        #endif
        us_byte |= aux;
        if(i!=0)
        us_byte = us_byte << 0x02;
    }
  
}

void read_us(unsigned long* readings_us) 
{
    static float filtered_us[2] = {0.0,0.0}; 
    
    #ifdef ALFA
    for (uint8_t j = 0; j < (uint8_t)(1/(1-ALFA))+1; j++)
    {
    #endif
        for (uint8_t i = 0; i < SONAR_NUM; i++) { // Loop through each sensor and display results.
        #ifdef ALFA
            filtered_us[i] = low_pass_filter(filtered_us[i],sonar[i].ping_cm());
        #else
            readings_us[i] = sonar[i].ping_cm();
        #endif
        delay(28);
        }
    #ifdef ALFA
    }
    #endif
    #ifdef ALFA
        mask(filtered_us);
    #else
        mask(readings_us);
    #endif

    Serial.print("Leitura 1: ");
    Serial.println(readings_us[0]);
    Serial.print("Leitura 2: ");
    Serial.println(readings_us[1]);

    // se alguma das leiturass é zero == 200
}

void teste_us() {

}