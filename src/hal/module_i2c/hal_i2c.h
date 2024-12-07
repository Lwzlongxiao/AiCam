#ifndef __HAL_IIC_H
#define __HAL_IIC_H

#include <stdint.h>
#include "stm32h7xx_hal.h"

/* I2C ID定义 */
enum {
    I2C_ID0 = 0,
    I2C_ID1 = 1,
    I2C_ID2 = 2,
    I2C_ID3 = 3,
    I2C_ID4 = 4,
    I2C_ID5 = 5,
    I2C_ID6 = 6,
    I2C_ID7 = 7,
    I2C_ID_MAX = 8
};

/* 属性定义 */
typedef struct {
    uint32_t Timing; /* 用于计算速度：100khz... */
    uint32_t OwnAddress1;
    uint32_t AddressingMode;
    uint32_t DualAddressMode;
    uint32_t OwnAddress2;
    uint32_t OwnAddress2Masks;
    uint32_t GeneralCallMode;
    uint32_t NoStretchMode;
} I2C_Properties;

typedef int8_t status;
typedef status (*I2C_MasterTransmitFn)(I2C_Properties *, uint16_t, uint8_t *, uint16_t, uint32_t);
typedef status (*I2C_MasterReceiveFn)(I2C_Properties *, uint16_t, uint8_t *, uint16_t, uint32_t);
typedef status (*I2C_SlaveTransmitFn)(I2C_Properties *, uint8_t *, uint16_t, uint32_t);
typedef status (*I2C_SlaveReceiveFn)(I2C_Properties *, uint8_t *, uint16_t, uint32_t);
typedef status (*I2C_MemWriteFn)(I2C_Properties *, uint16_t, uint16_t, uint16_t, uint8_t *, uint16_t, uint32_t);
typedef status (*I2C_MemReadFn)(I2C_Properties *, uint16_t, uint16_t, uint16_t, uint8_t *, uint16_t, uint32_t);
typedef status (*I2C_IsDeviceReadyFn)(I2C_Properties *, uint16_t, uint32_t, uint32_t);

typedef status (*I2C_MasterTransmitITFn)(I2C_Properties *, uint16_t, uint8_t *, uint16_t);
typedef status (*I2C_MasterReceiveITFn)(I2C_Properties *, uint16_t, uint8_t *, uint16_t);
typedef status (*I2C_SlaveTransmitITFn)(I2C_Properties *, uint8_t *, uint16_t);
typedef status (*I2C_SlaveReceiveITFn)(I2C_Properties *, uint8_t *, uint16_t);
typedef status (*I2C_MemWriteITFn)(I2C_Properties *, uint16_t, uint16_t, uint16_t, uint8_t *, uint16_t);
typedef status (*I2C_MemReadITFn)(I2C_Properties *, uint16_t, uint16_t, uint16_t, uint8_t *, uint16_t);

typedef status (*I2C_MasterSeqTransmitITFn)(I2C_Properties *, uint16_t, uint8_t *, uint16_t, uint32_t);
typedef status (*I2C_MasterSeqReceiveITFn)(I2C_Properties *, uint16_t, uint8_t *, uint16_t, uint32_t);
typedef status (*I2C_SlaveSeqTransmitITFn)(I2C_Properties *, uint8_t *, uint16_t, uint32_t);
typedef status (*I2C_SlaveSeqReceiveITFn)(I2C_Properties *, uint8_t *, uint16_t, uint32_t);
typedef status (*I2C_EnableListenITFn)(I2C_Properties *);
typedef status (*I2C_DisableListenITFn)(I2C_Properties *);
typedef status (*I2C_MasterAbortITFn)(I2C_Properties *, uint16_t);

typedef status (*I2C_MasterTransmitDMAFn)(I2C_Properties *, uint16_t, uint8_t *, uint16_t);
typedef status (*I2C_MasterReceiveDMAFn)(I2C_Properties *, uint16_t, uint8_t *, uint16_t);
typedef status (*I2C_SlaveTransmitDMAFn)(I2C_Properties *, uint8_t *, uint16_t);
typedef status (*I2C_SlaveReceiveDMAFn)(I2C_Properties *, uint8_t *, uint16_t);
typedef status (*I2C_MemWriteDMAFn)(I2C_Properties *, uint16_t, uint16_t, uint16_t, uint8_t *, uint16_t);
typedef status (*I2C_MemReadDMAFn)(I2C_Properties *, uint16_t, uint16_t, uint16_t, uint8_t *, uint16_t);

typedef status (*I2C_MasterSeqTransmitDMAFn)(I2C_Properties *, uint16_t, uint8_t *, uint16_t, uint32_t);
typedef status (*I2C_MasterSeqReceiveDMAFn)(I2C_Properties *, uint16_t, uint8_t *, uint16_t, uint32_t);
typedef status (*I2C_SlaveSeqTransmitDMAFn)(I2C_Properties *, uint8_t *, uint16_t, uint32_t);
typedef status (*I2C_SlaveSeqReceiveDMAFn)(I2C_Properties *, uint8_t *, uint16_t, uint32_t);

/* 行为定义 */
typedef struct{
    int8_t (*HAL_I2C_InitFn)(I2C_Properties);
    int8_t (*HAL_I2C_DeInitFn)(I2C_Properties);
    void (*HAL_I2C_MspInitFn)(I2C_Properties);
    void (*HAL_I2C_MspDeInitFn)(I2C_Properties);

    I2C_MasterTransmitFn I2C_MasterTransmit;
    I2C_MasterReceiveFn I2C_MasterReceive;
    I2C_SlaveTransmitFn I2C_SlaveTransmit;
    I2C_SlaveReceiveFn I2C_SlaveReceive;
    I2C_MemWriteFn I2C_MemWrite;
    I2C_MemReadFn I2C_MemRead;
    I2C_IsDeviceReadyFn I2C_IsDeviceReady;

    I2C_MasterTransmitITFn I2C_MasterTransmit_IT;
    I2C_MasterReceiveITFn I2C_MasterReceive_IT;
    I2C_SlaveTransmitITFn I2C_SlaveTransmit_IT;
    I2C_SlaveReceiveITFn I2C_SlaveReceive_IT;
    I2C_MemWriteITFn I2C_MemWrite_IT;
    I2C_MemReadITFn I2C_MemRead_IT;

    I2C_MasterSeqTransmitITFn I2C_MasterSeqTransmit_IT;
    I2C_MasterSeqReceiveITFn I2C_MasterSeqReceive_IT;
    I2C_SlaveSeqTransmitITFn I2C_SlaveSeqTransmit_IT;
    I2C_SlaveSeqReceiveITFn I2C_SlaveSeqReceive_IT;
    I2C_EnableListenITFn I2C_EnableListen_IT;
    I2C_DisableListenITFn I2C_DisableListen_IT;
    I2C_MasterAbortITFn I2C_MasterAbort_IT;

    I2C_MasterTransmitDMAFn I2C_MasterTransmit_DMA;
    I2C_MasterReceiveDMAFn I2C_MasterReceive_DMA;
    I2C_SlaveTransmitDMAFn I2C_SlaveTransmit_DMA;
    I2C_SlaveReceiveDMAFn I2C_SlaveReceive_DMA;
    I2C_MemWriteDMAFn I2C_MemWrite_DMA;
    I2C_MemReadDMAFn I2C_MemRead_DMA;

    I2C_MasterSeqTransmitDMAFn I2C_MasterSeqTransmit_DMA;
    I2C_MasterSeqReceiveDMAFn I2C_MasterSeqReceive_DMA;
    I2C_SlaveSeqTransmitDMAFn I2C_SlaveSeqTransmit_DMA;
    I2C_SlaveSeqReceiveDMAFn I2C_SlaveSeqReceive_DMA;
} I2C_Hehavior;
/* 对象定义 */
typedef struct
{
    I2C_Properties i2cProperties;
    I2C_Hehavior *i2cBehavior;
} Hal_I2cStru;

/* 函数声明 */
void HAL_IICInitHookFromVendor(void);
Hal_I2cStru* HAL_I2C_GetHandle(uint8_t i2cIndex);

#endif