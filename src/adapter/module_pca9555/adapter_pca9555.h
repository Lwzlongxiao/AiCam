#ifndef _MODULE_PCA9555_H
#define _MODULE_PCA9555_H

#include <stdint.h>
#include "hal_i2c.h"
#include <stddef.h>

enum {
    PCA9555_PORT0 = 0,
    PCA9555_PORT1 = 1,
};
enum {
    PCA9555_PIN0 = 0,
    PCA9555_PIN1,
    PCA9555_PIN2,
    PCA9555_PIN3,
    PCA9555_PIN4,
    PCA9555_PIN5,
    PCA9555_PIN6,
    PCA9555_PIN7,
    PCA9555_PIN8,
    PCA9555_PIN9,
    PCA9555_PIN10,
    PCA9555_PIN11,
    PCA9555_PIN12,
    PCA9555_PIN13,
    PCA9555_PIN14,
    PCA9555_PIN15,
    PCA9555_PIN_MAX,
};

#define PCA9555_I2C_ADDR 0x40  // PCA9555 I2C地址

// 寄存器地址
#define INPUT_PORT_REGISTER0 0x00
#define INPUT_PORT_REGISTER1 0x01
#define OUTPUT_PORT_REGISTER0 0x02
#define OUTPUT_PORT_REGISTER1 0x03
#define POLARITY_INVERSION_PORT_REGISTER0 0x04
#define POLARITY_INVERSION_PORT_REGISTER1 0x05
#define CONFIG_PORT_REGISTER0 0x06
#define CONFIG_PORT_REGISTER1 0x07

/* 函数声明 */
void ADAPTER_Pca9555Init(void);
void ADAPTER_Pca9555SetOutputMode(uint8_t pin);
void ADAPTER_Pca9555SetInputMode(uint8_t pin);
void ADAPTER_Pca9555SetGPIOOutputStatus(uint8_t pin, uint8_t status);
uint8_t ADAPTER_Pca9555GetGPIOStatus(uint8_t pin);
#endif /* _MODULE_PCA9555_H */