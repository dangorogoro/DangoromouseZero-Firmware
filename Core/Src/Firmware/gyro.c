#include "gyro.h"

inline void gyro_cs_set(GPIO_PinState state)
{
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, state);
}
uint8_t spi_gyro_read(uint8_t address)
{
  gyro_cs_set(GPIO_PIN_RESET);
  uint8_t transmit[2] = {0};
  transmit[0] = address | 0xc0;
  uint8_t receive[2] = {0};
  HAL_SPI_TransmitReceive(&hspi1, transmit, receive, 2, 100);
  gyro_cs_set(GPIO_PIN_SET);
  return receive[1];
}
void spi_gyro_write(uint8_t address, uint8_t value)
{
  uint8_t transmit[2] = {address, value};
  gyro_cs_set(GPIO_PIN_RESET);
  HAL_SPI_Transmit(&hspi1, transmit, 2, 100);
  gyro_cs_set(GPIO_PIN_SET);
}
int16_t read_gyro_z(void)
{
  uint16_t Z_H = spi_gyro_read(GYRO_OUT_Z_H);
  uint16_t Z_L = spi_gyro_read(GYRO_OUT_Z_L);

  return (int16_t)((Z_H << 8) | Z_L);
}
void set_gyro_configuration(void)
{
  spi_gyro_write(GYRO_CTRL1, 0x0f);
}