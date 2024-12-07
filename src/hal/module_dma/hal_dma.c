#include "hal_dma.h"
#include "stm32h7xx_hal.h"

/* DMA对象定义 */
static Hal_DMA_Stru g_dmaList[DMA_ID_MAX] = {
    { },
    { },
    { },
    { },
    { },
    { },
    { },
    { }
};

/* DMA行为定义 */
static DMA_Behavior g_dmaHost;

void HAL_DMA_InitHookFromVendor(void) {
    /* DMA初始化函数 */
    g_dmaHost.HAL_DMA_InitFn = HAL_DMA_Init;
    g_dmaHost.HAL_DMA_DeInitFn = HAL_DMA_DeInit;
    // g_dmaHost.HAL_DMA_MspInitFn = HAL_DMA_MspInit;
    // g_dmaHost.HAL_DMA_MspDeInitFn = HAL_DMA_MspDeInit;

    // g_dmaHost.DMA_Transmit = HAL_DMA_Transmit;
    // g_dmaHost.DMA_Receive = HAL_DMA_Receive;

    // g_dmaHost.DMA_Transmit_IT = HAL_DMA_Transmit_IT;
    // g_dmaHost.DMA_Receive_IT = HAL_DMA_Receive_IT;

    /* 初始化所有DMA实例 */
    for (uint32_t i = 0; i < DMA_ID_MAX; i++) {
        g_dmaList[i].dmaBehavior = &g_dmaHost;
    }
}

/* 获取DMA实例的句柄 */
Hal_DMA_Stru* HAL_DMA_GetHandle(uint8_t dmaIndex) {
    if (dmaIndex >= DMA_ID_MAX) {
        return NULL;
    }
    return &g_dmaList[dmaIndex];
}
