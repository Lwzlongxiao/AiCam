#include "hal_i2c.h"
#include "stm32h7xx_hal_i2c.h"

// 文件名+函数+行号printf做dbug
static Hal_I2cStru g_i2cList[I2C_ID_MAX] = 
{
    {

    },
    {

    },
    {

    },
    {

    },
    {
        .i2cProperties.Timing = 0x00606092,
        .i2cProperties.OwnAddress1 = 0,
        .i2cProperties.AddressingMode = I2C_ADDRESSINGMODE_7BIT,
        .i2cProperties.DualAddressMode = I2C_DUALADDRESS_DISABLE,
        .i2cProperties.OwnAddress2 = 0,
        .i2cProperties.OwnAddress2Masks = I2C_OA2_NOMASK,
        .i2cProperties.GeneralCallMode = I2C_GENERALCALL_DISABLE,
        .i2cProperties.NoStretchMode = I2C_NOSTRETCH_DISABLE,
    },
    {

    },
    {

    },
};
static I2C_Hehavior g_i2cHost;

void HAL_IICInitHookFromVendor(void)
{
    g_i2cHost.HAL_I2C_Init = HAL_I2C_Init;
    g_i2cHost.HAL_I2C_DeInit = HAL_I2C_DeInit;
    g_i2cHost.HAL_I2C_MspDeInit = HAL_I2C_MspInit;
    g_i2cHost.HAL_I2C_MspInit = HAL_I2C_MspInit;
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

    for (uint32_t i = 0; i < I2C_ID_MAX; i++) {
        g_i2cList[i].i2cBehavior = &g_i2cHost;
    }
}

Hal_I2cStru* HAL_I2C_GetHandle(uint8_t i2cIndex)
{
    if (i2cIndex >= I2C_ID_MAX) {
        return NULL;
    }
    return &g_i2cList[i2cIndex];
}