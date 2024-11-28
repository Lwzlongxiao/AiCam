#include "hal_dcmi.h"
#include "stm32h7xx_hal_dcmi.h"

// DCMI list, you can extend this if there are more DCMI peripherals
static Hal_DCMI_Stru g_dcmiList[DCMI_ID_MAX] = {
    {
        // Initialize properties for DCMI_ID0 (if needed)
    },
    {
        // Initialize properties for DCMI_ID1 (if needed)
    }
};

static DCMI_Behavior g_dcmiHost;

void HAL_DCMI_InitHookFromVendor(void)
{
    g_dcmiHost.DCMI_Init = HAL_DCMI_Init;
    g_dcmiHost.DCMI_DeInit = HAL_DCMI_DeInit;
    g_dcmiHost.DCMI_StartCapture = HAL_DCMI_StartCapture;
    g_dcmiHost.DCMI_StopCapture = HAL_DCMI_StopCapture;

    for (uint32_t i = 0; i < DCMI_ID_MAX; i++) {
        g_dcmiList[i].dcmiBehavior = &g_dcmiHost;
    }
}

Hal_DCMI_Stru* HAL_DCMI_GetHandle(uint8_t dcmiIndex)
{
    if (dcmiIndex >= DCMI_ID_MAX) {
        return NULL;
    }
    return &g_dcmiList[dcmiIndex];
}
