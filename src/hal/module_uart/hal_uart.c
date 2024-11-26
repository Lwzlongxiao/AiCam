#include <stdint.h>
#include "stm32h7xx_hal.h"

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
    uint32_t BaudRate;                /* 波特率 */
    uint32_t WordLength;              /* 数据位长度 */
    uint32_t StopBits;                /* 停止位 */
    uint32_t Parity;                  /* 校验位 */
    uint32_t Mode;                    /* 工作模式（发送、接收、双向） */
    uint32_t HardwareFlowControl;     /* 硬件流控（RTS/CTS） */
    uint32_t OverSampling;            /* 超采样 */
    uint32_t ReceiverTimeout;         /* 接收超时 */
} UART_Properties;

typedef int8_t status;

/* UART 操作函数原型 */
typedef status (*UART_TransmitFn)(UART_Properties *, uint8_t *, uint16_t, uint32_t);
typedef status (*UART_ReceiveFn)(UART_Properties *, uint8_t *, uint16_t, uint32_t);
typedef status (*UART_TransmitITFn)(UART_Properties *, uint8_t *, uint16_t);
typedef status (*UART_ReceiveITFn)(UART_Properties *, uint8_t *, uint16_t);
typedef status (*UART_TransmitDMAFn)(UART_Properties *, uint8_t *, uint16_t);
typedef status (*UART_ReceiveDMAFn)(UART_Properties *, uint8_t *, uint16_t);

typedef status (*UART_AbortFn)(UART_Properties *);

/* 行为定义 */
typedef struct {
    int8_t (*HAL_UART_Init)(UART_Properties *);
    int8_t (*HAL_UART_DeInit)(UART_Properties *);
    void (*HAL_UART_MspInit)(UART_Properties *);
    void (*HAL_UART_MspDeInit)(UART_Properties *);

    UART_TransmitFn UART_Transmit;
    UART_ReceiveFn UART_Receive;

    UART_TransmitITFn UART_Transmit_IT;
    UART_ReceiveITFn UART_Receive_IT;

    UART_TransmitDMAFn UART_Transmit_DMA;
    UART_ReceiveDMAFn UART_Receive_DMA;

    UART_AbortFn UART_Abort;
} UART_Hehavior;

/* 对象定义 */
typedef struct {
    UART_Properties uartProperties;
    UART_Hehavior *uartBehavior;
} Hal_UartStru;

/* 函数声明 */
Hal_UartStru* HAL_UART_GetHandle(uint8_t uartIndex){
    static Hal_UartStru halUart[UART_ID_MAX];
    return &halUart[uartIndex];
}

