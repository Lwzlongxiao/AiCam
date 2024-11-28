#ifndef __HAL_SPI_H
#define __HAL_SPI_H

#include <stdint.h>

/* SPI ID定义 */
enum {
    SPI_ID0 = 0,
    SPI_ID1 = 1,
    SPI_ID2 = 2,
    SPI_ID3 = 3,
    SPI_ID_MAX = 4
};

/* SPI属性定义 */
typedef struct {
    uint32_t BaudRatePrescaler;    /* 波特率预分频器 */
    uint32_t Direction;            /* 数据传输方向（全双工、单向） */
    uint32_t Mode;                 /* SPI工作模式（主模式/从模式） */
    uint32_t DataSize;             /* 数据大小（8位/16位） */
    uint32_t ClockPolarity;        /* 时钟极性 */
    uint32_t ClockPhase;           /* 时钟相位 */
    uint32_t NSS;                  /* NSS管理方式 */
    uint32_t FirstBit;             /* 数据传输顺序（MSB/LSB） */
    uint32_t CRCPolynomial;        /* CRC多项式 */
} SPI_Properties;

typedef int8_t status;

typedef status (*SPI_TransmitFn)(SPI_Properties *, uint8_t *, uint16_t);
typedef status (*SPI_ReceiveFn)(SPI_Properties *, uint8_t *, uint16_t);
typedef status (*SPI_TransmitReceiveFn)(SPI_Properties *, uint8_t *, uint8_t *, uint16_t);
typedef status (*SPI_Transmit_ITFn)(SPI_Properties *, uint8_t *, uint16_t);
typedef status (*SPI_Receive_ITFn)(SPI_Properties *, uint8_t *, uint16_t);

/* SPI行为定义 */
typedef struct {
    int8_t (*HAL_SPI_InitFn)(SPI_Properties);
    int8_t (*HAL_SPI_DeInitFn)(SPI_Properties);
    void (*HAL_SPI_MspInitFn)(SPI_Properties);
    void (*HAL_SPI_MspDeInitFn)(SPI_Properties);

    SPI_TransmitFn SPI_Transmit;
    SPI_ReceiveFn SPI_Receive;
    SPI_TransmitReceiveFn SPI_TransmitReceive;

    SPI_Transmit_ITFn SPI_Transmit_IT;
    SPI_Receive_ITFn SPI_Receive_IT;
} SPI_Behavior;

/* SPI对象定义 */
typedef struct {
    SPI_Properties spiProperties;  /* SPI的配置属性 */
    SPI_Behavior *spiBehavior;    /* SPI的行为（函数指针） */
} Hal_SpiStru;

/* 函数声明 */
void HAL_SPI_InitHookFromVendor(void);
Hal_SpiStru* HAL_SPI_GetHandle(uint8_t spiIndex);

#endif /* __HAL_SPI_H */
