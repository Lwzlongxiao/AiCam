#ifndef __HAL_DCMI_H
#define __HAL_DCMI_H

#include <stdint.h>

/* DCMI ID Definitions */
enum {
    DCMI_ID0 = 0,
    DCMI_ID1 = 1,
    DCMI_ID_MAX = 2
};

/* DCMI properties structure */
typedef struct {
    uint32_t FrameRate;   /* Frame rate */
    uint32_t DataWidth;   /* Data width (e.g., 8-bit, 10-bit, etc.) */
    uint32_t SynchroMode; /* Synchronization mode */
    uint32_t CaptureMode; /* Capture mode (continuous, single shot) */
    uint32_t PixelFormat; /* Pixel format */
} DCMI_Properties;

typedef int8_t status;

/* Function prototypes for DCMI operations */
typedef status (*DCMI_InitFn)(DCMI_Properties *);
typedef status (*DCMI_DeInitFn)(DCMI_Properties *);
typedef status (*DCMI_StartCaptureFn)(DCMI_Properties *);
typedef status (*DCMI_StopCaptureFn)(DCMI_Properties *);

/* DCMI Behavior structure */
typedef struct {
    DCMI_InitFn DCMI_Init;
    DCMI_DeInitFn DCMI_DeInit;
    DCMI_StartCaptureFn DCMI_StartCapture;
    DCMI_StopCaptureFn DCMI_StopCapture;
} DCMI_Behavior;

/* DCMI Object structure */
typedef struct {
    DCMI_Properties dcmiProperties;
    DCMI_Behavior *dcmiBehavior;
} Hal_DCMI_Stru;

/* Function declarations */
void HAL_DCMI_InitHookFromVendor(void);
Hal_DCMI_Stru* HAL_DCMI_GetHandle(uint8_t dcmiIndex);

#endif
