#include "hal_i2c.h"
#include "stm32h7xx_hal.h"

static I2C_HandleTypeDef g_i2cHandleList[I2C_ID_MAX] = {
    {
        .Instance = I2C1,
        .Init = {0},
    },
    {
        .Instance = I2C2,
        .Init = {0},
    },
    {
        .Instance = I2C3,
        .Init = {0},
    },
    {
        .Instance = I2C4,
        .Init = {0},
    }
};

static I2C_Hehavior g_i2cHost;

void HAL_IICInitHookFromVendor(void)
{
    g_i2cHost.HAL_I2C_InitFn = HAL_I2C_Init;
    g_i2cHost.HAL_I2C_DeInitFn = HAL_I2C_DeInit;
    g_i2cHost.HAL_I2C_MspDeInitFn = HAL_I2C_MspInit;
    g_i2cHost.HAL_I2C_MspInitFn = HAL_I2C_MspInit;
    g_i2cHost.I2C_MasterTransmit = HAL_I2C_Master_Transmit;
    g_i2cHost.I2C_MasterReceive = HAL_I2C_Master_Receive;
    g_i2cHost.I2C_SlaveTransmit = HAL_I2C_Slave_Transmit;
    g_i2cHost.I2C_SlaveReceive = HAL_I2C_Slave_Receive;
    g_i2cHost.I2C_MemWrite = HAL_I2C_Mem_Write;
    g_i2cHost.I2C_MemRead = HAL_I2C_Mem_Read;
    g_i2cHost.I2C_IsDeviceReady = HAL_I2C_IsDeviceReady;

    g_i2cHost.I2C_MasterTransmit_IT = HAL_I2C_Master_Transmit_IT;
    g_i2cHost.I2C_MasterReceive_IT = HAL_I2C_Master_Receive_IT;
    g_i2cHost.I2C_SlaveTransmit_IT = HAL_I2C_Slave_Transmit_IT;
    g_i2cHost.I2C_SlaveReceive_IT = HAL_I2C_Slave_Receive_IT;
    g_i2cHost.I2C_MemWrite_IT = HAL_I2C_Mem_Write_IT;
    g_i2cHost.I2C_MemRead_IT = HAL_I2C_Mem_Read_IT;

    g_i2cHost.I2C_MasterSeqTransmit_IT = HAL_I2C_Master_Seq_Transmit_IT;
    g_i2cHost.I2C_MasterSeqReceive_IT = HAL_I2C_Master_Seq_Receive_IT;
    g_i2cHost.I2C_SlaveSeqTransmit_IT = HAL_I2C_Slave_Seq_Transmit_IT;
    g_i2cHost.I2C_SlaveSeqReceive_IT = HAL_I2C_Slave_Seq_Receive_IT;
    g_i2cHost.I2C_EnableListen_IT = HAL_I2C_EnableListen_IT;
    g_i2cHost.I2C_DisableListen_IT = HAL_I2C_DisableListen_IT;
    g_i2cHost.I2C_MasterAbort_IT = HAL_I2C_Master_Abort_IT;

    g_i2cHost.I2C_MasterTransmit_DMA = HAL_I2C_Master_Transmit_DMA;
    g_i2cHost.I2C_MasterReceive_DMA = HAL_I2C_Master_Receive_DMA;
    g_i2cHost.I2C_SlaveTransmit_DMA = HAL_I2C_Slave_Transmit_DMA;
    g_i2cHost.I2C_SlaveReceive_DMA = HAL_I2C_Slave_Receive_DMA;
    g_i2cHost.I2C_MemWrite_DMA = HAL_I2C_Mem_Write_DMA;
    g_i2cHost.I2C_MemRead_DMA = HAL_I2C_Mem_Read_DMA;

    g_i2cHost.I2C_MasterSeqTransmit_DMA = HAL_I2C_Master_Seq_Transmit_DMA;
    g_i2cHost.I2C_MasterSeqReceive_DMA = HAL_I2C_Master_Seq_Receive_DMA;
    g_i2cHost.I2C_SlaveSeqTransmit_DMA = HAL_I2C_Slave_Seq_Transmit_DMA;
    g_i2cHost.I2C_SlaveSeqReceive_DMA = HAL_I2C_Slave_Seq_Receive_DMA;

}

I2C_Hehavior* HAL_I2C_GetHost(void)
{
    return &g_i2cHost;
}

I2C_HandleTypeDef *HAL_I2C_GetHandleList(void)
{
    return &g_i2cHandleList;
}