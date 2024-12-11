#include "adapter_led.h"
#include "adapter_pca9555.h"

void Adapter_LedInit(void)
{
    // Initialize LED GPIO
    Adapter_Pca9555SetOutputMode(PCA9555_PIN6); // Set all PCA9555 pins as output
    // Set LED GPIO as output
    Adapter_Pca9555SetGPIOOutputStatus(PCA9555_PIN6, PCA9555_PIN_SET); // Set all PCA9555 pins as high
    // Set initial LED state
}

void Adapter_LedSet(uint8_t led, uint8_t state)
{
    if (state == LED_ON) {
        Adapter_Pca9555SetGPIOOutputStatus(PCA9555_PIN6, PCA9555_PIN_SET); // Set all PCA9555 pins as high
    } else {
        Adapter_Pca9555SetGPIOOutputStatus(PCA9555_PIN6, PCA9555_PIN_RESET); // Set all PCA9555 pins as low
    } 
}

void Adapter_LedSetAll(uint8_t state)
{
    // Set all LED state
}

void Adapter_LedToggle(uint8_t led)
{
    // Toggle specific LED state
        
}

void Adapter_LedToggleAll(void)
{
    // Toggle all LED state
}

void Adapter_LedGet(uint8_t led, uint8_t *state)
{
    // Get specific LED state
}

void Adapter_LedGetAll(uint8_t *state)
{
    // Get all LED state
}
