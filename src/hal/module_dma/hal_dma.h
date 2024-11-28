#ifndef __HAL_DMA_H
#define __HAL_DMA_H

#include <stdint.h>

/* DMA流和通道的定义 */
#define DMA_CHANNEL0      0
#define DMA_CHANNEL1      1
#define DMA_CHANNEL2      2
#define DMA_CHANNEL3      3
#define DMA_CHANNEL4      4
#define DMA_CHANNEL5      5
#define DMA_CHANNEL6      6
#define DMA_CHANNEL7      7

#define DMA_ID_MAX        8

/* DMA配置属性定义 */
typedef struct {
    uint32_t Channel;        /* DMA通道 */
    uint32_t Direction;      /* 数据传输方向（内存到外设、外设到内存等） */
    uint32_t PeriphInc;      /* 外设地址是否递增 */
    uint32_t MemInc;         /* 内存地址是否递增 */
    uint32_t PeriphDataAlignment; /* 外设数据对齐方式 */
    uint32_t MemDataAlignment;    /* 内存数据对齐方式 */
    uint32_t Mode;           /* DMA模式（正常、循环等） */
    uint32_t Priority;       /* DMA优先级 */
    uint32_t M2M;            /* 内存到内存模式 */
} DMA_Properties;

typedef int8_t status;

/* DMA操作函数类型 */
typedef status (*DMA_TransmitFn)(DMA_Properties *, uint32_t, uint32_t, uint32_t);
typedef status (*DMA_ReceiveFn)(DMA_Properties *, uint32_t, uint32_t, uint32_t);
typedef status (*DMA_Transmit_ITFn)(DMA_Properties *, uint32_t, uint32_t, uint32_t);
typedef status (*DMA_Receive_ITFn)(DMA_Properties *, uint32_t, uint32_t, uint32_t);

/* DMA行为定义 */
typedef struct {
    int8_t (*HAL_DMA_InitFn)(DMA_Properties);
    int8_t (*HAL_DMA_DeInitFn)(DMA_Properties);
    void (*HAL_DMA_MspInitFn)(DMA_Properties);
    void (*HAL_DMA_MspDeInitFn)(DMA_Properties);

    DMA_TransmitFn DMA_Transmit;
    DMA_ReceiveFn DMA_Receive;

    DMA_Transmit_ITFn DMA_Transmit_IT;
    DMA_Receive_ITFn DMA_Receive_IT;
} DMA_Behavior;

/* DMA对象定义 */
typedef struct {
    DMA_Properties dmaProperties;  /* DMA的配置属性 */
    DMA_Behavior *dmaBehavior;     /* DMA的行为（函数指针） */
} Hal_DMA_Stru;

/* 函数声明 */
void HAL_DMA_InitHookFromVendor(void);
Hal_DMA_Stru* HAL_DMA_GetHandle(uint8_t dmaIndex);

#endif /* __HAL_DMA_H */
