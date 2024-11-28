#ifndef __HAL_TIMER_H
#define __HAL_TIMER_H

#include <stdint.h>
#include "stm32h7xx_hal_tim.h"

/* 定时器ID定义 */
enum {
    TIMER_ID0 = 0,
    TIMER_ID1 = 1,
    TIMER_ID2 = 2,
    TIMER_ID3 = 3,
    TIMER_ID4 = 4,
    TIMER_ID5 = 5,
    TIMER_ID6 = 6,
    TIMER_ID7 = 7,
    TIMER_ID_MAX = 8
};

/* 定时器属性定义 */
typedef struct {
    uint32_t Prescaler;                // 预分频值
    uint32_t CounterMode;              // 计数模式
    uint32_t Period;                   // 自动重装载周期
    uint32_t ClockDivision;            // 时钟分频
    uint32_t AutoReloadPreload;        // 自动重装载预加载
} TIMER_Properties;

typedef int8_t status;
typedef status (*TIM_BaseStartFn)(TIM_HandleTypeDef *);
typedef status (*TIM_BaseStopFn)(TIM_HandleTypeDef *);
typedef status (*TIM_BaseStartITFn)(TIM_HandleTypeDef *);
typedef status (*TIM_BaseStopITFn)(TIM_HandleTypeDef *);

typedef status (*TIM_PWMStartFn)(TIM_HandleTypeDef *);
typedef status (*TIM_PWMStopFn)(TIM_HandleTypeDef *);
typedef status (*TIM_PWMStartITFn)(TIM_HandleTypeDef *);
typedef status (*TIM_PWMStopITFn)(TIM_HandleTypeDef *);

/* 定时器行为定义 */
typedef struct{
    int8_t (*HAL_TIM_InitFn)(TIM_HandleTypeDef *);
    int8_t (*HAL_TIM_DeInitFn)(TIM_HandleTypeDef *);
    void (*HAL_TIM_MspInitFn)(TIM_HandleTypeDef *);
    void (*HAL_TIM_MspDeInitFn)(TIM_HandleTypeDef *);

    TIM_BaseStartFn TIM_BaseStart;
    TIM_BaseStopFn TIM_BaseStop;
    TIM_BaseStartITFn TIM_BaseStart_IT;
    TIM_BaseStopITFn TIM_BaseStop_IT;

    TIM_PWMStartFn TIM_PWMStart;
    TIM_PWMStopFn TIM_PWMStop;
    TIM_PWMStartITFn TIM_PWMStart_IT;
    TIM_PWMStopITFn TIM_PWMStop_IT;
} TIM_Hehavior;

/* 定时器对象定义 */
typedef struct
{
    TIMER_Properties timerProperties;
    TIM_Hehavior *timerBehavior;
} Hal_TimerStru;

/* 函数声明 */
void HAL_TimerInitHookFromVendor(void);
Hal_TimerStru* HAL_TIMER_GetHandle(uint8_t timerIndex);

#endif
