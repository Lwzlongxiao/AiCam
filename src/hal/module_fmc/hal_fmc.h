#ifndef __HAL_FMC_H
#define __HAL_FMC_H

#include <stdint.h>

/* FMC ID定义 */
enum {
    FMC_ID0 = 0,
    FMC_ID1 = 1,
    FMC_ID_MAX = 2
};

/* 属性定义 */
typedef struct {
    uint32_t Bank;          /* FMC Bank选择 */
    uint32_t MemoryType;    /* 存储器类型，例如NOR或NAND */
    uint32_t WaitSignal;    /* 等待信号配置 */
    uint32_t Timing;        /* 时序设置 */
} FMC_Properties;

/* 定义返回值类型 */
typedef int8_t status;

/* 定义FMC操作函数指针类型 */
typedef status (*FMC_InitFn)(FMC_Properties *);
typedef status (*FMC_DeInitFn)(FMC_Properties *);
typedef status (*FMC_ReadFn)(FMC_Properties *, uint32_t, uint8_t *, uint32_t);
typedef status (*FMC_WriteFn)(FMC_Properties *, uint32_t, uint8_t *, uint32_t);

/* 行为定义 */
typedef struct {
    FMC_InitFn FMC_Init;
    FMC_DeInitFn FMC_DeInit;
    FMC_ReadFn FMC_Read;
    FMC_WriteFn FMC_Write;
} FMC_Hehavior;

/* 对象定义 */
typedef struct {
    FMC_Properties fmcProperties;
    FMC_Hehavior *fmcBehavior;
} Hal_FmcStru;

/* 函数声明 */
void HAL_FMC_InitHookFromVendor(void);
Hal_FmcStru* HAL_FMC_GetHandle(uint8_t fmcIndex);

#endif
