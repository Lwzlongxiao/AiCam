#ifndef __HAL_GPIO_H
#define __HAL_GPIO_H

#include <stdint.h>
#include "stm32h7xx_hal.h"

/* GPIO ID定义 */
enum {
    GPIO_ID0 = 0,
    GPIO_ID1 = 1,
    GPIO_ID2 = 2,
    GPIO_ID3 = 3,
    GPIO_ID4 = 4,
    GPIO_ID5 = 5,
    GPIO_ID6 = 6,
    GPIO_ID7 = 7,
    GPIO_ID_MAX = 8
};

/* 属性定义 */
typedef struct {
    uint32_t Pin;
    uint32_t Mode;
    uint32_t Pull;
    uint32_t Speed;
    uint32_t Alternate;    
} GPIO_Properties;

typedef int8_t status;
typedef status (*GPIO_WritePinFn)(GPIO_Properties *, GPIO_PinState);
typedef GPIO_PinState (*GPIO_ReadPinFn)(GPIO_Properties *);

typedef status (*GPIO_InitFn)(GPIO_Properties *);
typedef status (*GPIO_DeInitFn)(GPIO_Properties *);
typedef void (*GPIO_MspInitFn)(GPIO_Properties *);
typedef void (*GPIO_MspDeInitFn)(GPIO_Properties *);

/* 行为定义 */
typedef struct {
    GPIO_InitFn HAL_GPIO_Init;
    GPIO_DeInitFn HAL_GPIO_DeInit;
    GPIO_MspInitFn HAL_GPIO_MspInit;
    GPIO_MspDeInitFn HAL_GPIO_MspDeInit;
    
    GPIO_WritePinFn GPIO_WritePin;
    GPIO_ReadPinFn GPIO_ReadPin;
} GPIO_Hehavior;

/* 对象定义 */
typedef struct {
    GPIO_Properties gpioProperties;
    GPIO_Hehavior *gpioBehavior;
} Hal_GpioStru;

/* 函数声明 */
void HAL_GPIO_InitHookFromVendor(void);
Hal_GpioStru* HAL_GPIO_GetHandle(uint8_t gpioIndex);

#endif
