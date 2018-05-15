#ifndef __UART_COMMON_API_H
#define __UART_COMMON_API_H

#include "device.h"


               /*-----------API--------------*/
typedef int (*uart_api_1)(struct device *dev, uint8_t *data, uint16_t length);
typedef int (*uart_api_2)(struct device *dev, uint8_t *data, uint16_t length);

struct uart_common_api {
	uart_api_1 transmit;
	uart_api_2 receive;
};

               /*-----------APP--------------*/
static inline int uart_init(struct device *dev)
{
	return dev->init(dev);
}

static inline int uart_transmit(struct device *dev, uint8_t *data, uint16_t length)
{
	const struct uart_common_api *uart_common_api = dev->api;
	return uart_common_api->transmit(dev, data, length);
}

static inline int uart_receive(struct device *dev, uint8_t *data, uint16_t length)
{
	const struct uart_common_api *uart_common_api = dev->api;
	return uart_common_api->receive(dev, data, length);
}


#endif