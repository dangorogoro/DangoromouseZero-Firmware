#ifndef _IR_SENSOR_H_
#define _IR_SENSOR_H_
#include "main.h"
#define IR_SENSOR_NUM 4
void ir_flash_start();
void ir_flash_stop();
void ir_sampling();
void ir_update();
void ir_value_reset();
extern uint16_t ir_sensor_value[IR_SENSOR_NUM];
#endif