#include "hal_adc.h"
#include "stm32h7xx_hal.h"

/* File and function for debugging */
static Hal_AdcStru g_adcList[ADC_ID_MAX] = {
    { },
    { },
    { },
    { },
    {
        // .adcProperties.Resolution = ADC_RESOLUTION_12B,
        .adcProperties.ScanConvMode = ADC_SCAN_DISABLE,
        // .adcProperties.ContinuousConvMode = ADC_CONTINUOUS_CONV_ENABLE,
        // .adcProperties.DiscontinuousConvMode = ADC_DISC_MODE_DISABLE,
        .adcProperties.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE,
        // .adcProperties.ExternalTrigConv = ADC_EXTERNALTRIGCONV_T1_CC1,
        // .adcProperties.DataAlign = ADC_DATAALIGN_RIGHT,
        .adcProperties.NbrOfConversion = 1,
        // .adcProperties.SamplingTime = ADC_SAMPLETIME_3CYCLES,
    },
    { },
    { },
};

static ADC_Behavior g_adcHost;

void HAL_ADC_InitHookFromVendor(void) {
    g_adcHost.HAL_ADC_InitFn = HAL_ADC_Init;
    g_adcHost.HAL_ADC_DeInitFn = HAL_ADC_DeInit;
    g_adcHost.HAL_ADC_MspInitFn = HAL_ADC_MspInit;
    g_adcHost.HAL_ADC_MspDeInitFn = HAL_ADC_MspDeInit;

    g_adcHost.ADC_Start = HAL_ADC_Start;
    g_adcHost.ADC_Stop = HAL_ADC_Stop;
    g_adcHost.ADC_PollForConversion = HAL_ADC_PollForConversion;
    g_adcHost.ADC_GetValue = HAL_ADC_GetValue;

    g_adcHost.ADC_Start_IT = HAL_ADC_Start_IT;
    g_adcHost.ADC_Stop_IT = HAL_ADC_Stop_IT;

    for (uint32_t i = 0; i < ADC_ID_MAX; i++) {
        g_adcList[i].adcBehavior = &g_adcHost;
    }
}

Hal_AdcStru* HAL_ADC_GetHandle(uint8_t adcIndex) {
    if (adcIndex >= ADC_ID_MAX) {
        return NULL;
    }
    return &g_adcList[adcIndex];
}
