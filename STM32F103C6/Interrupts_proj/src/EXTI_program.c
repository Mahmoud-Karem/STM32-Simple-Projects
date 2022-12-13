/***********************************************************************************/
/* Author  : Abdellatif Maher                                                      */
/* Date    : 13 JUL 2021                                                           */
/* Version : V01                                                                   */
/***********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

void (*EXTI_CallBack[16])(void)={NULL}; 

void MEXTI_voidInit()
{
	#if 	EXTI_MODE	== 	RISING
		SET_BIT(EXTI -> RTSR , EXTI_LINE);
	/*	CLR_BIT(EXTI -> FTSR , EXTI_LINE); */ // By me
	#elif 	EXTI_MODE	== 	FALLING
		SET_BIT(EXTI -> FTSR , EXTI_LINE);
	/*	CLR_BIT(EXTI -> RTSR , EXTI_LINE); */ // By me 
	#elif	EXTI_MODE	==	ON_CHANGE
		SET_BIT(EXTI -> RTSR , EXTI_LINE);
		SET_BIT(EXTI -> FTSR , EXTI_LINE);
	#else 	
		#error "Wrong Mode and Line Choice"
	#endif
	/*Disable interrupt*/
	CLR_BIT(EXTI->IMR , EXTI_LINE);
}

void MEXTI_voidEnableEXTI(u8 Copy_u8Line)
{
	SET_BIT(EXTI->IMR , Copy_u8Line);
}
void MEXTI_voidDisableEXTI(u8 Copy_u8Line)
{
	CLR_BIT(EXTI->IMR , Copy_u8Line);
}
void MEXTI_voidSwTrigger(u8 Copy_u8Line)
{
	CLR_BIT(EXTI->PR , Copy_u8Line );
	SET_BIT(EXTI -> SWIER , Copy_u8Line);
}
void MEXTI_voidClearPendingFlag(u8 Copy_u8Line)
{
	SET_BIT(EXTI->PR , Copy_u8Line );
}
void MEXTI_voidSetSignalLatch(u8 Copy_u8Line , u8 Copy_u8Mode)
{
	switch(Copy_u8Mode)
	{
		case RISING 	:	SET_BIT(EXTI -> RTSR , Copy_u8Line); 	break;
		case FALLING	:	SET_BIT(EXTI -> FTSR , Copy_u8Line); 	break;
		case ON_CHANGE 	:	SET_BIT(EXTI -> RTSR , Copy_u8Line); 
							SET_BIT(EXTI -> RTSR , Copy_u8Line); 	break;
	}
}

void MEXTI_voidSetCallBack(u8 Copy_u8Line,void (*Copy_ptr) (void))
{
	EXTI_CallBack[Copy_u8Line] = Copy_ptr ;
}

void EXTI0_IRQHandler(void)
{
	if(EXTI_CallBack[0] != NULL)
	{
		EXTI_CallBack[0]();
		MEXTI_voidClearPendingFlag(LINE0);
	}
}
void EXTI1_IRQHandler(void)
{
	if(EXTI_CallBack[1] != NULL)
	{
		EXTI_CallBack[1]();
		MEXTI_voidClearPendingFlag(LINE1);
	}
}
void EXTI2_IRQHandler(void)
{
	if(EXTI_CallBack[2] != NULL)
	{
		EXTI_CallBack[2]();
		MEXTI_voidClearPendingFlag(LINE2);
	}
}void EXTI3_IRQHandler(void)
{
	if(EXTI_CallBack[3] != NULL)
	{
		EXTI_CallBack[3]();
		MEXTI_voidClearPendingFlag(LINE3);
	}
}void EXTI4_IRQHandler(void)
{
	if(EXTI_CallBack[4] != NULL)
	{
		EXTI_CallBack[4]();
		MEXTI_voidClearPendingFlag(LINE4);
	}
}
void EXTI5_IRQHandler(void)
{
	if(EXTI_CallBack[5] != NULL)
	{
		EXTI_CallBack[5]();
		MEXTI_voidClearPendingFlag(LINE5);
	}
}
void EXTI6_IRQHandler(void)
{
	if(EXTI_CallBack[6] != NULL)
	{
		EXTI_CallBack[6]();
		MEXTI_voidClearPendingFlag(LINE6);
	}
}
void EXTI7_IRQHandler(void)
{
	if(EXTI_CallBack[7] != NULL)
	{
		EXTI_CallBack[7]();
		MEXTI_voidClearPendingFlag(LINE7);
	}
}void EXTI8_IRQHandler(void)
{
	if(EXTI_CallBack[8] != NULL)
	{
		EXTI_CallBack[8]();
		MEXTI_voidClearPendingFlag(LINE8);
	}
}void EXTI9_IRQHandler(void)
{
	if(EXTI_CallBack[9] != NULL)
	{
		EXTI_CallBack[9]();
		MEXTI_voidClearPendingFlag(LINE9);
	}
}
void EXTI10_IRQHandler(void)
{
	if(EXTI_CallBack[10] != NULL)
	{
		EXTI_CallBack[10]();
		MEXTI_voidClearPendingFlag(LINE10);
	}
}
void EXTI11_IRQHandler(void)
{
	if(EXTI_CallBack[11] != NULL)
	{
		EXTI_CallBack[11]();
		MEXTI_voidClearPendingFlag(LINE11);
	}
}
void EXTI12_IRQHandler(void)
{
	if(EXTI_CallBack[12] != NULL)
	{
		EXTI_CallBack[12]();
		MEXTI_voidClearPendingFlag(LINE12);
	}
}void EXTI13_IRQHandler(void)
{
	if(EXTI_CallBack[13] != NULL)
	{
		EXTI_CallBack[13]();
		MEXTI_voidClearPendingFlag(LINE13);
	}
}void EXTI14_IRQHandler(void)
{
	if(EXTI_CallBack[14] != NULL)
	{
		EXTI_CallBack[14]();
		MEXTI_voidClearPendingFlag(LINE14);
	}
}
void EXTI15_IRQHandler(void)
{
	if(EXTI_CallBack[15] != NULL)
	{
		EXTI_CallBack[15]();
		MEXTI_voidClearPendingFlag(LINE15);
	}
}