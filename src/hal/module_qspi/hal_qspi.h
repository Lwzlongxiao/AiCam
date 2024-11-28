#ifndef __HAL_QSPI_H
#define __HAL_QSPI_H

#include <stdint.h>

/* QSPI ID定义 */
enum {
    QSPI_ID0 = 0,
    QSPI_ID1 = 1,
    QSPI_ID_MAX = 2
};

/* QSPI属性定义 */
typedef struct {
    uint32_t BaudRatePrescaler; /* 波特率预分频 */
    uint32_t ClockMode;         /* 时钟模式 */
    uint32_t DataMode;          /* 数据模式 */
    uint32_t FlashSize;         /* 闪存大小 */
    uint32_t AddressMode;       /* 地址模式 */
    uint32_t DummyCycles;       /* 空操作周期 */
} QSPI_Properties;

typedef int8_t status;
typedef status (*QSPI_TransmitFn)(QSPI_Properties *, uint8_t *, uint32_t);
typedef status (*QSPI_ReceiveFn)(QSPI_Properties *, uint8_t *, uint32_t);
typedef status (*QSPI_WriteITFn)(QSPI_Properties *, uint8_t *, uint32_t);
typedef status (*QSPI_ReadITFn)(QSPI_Properties *, uint8_t *, uint32_t);

typedef status (*QSPI_TransmitDMAFn)(QSPI_Properties *, uint8_t *, uint32_t);
typedef status (*QSPI_ReceiveDMAFn)(QSPI_Properties *, uint8_t *, uint32_t);

/* QSPI行为定义 */
typedef struct {
    int8_t (*HAL_QSPI_InitFn)(QSPI_Properties);
    int8_t (*HAL_QSPI_DeInitFn)(QSPI_Properties);
    void (*HAL_QSPI_MspInitFn)(QSPI_Properties);
    void (*HAL_QSPI_MspDeInitFn)(QSPI_Properties);

    QSPI_TransmitFn QSPI_Transmit;
    QSPI_ReceiveFn QSPI_Receive;
    QSPI_WriteITFn QSPI_Write_IT;
    QSPI_ReadITFn QSPI_Read_IT;

    QSPI_TransmitDMAFn QSPI_Transmit_DMA;
    QSPI_ReceiveDMAFn QSPI_Receive_DMA;
} QSPI_Hehavior;

/* QSPI对象定义 */
typedef struct {
    QSPI_Properties qspiProperties;
    QSPI_Hehavior *qspiBehavior;
} Hal_QspiStru;

/* 函数声明 */
void HAL_QSPI_InitHookFromVendor(void);
Hal_QspiStru* HAL_QSPI_GetHandle(uint8_t qspiIndex);

#endif
