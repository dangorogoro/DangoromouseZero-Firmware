#ifndef _MOTOR_H_
#define _MOTOR_H_
#include "main.h"
void start_motor();
void stop_motor();
void set_motor_pulse(int16_t left_pulse, int16_t right_pulse);
void start_encoder();
#endif