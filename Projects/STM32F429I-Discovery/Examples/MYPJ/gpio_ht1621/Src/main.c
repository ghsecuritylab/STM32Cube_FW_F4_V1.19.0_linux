#include "system_initialization.h"
#include "uart_printf.h"
#include "api_define.h"
#include "main.h"

#include "ht1621.h"


int main(void)
{
	system_initialization();
	uart_printf_init();
	
	struct gpio_api *gpio_a5 = gpio_a5_binding();
	struct gpio_api *gpio_g2 = gpio_g2_binding();
	struct gpio_api *gpio_g3 = gpio_g3_binding();
	gpio_a5->init();
	gpio_g2->init();
	gpio_g3->init();
	
	ht1621_init();
	
	set_all();
	HAL_Delay(500);
	clean_all();
	HAL_Delay(500);
	
	uint16_t i;
	
	while(1) {
		for(i = 0; i < 32; i++) {
			write_seg_data_4(i, 0x01); //COM:0001
			HAL_Delay(500);
		}
		HAL_Delay(2000);
		
		for(i = 0; i < 32; i++) {
			write_seg_data_4(i, 0x03); //COM:0011
			HAL_Delay(500);
		}
		HAL_Delay(2000);
		
		for(i = 0; i < 32; i++) {
			write_seg_data_4(i, 0x07); //COM:0111
			HAL_Delay(500);
		}
		HAL_Delay(2000);
		
		for(i = 0; i < 32; i++) {
			write_seg_data_4(i, 0x0F); //COM:1111
			HAL_Delay(500);
		}
		HAL_Delay(2000);
		
		for(i = 0; i < 32; i++) {
			write_seg_data_bit_4(i, 1, 1, 1, 0); //COM:1110
			HAL_Delay(500);
		}
		HAL_Delay(2000);
		
		for(i = 0; i < 32; i++) {
			write_seg_data_bit_4(i, 1, 1, 0, 0); //COM:1100
			HAL_Delay(500);
		}
		HAL_Delay(2000);
		
		for(i = 0; i < 32; i++) {
			write_seg_data_bit_4(i, 1, 0, 0, 0); //COM:1000
			HAL_Delay(500);
		}
		HAL_Delay(2000);
		
		for(i = 0; i < 32; i++) {
			write_seg_data_bit_4(i, 0, 0, 0, 0); //COM:0000
			HAL_Delay(500);
		}
		HAL_Delay(2000);
	}
}