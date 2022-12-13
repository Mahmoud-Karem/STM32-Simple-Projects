/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    ADC_private.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mahmoud Karem Zamel
 *  Date    : 7/9/2021
 *  Version : V01
 *  Layer   : MCAL
 * 
 */

#ifndef ADC_PRIVATE
#define ADC_PRIVATE


/* Register Definitions */  /* P:51,252 (Reg Des) */
#define ADC_SR                *( (volatile u32*) (0x40012400 + 0x00) )
#define ADC_SR_EOC    1

#define ADC_CR1               *( (volatile u32*) (0x40012400 + 0x04) )
#define ADC_CR1_EOCIE     5


#define ADC_CR2               *( (volatile u32*) (0x40012400 + 0x08) )
#define ADC_CR2_ADON      0
#define ADC_CR2_CONT      1
#define ADC_CR2_DMA       8
#define ADC_CR2_SWSTART   22



#define ADC_SMPR1             *( (volatile u32*) (0x40012400 + 0x0C) )
#define ADC_SMPR2             *( (volatile u32*) (0x40012400 + 0x10) )
#define ADC_JOFR1             *( (volatile u32*) (0x40012400 + 0x14) )
#define ADC_JOFR2             *( (volatile u32*) (0x40012400 + 0x18) )
#define ADC_JOFR3             *( (volatile u32*) (0x40012400 + 0x1C) )
#define ADC_JOFR4             *( (volatile u32*) (0x40012400 + 0x20) )
#define ADC_HTR               *( (volatile u32*) (0x40012400 + 0x24) )
#define ADC_LTR               *( (volatile u32*) (0x40012400 + 0x28) )
#define ADC_SQR1              *( (volatile u32*) (0x40012400 + 0x2C) )
#define ADC_SQR2              *( (volatile u32*) (0x40012400 + 0x30) )
#define ADC_SQR3              *( (volatile u32*) (0x40012400 + 0x34) )
#define ADC_JSQR              *( (volatile u32*) (0x40012400 + 0x38) )
#define ADC_JDR1              *( (volatile u32*) (0x40012400 + 0x3C) )
#define ADC_JDR2              *( (volatile u32*) (0x40012400 + 0x40) )
#define ADC_JDR3              *( (volatile u32*) (0x40012400 + 0x44) )
#define ADC_JDR4              *( (volatile u32*) (0x40012400 + 0x48) )
#define ADC_DR                *( (volatile u32*) (0x40012400 + 0x4C) )


#endif
