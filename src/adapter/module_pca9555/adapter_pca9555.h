#ifndef _MODULE_PCA9555_H
#define _MODULE_PCA9555_H

#include <stdint.h>
#include "hal_i2c.h"
#include <stddef.h>

#define PCA9555_I2C_ID 4
#define PCA9555_I2C_ADDR 0x20
#define PCA9555_REG_INPUT 0x00
#define PCA9555_REG_OUTPUT 0x02
#define PCA9555_REG_POLARITY 0x04
#define PCA9555_REG_CONFIG 0x06

/* 函数声明 */
void Adapter_Pca9555Init(void);
void Adapter_Pca9555Write(uint8_t reg, uint8_t data);
uint8_t Adapter_Pca9555Read(uint8_t reg);

#endif /* _MODULE_PCA9555_H */