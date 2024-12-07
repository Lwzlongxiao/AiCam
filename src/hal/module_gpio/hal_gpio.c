#include "hal_gpio.h"

// 文件名+函数+行号printf做debug
static Hal_GpioStru g_gpioList[GPIO_ID_MAX] = 
{
    {},
    {},
    {},
    {},
    {
        .gpioProperties.Pin = GPIO_PIN_0,
        .gpioProperties.Mode = GPIO_MODE_OUTPUT_PP,
        .gpioProperties.Pull = GPIO_NOPULL,
        .gpioProperties.Speed = GPIO_SPEED_FREQ_LOW,
    },
    {},
    {},
};

static GPIO_Hehavior g_gpioHost;

void HAL_GPIO_InitHookFromVendor(void)
{
    g_gpioHost.HAL_GPIO_Init = HAL_GPIO_Init;
    g_gpioHost.HAL_GPIO_DeInit = HAL_GPIO_DeInit;
    // g_gpioHost.HAL_GPIO_MspInit = HAL_GPIO_MspInit;
    // g_gpioHost.HAL_GPIO_MspDeInit = HAL_GPIO_MspDeInit;
    g_gpioHost.GPIO_WritePin = HAL_GPIO_WritePin;
    g_gpioHost.GPIO_ReadPin = HAL_GPIO_ReadPin;

    for (uint32_t i = 0; i < GPIO_ID_MAX; i++) {
        g_gpioList[i].gpioBehavior = &g_gpioHost;
    }
}

Hal_GpioStru* HAL_GPIO_GetHandle(uint8_t gpioIndex)
{
    if (gpioIndex >= GPIO_ID_MAX) {
        return NULL;
    }
    return &g_gpioList[gpioIndex];
}
