#ifndef __HAL_WDG_H
#define __HAL_WDG_H

#include <stdint.h>

/* WDG ID定义 */
enum {
    WDG_ID0 = 0,
    WDG_ID1 = 1,
    WDG_ID_MAX = 2
};

/* 属性定义 */
typedef struct {
    uint32_t Timeout; /* 超时时间：单位为毫秒 */
    uint32_t Reload;  /* 重装载值 */
    uint32_t ClockSource; /* 时钟源 */
    uint32_t Prescaler; /* 预分频器 */
} WDG_Properties;

typedef int8_t status;
typedef status (*WDG_StartFn)(WDG_Properties *);
typedef status (*WDG_StopFn)(WDG_Properties *);
typedef status (*WDG_RefreshFn)(WDG_Properties *);

/* 行为定义 */
typedef struct{
    int8_t (*HAL_WDG_Init)(WDG_Properties);
    int8_t (*HAL_WDG_DeInit)(WDG_Properties);
    void (*HAL_WDG_MspInit)(WDG_Properties);
    void (*HAL_WDG_MspDeInit)(WDG_Properties);

    WDG_StartFn WDG_Start;
    WDG_StopFn WDG_Stop;
    WDG_RefreshFn WDG_Refresh;
} WDG_Behavior;

/* 对象定义 */
typedef struct
{
    WDG_Properties wdgProperties;
    WDG_Behavior *wdgBehavior;
} Hal_WdgStru;

/* 函数声明 */
void HAL_WDG_InitHookFromVendor(void);
Hal_WdgStru* HAL_WDG_GetHandle(uint8_t wdgIndex);

#endif