#include "motor.h"
void set_right_motor_pulse(int16_t pulse)
{
  int16_t max_pulse = htim4.Init.Period;
  if (pulse > 0)
  {
    if (pulse >= max_pulse)
      pulse = max_pulse;
    __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, max_pulse);
    __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, max_pulse - pulse);
  }
  else
  {
    if (pulse <= -max_pulse)
      pulse = -max_pulse;
    __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, max_pulse + pulse);
    __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, max_pulse);
  }
}

void set_left_motor_pulse(int16_t pulse)
{
  int16_t max_pulse = htim4.Init.Period;
  if (pulse > 0)
  {
    if (pulse >= max_pulse)
      pulse = max_pulse;
    __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, max_pulse);
    __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, max_pulse - pulse);
  }
  else
  {
    if (pulse <= -max_pulse)
      pulse = -max_pulse;
    __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, max_pulse + pulse);
    __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, max_pulse);
  }
}
void set_motor_pulse(int16_t left_pulse, int16_t right_pulse)
{
  start_motor();
  set_left_motor_pulse(left_pulse);
  set_right_motor_pulse(right_pulse);
}
void start_motor()
{
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_3);
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_4);
}
void stop_motor()
{
  set_motor_pulse(0, 0);
  HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_1);
  HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_2);
  HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_3);
  HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_4);
}
void start_encoder()
{
  HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_ALL); // left encoder
  HAL_TIM_Encoder_Start(&htim8, TIM_CHANNEL_ALL); // right encoder
}
