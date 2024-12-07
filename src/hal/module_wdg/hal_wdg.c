#include "hal_wdg.h"
#include "stm32h7xx_hal.h"

// 文件名+函数+行号printf做dbug
static Hal_WdgStru g_wdgList[WDG_ID_MAX] = 
{
    {

    },
    {

    },
    {

    },
    {

    },
    {
        .wdgProperties.Prescaler = IWDG_PRESCALER_64,
        .wdgProperties.Reload = 4095,
    },
    {

    },
    {

    },
};
static WDG_Behavior g_wdgHost;

void HAL_WDG_InitHookFromVendor(void)
{
    g_wdgHost.HAL_WDG_InitFn = HAL_IWDG_Init;
    g_wdgHost.HAL_WDG_DeInitFn = HAL_IWDG_Refresh;

    for (uint32_t i = 0; i < WDG_ID_MAX; i++) {
        g_wdgList[i].wdgBehavior = &g_wdgHost;
    }
}

Hal_WdgStru* HAL_WDG_GetHandle(uint8_t wdgIndex)
{
    if (wdgIndex >= WDG_ID_MAX) {
        return NULL;
    }
    return &g_wdgList[wdgIndex];
}
