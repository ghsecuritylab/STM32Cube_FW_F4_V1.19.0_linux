#include "stm32f4xx_hal.h"
#include "cmsis_os.h"
#include "stm32f4xx_it.h"


void NMI_Handler(void)
{
}

void HardFault_Handler(void)
{
  while(1) {
  }
}

void MemManage_Handler(void)
{
  while(1) {
  }
}

void BusFault_Handler(void)
{
  while(1) {
  }
}

void UsageFault_Handler(void)
{
  while(1) {
  }
}

void DebugMon_Handler(void)
{
}

void SysTick_Handler(void)
{
  HAL_IncTick();
  osSystickHandler();
}
