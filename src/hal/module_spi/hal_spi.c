#include "hal_spi.h"
#include "stm32h7xx_hal.h"

/* 文件和函数用于调试 */
static Hal_SpiStru g_spiList[SPI_ID_MAX] = {
    { },
    { },
    { },
    {
        .spiProperties.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16,
        .spiProperties.Direction = SPI_DIRECTION_2LINES,
        .spiProperties.Mode = SPI_MODE_MASTER,
        .spiProperties.DataSize = SPI_DATASIZE_8BIT,
        .spiProperties.ClockPolarity = SPI_POLARITY_LOW,
        .spiProperties.ClockPhase = SPI_PHASE_1EDGE,
        .spiProperties.NSS = SPI_NSS_SOFT,
        .spiProperties.FirstBit = SPI_FIRSTBIT_MSB,
        .spiProperties.CRCPolynomial = 7,  // 如果需要CRC功能可配置
    },
};

/* SPI行为定义 */
static SPI_Behavior g_spiHost;

void HAL_SPI_InitHookFromVendor(void) {
    /* SPI初始化函数 */
    g_spiHost.HAL_SPI_InitFn = HAL_SPI_Init;
    g_spiHost.HAL_SPI_DeInitFn = HAL_SPI_DeInit;
    g_spiHost.HAL_SPI_MspInitFn = HAL_SPI_MspInit;
    g_spiHost.HAL_SPI_MspDeInitFn = HAL_SPI_MspDeInit;

    g_spiHost.SPI_Transmit = HAL_SPI_Transmit;
    g_spiHost.SPI_Receive = HAL_SPI_Receive;
    g_spiHost.SPI_TransmitReceive = HAL_SPI_TransmitReceive;

    g_spiHost.SPI_Transmit_IT = HAL_SPI_Transmit_IT;
    g_spiHost.SPI_Receive_IT = HAL_SPI_Receive_IT;

    /* 初始化所有SPI实例 */
    for (uint32_t i = 0; i < SPI_ID_MAX; i++) {
        g_spiList[i].spiBehavior = &g_spiHost;
    }
}

/* 获取SPI实例的句柄 */
Hal_SpiStru* HAL_SPI_GetHandle(uint8_t spiIndex) {
    if (spiIndex >= SPI_ID_MAX) {
        return NULL;
    }
    return &g_spiList[spiIndex];
}
