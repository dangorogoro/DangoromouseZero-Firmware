#include "ir_sensor.h"
uint16_t ir_sensor_value[4];
uint16_t temp_ir_sensor_value[4];
void ir_flash_start()
{
  HAL_TIM_PWM_Start(&htim9, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim9, TIM_CHANNEL_2);
  __HAL_TIM_SET_COMPARE(&htim9, TIM_CHANNEL_1, 20); //Max 100
  __HAL_TIM_SET_COMPARE(&htim9, TIM_CHANNEL_2, 20); //Max 100
  ir_value_reset();
}

void ir_flash_stop()
{
  HAL_TIM_PWM_Stop(&htim9, TIM_CHANNEL_1);
  HAL_TIM_PWM_Stop(&htim9, TIM_CHANNEL_2);
  __HAL_TIM_SET_COMPARE(&htim9, TIM_CHANNEL_1, 20); //Max 100
  __HAL_TIM_SET_COMPARE(&htim9, TIM_CHANNEL_2, 20); //Max 100
}

void ir_sampling()
{
  for (uint8_t i = 0; i < IR_SENSOR_NUM; i++)
  {
    if (g_adc_data[i] > ir_sensor_value[i])
      ir_sensor_value[i] = g_adc_data[i];
  }
}
void ir_update()
{
  for (uint8_t i = 0; i < IR_SENSOR_NUM; i++)
  {
      ir_sensor_value[i] = temp_ir_sensor_value[i];
      temp_ir_sensor_value[i] = 0;
  }  
}
void ir_value_reset()
{
  for (uint8_t i = 0; i < IR_SENSOR_NUM; i++) ir_sensor_value[i] = 0;
}
