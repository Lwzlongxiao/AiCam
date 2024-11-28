#ifndef __HAL_UART_H
#define __HAL_UART_H

#include <stdint.h>

/* UART ID定义 */
enum {
    UART_ID0 = 0,
    UART_ID1 = 1,
    UART_ID2 = 2,
    UART_ID3 = 3,
    UART_ID4 = 4,
    UART_ID5 = 5,
    UART_ID6 = 6,
    UART_ID7 = 7,
    UART_ID_MAX = 8
};

/* 属性定义 */
typedef struct {
    uint32_t BaudRate; /* 波特率：9600, 19200, 38400, 57600, 115200, ... */
    uint32_t WordLength;
    uint32_t StopBits;
    uint32_t Parity;
    uint32_t Mode;
    uint32_t HwFlowCtl;
    uint32_t OverSampling;
} UART_Properties;

typedef int8_t status;
typedef status (*UART_TransmitFn)(UART_Properties *, uint8_t *, uint16_t, uint32_t);
typedef status (*UART_ReceiveFn)(UART_Properties *, uint8_t *, uint16_t, uint32_t);
typedef status (*UART_TransmitITFn)(UART_Properties *, uint8_t *, uint16_t);
typedef status (*UART_ReceiveITFn)(UART_Properties *, uint8_t *, uint16_t);
typedef status (*UART_TransmitDMAFn)(UART_Properties *, uint8_t *, uint16_t);
typedef status (*UART_ReceiveDMAFn)(UART_Properties *, uint8_t *, uint16_t);

/* 行为定义 */
typedef struct{
    int8_t (*HAL_UART_InitFn)(UART_Properties);
    int8_t (*HAL_UART_DeInitFn)(UART_Properties);
    void (*HAL_UART_MspInitFn)(UART_Properties);
    void (*HAL_UART_MspDeInitFn)(UART_Properties);

    UART_TransmitFn UART_Transmit;
    UART_ReceiveFn UART_Receive;

    UART_TransmitITFn UART_Transmit_IT;
    UART_ReceiveITFn UART_Receive_IT;

    UART_TransmitDMAFn UART_Transmit_DMA;
    UART_ReceiveDMAFn UART_Receive_DMA;
} UART_Behavior;

/* 对象定义 */
typedef struct
{
    UART_Properties uartProperties;
    UART_Behavior *uartBehavior;
} Hal_UartStru;

/* 函数声明 */
void HAL_UART_InitHookFromVendor(void);
Hal_UartStru* HAL_UART_GetHandle(uint8_t uartIndex);

#endif