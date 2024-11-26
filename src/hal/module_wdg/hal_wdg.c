#include "stm32h7xx_hal.h"
#include "hal_wdg.h"

/* 看门狗定时器ID定义 */
enum {
    WDG_ID0 = 0,
    WDG_ID1 = 1,
    WDG_ID_MAX = 2
};

/* 看门狗属性定义 */
typedef struct {
    uint32_t Timeout;         /* 超时时间 */
    uint32_t Reload;          /* 重载值 */
    uint32_t Window;          /* 窗口值 */
} WDG_Properties;

typedef int8_t status;

/* 看门狗操作函数原型 */
typedef status (*WDG_StartFn)(WDG_Properties *);
typedef status (*WDG_FeedFn)(WDG_Properties *);
typedef status (*WDG_StopFn)(WDG_Properties *);

/* 行为定义 */
typedef struct {
    int8_t (*HAL_WDG_Init)(WDG_Properties *wdgProperties);
    int8_t (*HAL_WDG_DeInit)(WDG_Properties *wdgProperties);

    WDG_StartFn WDG_Start;
    WDG_FeedFn WDG_Feed;
    WDG_StopFn WDG_Stop;
} WDG_Behavior;

/* 对象定义 */
typedef struct {
    WDG_Properties wdgProperties;
    WDG_Behavior *wdgBehavior;
} Hal_WdgStru;

/* 函数声明 */
Hal_WdgStru* HAL_WDG_GetHandle(uint8_t wdgIndex) {
    static Hal_WdgStru wdgHandles[WDG_ID_MAX];
    // 根据wdgIndex返回对应的看门狗句柄
    return &wdgHandles[wdgIndex];
}