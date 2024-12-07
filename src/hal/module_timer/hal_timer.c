#include "hal_timer.h"

// 文件名+函数+行号printf做debug
static Hal_TimerStru g_timerList[TIMER_ID_MAX] = 
{
    {
        // 定时器0配置
    },
    {
        // 定时器1配置
    },
    {
        // 定时器2配置
    },
    {
        // 定时器3配置
    },
    {
        .timerProperties.Prescaler = 0,
        .timerProperties.CounterMode = TIM_COUNTERMODE_UP,
        .timerProperties.Period = 1000,
        .timerProperties.ClockDivision = TIM_CLOCKDIVISION_DIV1,
        .timerProperties.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE,
    },
    {
        // 定时器5配置
    },
    {
        // 定时器6配置
    },
    {
        // 定时器7配置
    }
};

static TIM_Hehavior g_timerHost;

void HAL_TimerInitHookFromVendor(void)
{
    g_timerHost.HAL_TIM_InitFn = HAL_TIM_Base_Init;
    g_timerHost.HAL_TIM_DeInitFn = HAL_TIM_Base_DeInit;
    // g_timerHost.HAL_TIM_MspInitFn = HAL_TIM_MspInit;
    // g_timerHost.HAL_TIM_MspDeIniFn = HAL_TIM_MspDeInit;

    g_timerHost.TIM_BaseStart = HAL_TIM_Base_Start;
    g_timerHost.TIM_BaseStop = HAL_TIM_Base_Stop;
    g_timerHost.TIM_BaseStart_IT = HAL_TIM_Base_Start_IT;
    g_timerHost.TIM_BaseStop_IT = HAL_TIM_Base_Stop_IT;

    g_timerHost.TIM_PWMStart = HAL_TIM_PWM_Start;
    g_timerHost.TIM_PWMStop = HAL_TIM_PWM_Stop;
    g_timerHost.TIM_PWMStart_IT = HAL_TIM_PWM_Start_IT;
    g_timerHost.TIM_PWMStop_IT = HAL_TIM_PWM_Stop_IT;

    for (uint32_t i = 0; i < TIMER_ID_MAX; i++) {
        g_timerList[i].timerBehavior = &g_timerHost;
    }
}

Hal_TimerStru* HAL_TIMER_GetHandle(uint8_t timerIndex)
{
    if (timerIndex >= TIMER_ID_MAX) {
        return NULL;
    }
    return &g_timerList[timerIndex];
}
