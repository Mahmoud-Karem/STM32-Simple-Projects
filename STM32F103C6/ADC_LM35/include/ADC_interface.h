/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    ADC_interface.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mahmoud Karem Zamel
 *  Date    : 7/9/2021
 *  Version : V01
 *  Layer   : MCAL
 * 
 */

#ifndef ADC_INTERFACE
#define ADC_INTERFACE

#define ADC_DISABLE  0
#define ADC_ENABLE   1

#define ADC_SINGLE_CON_MODE       0
#define ADC_CONTINUOUS_CON_MODE   1

#define DMA_DISABLE       0
#define ADC_ENABLE        1


void ADC_voidInit(void);
u8 ADC_u8GetResultSync( u16* Copy_pu16Result );
u8 ADC_u8StartConversionAsynch( u16* Copy_pu16Reading, void(*Copy_pvNotificationFunc)(void));
void ADC_voidEnableInterrupt(void);
void ADC_voidDisableInterrupt(void);


#endif
