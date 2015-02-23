#ifndef __TPS65217_H_
#define __TPS65217_H_

#include <stdint.h>
#include <stdbool.h>

#define	TPS65217_BUS_NUM	1
#define	TPS65217_BUS_ADDRESS	0x24

#define	TPS65217_CHIPID			0x00
#define	TPS65217_MUXCTRL		0x09
#define	TPS65217_STATUS			0x0A
#define	TPS65217_STATUS_BIT_USBPWR	(1 << 2)
#define	TPS65217_STATUS_BIT_ACPWR	(1 << 3)
#define	TPS65217_STATUS_BIT_OFF		(1 << 7)
#define	TPS65217_PASSWORD		0x0B
#define	TPS65217_PASSWORD_VALUE		0x7D
#define	TPS65217_PGOOD			0x0C
#define	TPS65217_DEFDCDC1		0x0E
#define	TPS65217_DEFDCDC2		0x0F
#define	TPS65217_DEFDCDC3		0x10
#define	TPS65217_DEFDCDC_VALUE_1_2V	0x0C
#define	TPS65217_DEFDCDC_VALUE_1_8V	0x1E
#define	TPS65217_DEFDCDC_VALUE_1_95V	0x21
#define	TPS65217_DEFDCDC_VALUE_3_3V	0x38
#define	TPS65217_DEFSLEW		0x11
#define	TPS65217_DEFSLEW_GO_FAST	0x86
#define	TPS65217_DEFLDO1		0x12
#define	TPS65217_DEFLDO1_VALUE_2_5V	0x0A
#define	TPS65217_DEFLDO2		0x13
#define	TPS65217_DEFLDO2_VALUE_1_2V	0x0C
#define	TPS65217_DEFLDO3		0x14
#define	TPS65217_DEFLDO3_VALUE_LS_3_3V	0x1F
#define	TPS65217_DEFLDO4		0x15
#define	TPS65217_DEFLDO4_VALUE_LDO_1_8V	0x26
#define	TPS65217_DEFLDO4_VALUE_LDO_2_5V	0x2F
#define	TPS65217_ENABLE			0x16
#define	TPS65217_ENABLE_DCDC1		(1 << 4)
#define	TPS65217_ENABLE_DCDC2		(1 << 3)
#define	TPS65217_ENABLE_DCDC3		(1 << 2)
#define	TPS65217_ENABLE_LDO1		(1 << 1)
#define	TPS65217_ENABLE_LDO2		(1 << 0)
#define	TPS65217_ENABLE_LDO3		(1 << 6)
#define	TPS65217_ENABLE_LDO4		(1 << 5)
#define	TPS65217_ENABLE_VALUE		(	    \
    TPS65217_ENABLE_DCDC2 | TPS65217_ENABLE_DCDC3 | \
    TPS65217_ENABLE_LDO1 | TPS65217_ENABLE_LDO2 )
#define	TPS65217_SEQ1			0x19
#define	TPS65217_SEQ1_DCDC1_MASK	0xF0
#define	TPS65217_SEQ1_DCDC2_MASK	0x0F
#define	TPS65217_SEQ1_MASK		(TPS65217_SEQ1_DCDC1_MASK |	\
					 TPS65217_SEQ1_DCDC2_MASK)
#define	TPS65217_SEQ2			0x1A
#define	TPS65217_SEQ2_DCDC3_MASK	0xF0
#define	TPS65217_SEQ2_LDO1_MASK		0x0F
#define	TPS65217_SEQ2_MASK		(TPS65217_SEQ2_DCDC3_MASK |	\
					 TPS65217_SEQ2_LDO1_MASK)
#define	TPS65217_SEQ3			0x1B
#define	TPS65217_SEQ3_LDO2_MASK		0xF0
#define	TPS65217_SEQ3_LDO3_MASK		0x0F
#define	TPS65217_SEQ3_MASK		(TPS65217_SEQ3_LDO2_MASK |	\
					 TPS65217_SEQ3_LDO3_MASK)
#define	TPS65217_SEQ4			0x1C
#define	TPS65217_SEQ4_LDO4_MASK		0xF0
#define	TPS65217_SEQ4_MASK		(TPS65217_SEQ4_LDO4_MASK)

#define	DEFAULT_SPI_VOLTAGE		TPS65217_DEFDCDC_VALUE_1_8V

bool test_tps65217(int i2c_bus);
bool configure_tps65217(int i2c_bus, bool titan_voltage_fix);
bool power_down_spi_connector(int i2c_bus);
bool power_up_spi_connector(int i2c_bus, bool titan_voltage_fix);
bool tps65217_set_digital_SPI_voltage(int i2c_bus, int voltage);
int tps65217_get_digital_SPI_voltage(int i2c_bus);
uint8_t tps65217_nearest_valid_spi_voltage(float user_voltage);

#endif /* __TPS65217_H_ */
