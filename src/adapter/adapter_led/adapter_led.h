#ifndef _ADAPTER_LED_H
#define _ADAPTER_LED_H

#include <stdint.h>
#include "hal_i2c.h"
#include <stddef.h>

enum {
    LED_ON = 1,
    LED_OFF = 0
};

void Adapter_LedInit(void);
void Adapter_LedSet(uint8_t led, uint8_t state);
void Adapter_LedSetAll(uint8_t state);
void Adapter_LedToggle(uint8_t led);
void Adapter_LedToggleAll(void);
void Adapter_LedGet(uint8_t led, uint8_t *state);
void Adapter_LedGetAll(uint8_t *state);

#endif /* _ADAPTER_LED_H */