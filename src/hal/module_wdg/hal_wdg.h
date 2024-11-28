#ifndef __HAL_WDG_H
#define __HAL_WDG_H

#include <stdint.h>

/* WDG ID定义 */
enum {
    WDG_ID0 = 0,
    WDG_ID1 = 1,
    WDG_ID2 = 2,
    WDG_ID3 = 3,
    WDG_ID4 = 4,
    WDG_ID5 = 5,
    WDG_ID6 = 6,
    WDG_ID7 = 7,
    WDG_ID_MAX = 8
};

/* 属性定义 */
typedef struct {
    uint32_t Prescaler;
    uint32_t Reload;
} WDG_Properties;

typedef int8_t status;
typedef status (*WDG_RefreshFn)(WDG_Properties *);

/* 行为定义 */
typedef struct{
    int8_t (*HAL_WDG_InitFn)(WDG_Properties);
    int8_t (*HAL_WDG_DeInitFn)(WDG_Properties);

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