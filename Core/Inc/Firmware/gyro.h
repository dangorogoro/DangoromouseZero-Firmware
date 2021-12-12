#ifndef _GYRO_H_
#define _GYRO_H_
#include "main.h"
#define GYRO_WHO_AM_I 0x0F
#define GYRO_CTRL1 0x20
#define GYRO_CTRL2 0x21
#define GYRO_OUT_Z_L 0x2C
#define GYRO_OUT_Z_H 0x2D

uint8_t spi_gyro_read(uint8_t address);
void spi_gyro_write(uint8_t address, uint8_t value);
int16_t read_gyro_z(void);
void set_gyro_configuration(void);
#endif