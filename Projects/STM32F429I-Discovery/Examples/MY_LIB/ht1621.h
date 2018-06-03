#ifndef __HT1621_H
#define __HT1621_H

#include "gpio_a5.h"
#include "gpio_g2.h"
#include "gpio_g3.h"


#define  CS_LOW        A5_OUTPUT_LOW()
#define  CS_HIGH       A5_OUTPUT_HIGH()
#define  WR_LOW        G3_OUTPUT_LOW()
#define  WR_HIGH       G3_OUTPUT_HIGH()
#define  DATA_LOW      G2_OUTPUT_LOW()
#define  DATA_HIGH     G2_OUTPUT_HIGH()

#define  BIAS          0x29
#define  RC256         0x18
#define  SYSEN         0x01
#define  LCDON         0x03

void send_command(uint8_t cmd);
void write_seg_data_4(uint8_t seg_addr, uint8_t com_data);
void write_seg_data_44(uint8_t seg_addr, uint8_t *com_data, uint16_t count);
void write_seg_data_bit_4(uint8_t seg_addr, uint8_t d3, uint8_t d2, uint8_t d1, uint8_t d0);
void set_all(void);
void clean_all(void);
void ht1621_init(void);


#endif