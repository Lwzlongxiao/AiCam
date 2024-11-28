#ifndef __HAL_ADC_H
#define __HAL_ADC_H

#include <stdint.h>

/* ADC ID definition */
enum {
    ADC_ID0 = 0,
    ADC_ID1 = 1,
    ADC_ID2 = 2,
    ADC_ID3 = 3,
    ADC_ID4 = 4,
    ADC_ID5 = 5,
    ADC_ID6 = 6,
    ADC_ID7 = 7,
    ADC_ID_MAX = 8
};

/* ADC properties definition */
typedef struct {
    uint32_t Resolution;        /* ADC resolution (12-bit, 10-bit, etc.) */
    uint32_t ScanConvMode;      /* Scan conversion mode */
    uint32_t ContinuousConvMode;/* Continuous conversion mode */
    uint32_t DiscontinuousConvMode; /* Discontinuous conversion mode */
    uint32_t ExternalTrigConvEdge; /* External trigger edge */
    uint32_t ExternalTrigConv;   /* External trigger */
    uint32_t DataAlign;         /* Data alignment */
    uint32_t NbrOfConversion;   /* Number of conversions */
    uint32_t SamplingTime;      /* Sampling time */
} ADC_Properties;

typedef int8_t status;

typedef status (*ADC_StartFn)(ADC_Properties *, uint32_t);
typedef status (*ADC_StopFn)(ADC_Properties *);
typedef status (*ADC_PollForConversionFn)(ADC_Properties *, uint32_t);
typedef status (*ADC_GetValueFn)(ADC_Properties *, uint32_t *);
typedef status (*ADC_Start_ITFn)(ADC_Properties *);
typedef status (*ADC_Stop_ITFn)(ADC_Properties *);

/* ADC behavior definition */
typedef struct {
    int8_t (*HAL_ADC_InitFn)(ADC_Properties);
    int8_t (*HAL_ADC_DeInitFn)(ADC_Properties);
    void (*HAL_ADC_MspInitFn)(ADC_Properties);
    void (*HAL_ADC_MspDeInitFn)(ADC_Properties);

    ADC_StartFn ADC_Start;
    ADC_StopFn ADC_Stop;
    ADC_PollForConversionFn ADC_PollForConversion;
    ADC_GetValueFn ADC_GetValue;

    ADC_Start_ITFn ADC_Start_IT;
    ADC_Stop_ITFn ADC_Stop_IT;
} ADC_Behavior;

/* ADC object definition */
typedef struct {
    ADC_Properties adcProperties;
    ADC_Behavior *adcBehavior;
} Hal_AdcStru;

/* Function declarations */
void HAL_ADC_InitHookFromVendor(void);
Hal_AdcStru* HAL_ADC_GetHandle(uint8_t adcIndex);

#endif /* __HAL_ADC_H */
