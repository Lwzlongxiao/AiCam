#ifndef _MODULE_WDG_H
#define _MODULE_WDG_H

#include <stdint.h>

// 定义看门狗定时器的ID和地址（假设值）
#define WDG_ID 1
#define WDG_ADDR 0x40

// 定义看门狗定时器的相关寄存器（假设值）
#define WDG_REG_CONTROL 0x00
#define WDG_REG_TIMEOUT 0x01
#define WDG_REG_RESET 0x02

// 函数声明
void Adapter_Wdg_Init(void); // 初始化看门狗定时器
void Adapter_Wdg_SetTimeout(uint8_t timeout); // 设置看门狗定时器的超时时间
void Adapter_Wdg_Kick(void); // “踢”看门狗，防止重启

#endif /* _MODULE_WDG_H */