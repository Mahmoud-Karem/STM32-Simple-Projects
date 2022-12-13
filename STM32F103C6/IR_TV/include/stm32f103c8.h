/************************************************************/
/************ Name        : Abdelrahman Sobhy    ************/
/************ Date        : 8/9/2021             ************/
/************ version     : 1.0v                 ************/
/************ SWC         : stm32f10xx.h         ************/
#ifndef STM32F103C8_H_
#define STM32F103C8_H_


/************          RCC Registers        ************/



typedef struct
{
	volatile u32 CR       ;
	volatile u32 CFGR     ;
	volatile u32 CIR      ;
	volatile u32 APB2RSTR ;
	volatile u32 APB1RSTR ;
	volatile u32 AHBENR   ;
	volatile u32 APB2ENR  ;
	volatile u32 APB1ENR  ;
	volatile u32 BDCR     ;
	volatile u32 CSR      ;
}RCC_REGDEF_T;


#define RCC     ((RCC_REGDEF_T *)0x40021000)


/*******************************************************/

/************          GPIO Registers        ************/



typedef struct{

	volatile u32 CRL  ;
	volatile u32 CRH  ;
	volatile u32 IDR  ;
	volatile u32 ODR  ;
	volatile u32 BSRR ;
	volatile u32 BRR  ;
	volatile u32 LCKR ;

}GPIO_REGDEF_T;





#define GPIOA    ((GPIO_REGDEF_T *)0x40010800)
#define GPIOB    ((GPIO_REGDEF_T *)0x40010C00)
#define GPIOC    ((GPIO_REGDEF_T *)0x40011000)

/*******************************************************/


/************          STK Registers        ************/



typedef struct{

	volatile u32 CTRL  ;
	volatile u32 LOAD  ;
	volatile u32 VAL   ;
	volatile u32 CALIB ;

}STK_REGDEF_T;





#define STK    ((STK_REGDEF_T *)0xE000E010)

/*******************************************************/


#endif
