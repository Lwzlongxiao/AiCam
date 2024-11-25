#include "adapter_pca9555.h"

uint8_t Adapter_Pca9555Read(uint8_t reg)
{
    uint8_t buf[1] = {reg};
    uint8_t data;
    Hal_I2cStru *pI2cHandle = HAL_I2C_GetHandle(PCA9555_I2C_ID);
    if (pI2cHandle == NULL) {
        return 0;
    }
    pI2cHandle->i2cBehavior->I2C_MasterReceive(pI2cHandle, PCA9555_I2C_ADDR, buf, 1, 0);
    return data;
}

void Adapter_Pca9555Write(uint8_t reg, uint8_t data)
{
    uint8_t buf[1] = {reg};
    uint8_t data;
    Hal_I2cStru *pI2cHandle = HAL_I2C_GetHandle(PCA9555_I2C_ID);
    if (pI2cHandle == NULL) {
        return 0;
    }
    pI2cHandle->i2cBehavior->I2C_MasterTransmit(pI2cHandle, PCA9555_I2C_ADDR, buf, 1, 0);
    return data;
}

void Adapter_Pca9555Init(void)
{
    Hal_I2cStru *pI2cHandle = HAL_I2C_GetHandle(PCA9555_I2C_ID);
    pI2cHandle->i2cProperties.OwnAddress1 = PCA9555_I2C_ADDR;
    pI2cHandle->i2cBehavior->HAL_I2C_Init(pI2cHandle->i2cProperties);
}