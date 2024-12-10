#include "ADAPTER_pca9555.h"
#include "i2c.h"

#define PCA9555_I2C_ID 4  // PCA9555 I2C地址

void ADAPTER_Pca9555Init(void)
{
    Adapter_I2c_Init(PCA9555_I2C_ID); // 初始化I2C
}

// PCA9555 初始化
void ADAPTER_Pca9555Init(void) {
    uint8_t config_byte = 0xff;  // 配置所有IO为输入出模式
    Hal_I2cStru *pI2cHandle = Adapter_I2C_GetHandle(PCA9555_I2C_ID);
    if (pI2cHandle == NULL) {
        return 0;
    }
    HAL_StatusTypeDef ret = pI2cHandle->i2cBehavior->I2C_MemWrite(&pI2cHandle->i2cHan, PCA9555_I2C_ADDR, CONFIG_PORT_REGISTER0, I2C_MEMADD_SIZE_8BIT, &config_byte, 1, 1000);    
    if (ret != HAL_OK) {
        // 初始化失败
    }
    HAL_StatusTypeDef ret = pI2cHandle->i2cBehavior->I2C_MemWrite(&pI2cHandle->i2cHan, PCA9555_I2C_ADDR, CONFIG_PORT_REGISTER1, I2C_MEMADD_SIZE_8BIT, &config_byte, 1, 1000);    
    if (ret != HAL_OK) {
        // 初始化失败
    }
}

// 设置GPIO为输出模式
void ADAPTER_Pca9555SetOutputMode(uint8_t pin)
 {
    Hal_I2cStru *pI2cHandle = Adapter_I2C_GetHandle(PCA9555_I2C_ID);
    if (pI2cHandle == NULL || pin > 15) {
        return 0;
    }

    uint8_t reg = CONFIG_PORT_REGISTER0;
    if (pin > PCA9555_PIN7) {
        reg = CONFIG_PORT_REGISTER1;
        pin -= PCA9555_PIN8;        
    }

    uint8_t config_byte;
    HAL_StatusTypeDef ret = pI2cHandle->i2cBehavior->I2C_MemRead(&pI2cHandle->i2cHan, PCA9555_I2C_ADDR, reg, I2C_MEMADD_SIZE_8BIT, &config_byte, 1, 1000);    
    if (ret != HAL_OK) {
        // 初始化失败
    }
    config_byte &= ~(1 << pin);  // 清除对应位
    HAL_StatusTypeDef ret = pI2cHandle->i2cBehavior->I2C_MemWrite(&pI2cHandle->i2cHan, PCA9555_I2C_ADDR, reg, I2C_MEMADD_SIZE_8BIT, &config_byte, 1, 1000);    
    if (ret != HAL_OK) {
        // 初始化失败
    }
}

// 设置GPIO为输入模式
void ADAPTER_Pca9555SetInputMode(uint8_t pin) 
{
    Hal_I2cStru *pI2cHandle = Adapter_I2C_GetHandle(PCA9555_I2C_ID);
    if (pI2cHandle == NULL) {
        return 0;
    }
    
    uint8_t reg = CONFIG_PORT_REGISTER0;
    if (pin > PCA9555_PIN7) {
        reg = CONFIG_PORT_REGISTER1;
        pin -= PCA9555_PIN8;
    }
    
    uint8_t config_byte;
    HAL_StatusTypeDef ret = pI2cHandle->i2cBehavior->I2C_MemRead(&pI2cHandle->i2cHan, PCA9555_I2C_ADDR, reg, I2C_MEMADD_SIZE_8BIT, &config_byte, 1, 1000);    
    if (ret != HAL_OK) {
        // 初始化失败
    }
    config_byte |= (1 << pin);  // 设置对应位
    HAL_StatusTypeDef ret = pI2cHandle->i2cBehavior->I2C_MemWrite(&pI2cHandle->i2cHan, PCA9555_I2C_ADDR, reg, I2C_MEMADD_SIZE_8BIT, &config_byte, 1, 1000);    
    if (ret != HAL_OK) {
        // 初始化失败
    }
}

// 设置GPIO输出状态
void ADAPTER_Pca9555SetGPIOOutputStatus(uint8_t pin, uint8_t status) 
{
    Hal_I2cStru *pI2cHandle = Adapter_I2C_GetHandle(PCA9555_I2C_ID);
    if (pI2cHandle == NULL) {
        return 0;
    }
    
    uint8_t reg = CONFIG_PORT_REGISTER0;
    if (pin > PCA9555_PIN7) {
        reg = CONFIG_PORT_REGISTER1;
        pin -= PCA9555_PIN8;        
    }

    uint8_t output_byte;
    HAL_StatusTypeDef ret = pI2cHandle->i2cBehavior->I2C_MemRead(&pI2cHandle->i2cHan, PCA9555_I2C_ADDR, reg, I2C_MEMADD_SIZE_8BIT, &output_byte, 1, 1000);    
    if (ret != HAL_OK) {
        // 初始化失败
    }
    if (status) {
        output_byte |= (1 << pin);  // 设置对应位
    } else {
        output_byte &= ~(1 << pin);  // 清除对应位
    }
    HAL_StatusTypeDef ret = pI2cHandle->i2cBehavior->I2C_MemWrite(&pI2cHandle->i2cHan, PCA9555_I2C_ADDR, reg, I2C_MEMADD_SIZE_8BIT, &output_byte, 1, 1000);    
    if (ret != HAL_OK) {
        // 初始化失败
    }    
}

// 获取GPIO输入状态
uint8_t ADAPTER_Pca9555GetGPIOStatus(uint8_t pin) 
{
    Hal_I2cStru *pI2cHandle = Adapter_I2C_GetHandle(PCA9555_I2C_ID);
    if (pI2cHandle == NULL) {
        return 0;
    }

    uint8_t reg = CONFIG_PORT_REGISTER0;
    if (pin > PCA9555_PIN7) {
        reg = CONFIG_PORT_REGISTER1;
        pin -= PCA9555_PIN8;        
    }

    uint8_t input_byte;
    HAL_StatusTypeDef ret = pI2cHandle->i2cBehavior->I2C_MemRead(&pI2cHandle->i2cHan, PCA9555_I2C_ADDR, reg, I2C_MEMADD_SIZE_8BIT, &input_byte, 1, 1000);    
    if (ret != HAL_OK) {
        // 初始化失败
    }        
    return (input_byte >> pin) & 0x01;
}