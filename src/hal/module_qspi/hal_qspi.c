#include "hal_qspi.h"
#include "stm32h7xx_hal_qspi.h"

// 文件名+函数+行号printf做dbug
static Hal_QspiStru g_qspiList[QSPI_ID_MAX] = 
{
    {
        // 配置QSP0属性
    },
    {
        // 配置QSP1属性
    }
};

static QSPI_Hehavior g_qspiHost;

void HAL_QSPI_InitHookFromVendor(void)
{
    // 初始化行为函数指针
    g_qspiHost.HAL_QSPI_Init = HAL_QSPI_Init;
    g_qspiHost.HAL_QSPI_DeInit = HAL_QSPI_DeInit;
    g_qspiHost.HAL_QSPI_MspInit = HAL_QSPI_MspInit;
    g_qspiHost.HAL_QSPI_MspDeInit = HAL_QSPI_MspDeInit;

    g_qspiHost.QSPI_Transmit = HAL_QSPI_Transmit;
    g_qspiHost.QSPI_Receive = HAL_QSPI_Receive;
    g_qspiHost.QSPI_Write_IT = HAL_QSPI_Write_IT;
    g_qspiHost.QSPI_Read_IT = HAL_QSPI_Read_IT;

    g_qspiHost.QSPI_Transmit_DMA = HAL_QSPI_Transmit_DMA;
    g_qspiHost.QSPI_Receive_DMA = HAL_QSPI_Receive_DMA;

    // 将行为指针绑定到Qspi对象
    for (uint32_t i = 0; i < QSPI_ID_MAX; i++) {
        g_qspiList[i].qspiBehavior = &g_qspiHost;
    }
}

Hal_QspiStru* HAL_QSPI_GetHandle(uint8_t qspiIndex)
{
    if (qspiIndex >= QSPI_ID_MAX) {
        return NULL;
    }
    return &g_qspiList[qspiIndex];
}
