// File: hal_uart.c

#include "hal_uart.h"
#include "stm32h7xx_hal.h"


// Static UART list and behavior instances
static Hal_UartStru g_uartList[UART_ID_MAX] = 
{
    {
        .uartProperties.BaudRate = 115200,
        .uartProperties.WordLength = UART_WORDLENGTH_8B,
        .uartProperties.StopBits = UART_STOPBITS_1,
        .uartProperties.Parity = UART_PARITY_NONE,
        .uartProperties.Mode = UART_MODE_TX_RX,
        .uartProperties.HwFlowCtl = UART_HWCONTROL_NONE,
        .uartProperties.OverSampling = UART_OVERSAMPLING_16,
    },
    // Other UART configurations can be added here
};

static UART_Behavior g_uartHost;

// Function to initialize UART behavior from vendor
void HAL_UART_InitHookFromVendor(void)
{
    g_uartHost.HAL_UART_InitFn = HAL_UART_Init;
    g_uartHost.HAL_UART_DeInitFn = HAL_UART_DeInit;
    g_uartHost.HAL_UART_MspInitFn = HAL_UART_MspInit;
    g_uartHost.HAL_UART_MspDeInitFn = HAL_UART_MspDeInit;
    g_uartHost.UART_Transmit = HAL_UART_Transmit;
    g_uartHost.UART_Receive = HAL_UART_Receive;
    g_uartHost.UART_Transmit_IT = HAL_UART_Transmit_IT;
    g_uartHost.UART_Receive_IT = HAL_UART_Receive_IT;
    g_uartHost.UART_Transmit_DMA = HAL_UART_Transmit_DMA;
    g_uartHost.UART_Receive_DMA = HAL_UART_Receive_DMA;

    for (uint32_t i = 0; i < UART_ID_MAX; i++) {
        g_uartList[i].uartBehavior = &g_uartHost;
    }
}

// Function to get UART handle
Hal_UartStru* HAL_UART_GetHandle(uint8_t uartIndex)
{
    if (uartIndex >= UART_ID_MAX) {
        return NULL;
    }
    return &g_uartList[uartIndex];
}