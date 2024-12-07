#include "hal_fmc.h"
#include "stm32h7xx_hal.h"

// 文件名+函数+行号printf做debug
static Hal_FmcStru g_fmcList[FMC_ID_MAX] = 
{
    {
        // 这里可以初始化每个FMC的属性
    },
    {
        // 这里可以初始化每个FMC的属性
    }
};

static FMC_Hehavior g_fmcHost;

void HAL_FMC_InitHookFromVendor(void)
{
    // g_fmcHost.FMC_Init = HAL_FMC_Init;
    // g_fmcHost.FMC_DeInit = HAL_FMC_DeInit;
    // g_fmcHost.FMC_Read = HAL_FMC_Read;
    // g_fmcHost.FMC_Write = HAL_FMC_Write;

    // 为每个FMC实例赋值对应的行为
    for (uint32_t i = 0; i < FMC_ID_MAX; i++) {
        g_fmcList[i].fmcBehavior = &g_fmcHost;
    }
}

Hal_FmcStru* HAL_FMC_GetHandle(uint8_t fmcIndex)
{
    if (fmcIndex >= FMC_ID_MAX) {
        return NULL;
    }
    return &g_fmcList[fmcIndex];
}
