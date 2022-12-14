/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    ADC_interface.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mahmoud Karem Zamel
 *  Date    : 3/9/2021
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
#define DMA_ENABLE        1


void ADC1_voidInit(void);
u8   ADC1_u8GetResultSync( u16* Copy_pu16Result );
u8   ADC1_u8StartConversionAsynch( u16* Copy_pu16Reading, void(*Copy_pvNotificationFunc)(void));
void ADC1_voidEnableEnterrupt(void);
void ADC1_voidDisableEnterrupt(void);


void ADC2_voidInit(void);
u8   ADC2_u8GetResultSync( u16* Copy_pu16Result );
u8   ADC2_u8StartConversionAsynch( u16* Copy_pu16Reading, void(*Copy_pvNotificationFunc)(void));
void ADC2_voidEnableEnterrupt(void);
void ADC2_voidDisableEnterrupt(void);



void ADC3_voidInit(void);
u8   ADC3_u8GetResultSync( u16* Copy_pu16Result );
u8   ADC3_u8StartConversionAsynch( u16* Copy_pu16Reading, void(*Copy_pvNotificationFunc)(void));
void ADC3_voidEnableInterrupt(void);
void ADC3_voidDisableEnterrupt(void);




#endif
