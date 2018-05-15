#ifndef __SPI_COMMON_API_H
#define __SPI_COMMON_API_H

#include "device.h"


               /*-----------API--------------*/
typedef int (*spi_api_1)(struct device *dev, uint8_t *data, uint16_t length);
typedef int (*spi_api_2)(struct device *dev, uint8_t *data, uint16_t length);
typedef int (*spi_api_3)(struct device *dev, uint8_t *tx_data, uint8_t *rx_data, uint16_t length);

struct spi_common_api {
	spi_api_1 transmit;
	spi_api_2 receive;
	spi_api_3 transmit_receive;
};

               /*-----------APP--------------*/
static inline int spi_init(struct device *dev)
{
	return dev->init(dev);
}

static inline int spi_transmit(struct device *dev, uint8_t *data, uint16_t length)
{
	const struct spi_common_api *spi_common_api = dev->api;
	return spi_common_api->transmit(dev, data, length);
}

static inline int spi_receive(struct device *dev, uint8_t *data, uint16_t length)
{
	const struct spi_common_api *spi_common_api = dev->api;
	return spi_common_api->receive(dev, data, length);
}

static inline int spi_transmit_receive(struct device *dev, uint8_t *tx_data, uint8_t *rx_data, uint16_t length)
{
	const struct spi_common_api *spi_common_api = dev->api;
	return spi_common_api->transmit_receive(dev, tx_data, rx_data, length);
}


#endif