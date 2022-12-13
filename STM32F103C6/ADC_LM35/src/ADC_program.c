/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    ADC_program.c   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mahmoud Karem Zamel
 *  Date    : 7/9/2021
 *  Version : V01
 *  Layer   : MCAL
 * 
 */ 
 
//=====================================================================================================================
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"


#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"

static u16* ADC_pu16Reading= NULL;
static void (*ADC_pvCallBackNotificationFunc)(void)=NULL;

u8 ADC_u8BusyState= IDLE;



//=====================================================================================================================
/*
	Hint : We will Initialize ADC1 & Channel 1 (PA0)
*/

void ADC_voidInit(void)
{
/* ADC1 Enable Condition    */
#if ADC1_STATUS == ADC_ENABLE
	
	/* Enable ADC Peripheral */
	SET_BIT( ADC_CR2 , ADC_CR2_ADON );

	/***********************************************************************************/
	/*************************  ADC1 Config  *******************************************/
	/***********************************************************************************/
	
	/* Conversion Mode */
	#if ADC_CON_MODE == ADC_SINGLE_CON_MODE
		CLR_BIT( ADC_CR2 , ADC_CR2_CONT );

	#elif ADC_CON_MODE == ADC_CONTINUOUS_CON_MODE
		SET_BIT( ADC_CR2 , ADC_CR2_CONT );

	#endif
	/*******************/
	
	/* Set conversion sequence length to 1 L[3:0]*/
	ADC_SQR1 = 0 ;
	/*******************/
	
	/*  Set start of conversion sequence to ch 1 (PA1)*/
	ADC_SQR3 = 1 ;
	/*******************/
	
	/* ENable DMA */
	#if DMA_STATUS == DMA_DISABLE
		CLR_BIT( ADC_CR2 , ADC_CR2_DMA );

	#elif DMA_STATUS == DMA_ENABLE
		SET_BIT( ADC_CR2 , ADC_CR2_DMA );

	#endif
	/*******************/
	
	
	
	/***********************************************************************************/
	
/* ADC1 Disable Condition    */
#elif ADC1_STATUS == ADC_DISABLE
	
	/* Disable Clock For ADC1 Peripheral */
	RCC_voidDisablePeripheralClock  ( APB2_BUS , ADC1_RCC );
	
#endif

	
}

//----------------------------------------------------------------------------------------------------------------------------------------------------

u8 ADC_u8GetResultSync( u16* Copy_pu16Result )
{

	u8 LOC_u8ErrorState = OK ;
	
	u32 LOC_u32Counter = 0 ;
	
	if (ADC_u8BusyState == IDLE)
	{

			/*
				Hint:
					=> We maay config the channel here and take it as an argument from the user in this func
					   if we had many channels 
					=> In This App we config this for Ch1 @ ADC_voidInit
			*/
			/*Start conversion*/
			SET_BIT(ADC_CR2,ADC_CR2_SWSTART);

		
			/***********************************************************************************************************************/
			/* Polling (Busy Waiting) until The conversion complete (EOC flag is set) OR  LOC_u32Counter reached ADC_TIMEOUT */

			while( ( GET_BIT( ADC_SR , ADC_SR_EOC ) == 0 ) && ( LOC_u32Counter != ADC_TIMEOUT) )
			{
				LOC_u32Counter ++ ;
			}
			/* Check The reason of breaking the loop   */
			if (LOC_u32Counter == ADC_TIMEOUT)
			{
				/* Loop is broken because time_out is reached */
				LOC_u8ErrorState = NOK ;
			}
			else
			{
				/* Loop is broken because Flag is raised */
				
				/*
					Clear the conversion complete flag 
				    CLR_BIT( ADC_SR , ADC_SR_EOC ); we will clear it by reading ADC_DR
				*/
				
				/* Return The Reading & Clear EOC flag */
				* Copy_pu16Result = ADC_DR ;
				
				/*ADC is finished, return it to IDLE*/
				ADC_u8BusyState= IDLE;
			}
	}
	else
	{
		LOC_u8ErrorState= BUSY_STATE;
	}

	
	/***********************************************************************************************************************/

	return LOC_u8ErrorState ;

}

//----------------------------------------------------------------------------------------------------------------------------------------------------

u8 ADC_u8StartConversionAsynch( u16* Copy_pu16Reading, void(*Copy_pvNotificationFunc)(void))
{
	u8 Local_u8ErrorState=OK;
	
	/*Check on the ADC state to avoid overwrite on the convertion */
	if(ADC_u8BusyState== IDLE)
	{
		/* Check Null Pointer  */
		if((Copy_pu16Reading ==NULL) || (Copy_pvNotificationFunc == NULL))
		{
			Local_u8ErrorState= NULL_POINTER;
		}
		else
		{
			/*make ADC busy in order not to work until being idle*/
			ADC_u8BusyState= BUSY;
			
			/*************************************************************************************************************************/
			/* 
				We should make the address of the Global Pointers as the same as the local which return the result to user
			*/

			/*Initialize the reading variable globally*/
			ADC_pu16Reading = Copy_pu16Reading;

			/*Initialize the callback notification function globally*/
			ADC_pvCallBackNotificationFunc= Copy_pvNotificationFunc;
			
			/*************************************************************************************************************************/
			
			/*
				Hint:
					=> We maay config the channel here and take it as an argument from the user in this func
					   if we had many channels 
					=> In This App we config this for Ch1 @ ADC_voidInit
			*/

			/*Start conversion*/
			SET_BIT(ADC_CR2,ADC_CR2_SWSTART);

			/*ADC interrupt enable*/
			SET_BIT(ADC_CR1,ADC_CR1_EOCIE);
		}
	}
	else
	{
		Local_u8ErrorState= BUSY_STATE;
	}

	return Local_u8ErrorState;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
void ADC_voidEnableInterrupt(void)
{
	SET_BIT(ADC_CR1,ADC_CR1_EOCIE);

}
//----------------------------------------------------------------------------------------------------------------------------------------------------
void ADC_voidDisableInterrupt(void)
{
	  CLR_BIT(ADC_CR1,ADC_CR1_EOCIE);
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
void ADC1_2_IRQHandler(void)
{

	/*Read ADC result*/
	*ADC_pu16Reading=ADC_DR;

	/*Make ADC state be IDLE because it finished*/
	ADC_u8BusyState=IDLE;

	/*Invoke the callback notification function*/
	ADC_pvCallBackNotificationFunc();


	/*  Disable ADC conversion complete interrupt */
	ADC_voidDisableInterrupt();

}
