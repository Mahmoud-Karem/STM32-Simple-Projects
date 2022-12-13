/*
 * main.c
 *
 *  Created on: Sep 27, 2021
 *      Author: repair
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"
#include "EXTI_interface.h"
#include "AFIO_interface.h"
#include "NVIC_interface.h"
#include "ADC_interface.h"
#include "ADC_private.h"

u16 ADC_Reading_For_LDR = 0 ;

u16 ADC_Reading_For_LM35 = 0 ;
u16 LM35_u16TempValue = 0 ;

void LightnessAutoMode();
void LightnessAutoModeEnable ();
void LightnessAutoModeDisable ();

void LM35_GetTemp (u16 * Copy_TempVal);


void FanAutoMode ();
void FanAutoModeEnable ();
void FanAutoModeDisable ();


/*void Flame2(void)
{
	MDIO_voidSetPinValue(DIOC, PIN14,DIO_LOW);
}*/
void Flame(void)
{
	static u8 state = 0;
	state++;
	if(state == 1)
	{
		MDIO_voidSetPinValue(DIOC, PIN13,DIO_HIGH);
	}
	else if(state == 2)
	{
		MDIO_voidSetPinValue(DIOC, PIN13,DIO_LOW);
		state =0;
	}

}
void PIR2(void)
{
	MDIO_voidSetPinValue(DIOC, PIN14,DIO_LOW);
}
void PIR(void)
{
		 MDIO_voidSetPinValue(DIOC, PIN14,DIO_HIGH);
		 MSTK_voidSetIntervalSingle(5000000,PIR2);
}





void main(void)
{
	/******************************************RCC******************************************/
	RCC_voidInitSysClock(); /* Initialization the clock */
	RCC_voidEnablePeripheralClock(APB2_BUS, DIOA_RCC);		    /* Enable DIOA clock*/
	RCC_voidEnablePeripheralClock(APB2_BUS, DIOB_RCC);		    /* Enable DIOB clock*/
	RCC_voidEnablePeripheralClock(APB2_BUS, DIOC_RCC);		    /* Enable DIOC clock*/
	//RCC_voidEnablePeripheralClock(APB2_BUS, USART1_RCC);		/* Enable USART1 Clock */
	RCC_voidEnablePeripheralClock(APB2_BUS, AFIO_RCC);		    /* Enable AFIO clock*/
	RCC_voidEnablePeripheralClock  ( APB2_BUS , ADC1_RCC );	    /* Enable Clock For ADC1 Peripheral */
	RCC_voidEnablePeripheralClock( APB2_BUS , ADC2_RCC );   	/* Enable Clock For ADC2 Peripheral */
	/****************************************************************************************/
	MDIO_voidSetPinDirection(DIOC, PIN13, OUTPUT_SPEED_2MHZ_PP);
	MDIO_voidSetPinDirection(DIOC, PIN14, OUTPUT_SPEED_2MHZ_PP);
	/* LDR & LM35 Test  */
	MDIO_voidSetPinDirection(DIOB, PIN0, OUTPUT_SPEED_2MHZ_PP);
	MDIO_voidSetPinDirection(DIOB, PIN1, OUTPUT_SPEED_2MHZ_PP);
	MDIO_voidSetPinDirection(DIOB, PIN2, OUTPUT_SPEED_2MHZ_PP);
	MDIO_voidSetPinDirection(DIOB, PIN3, OUTPUT_SPEED_2MHZ_PP);

	MDIO_voidSetPinDirection(DIOA, PIN3, OUTPUT_SPEED_2MHZ_PP);
	MDIO_voidSetPinValue(DIOA, PIN3,DIO_LOW);
	MDIO_voidSetPinDirection(DIOA, PIN3, INPUT_FLOATING);
	MDIO_voidSetPinDirection(DIOA, PIN4, INPUT_PULLUP_PULLDOWN);
	MDIO_voidSetPinValue(DIOA, PIN4,DIO_LOW);
	/* PA0 --> i/p pin ADC2 */
	MDIO_voidSetPinDirection  ( DIOA , PIN0   , INPUT_ANLOG   );
	/* PA1 --> i/p pin ADC1 */
	MDIO_voidSetPinDirection  ( DIOA , PIN1   , INPUT_ANLOG   );
	/* EN ADC1_2 Interrupt from NVIC  */
	MNVIC_voidEnableInterrupt(18);
	MSTK_voidInit();
	MEXTI_voidInit();
	MNVIC_voidInit();
	ADC1_voidInit();
	MEXTI_voidSetSignalLatch(LINE3,ON_CHANGE);
	MEXTI_voidSetSignalLatch(LINE4,RISING);
	MEXTI_voidSetCallBack(LINE3,Flame);
	MEXTI_voidSetCallBack(LINE4,PIR);
	MAFIO_voidSetEXTIConfiguration(3,0);
	MAFIO_voidSetEXTIConfiguration(4,0);
	MEXTI_voidEnableEXTI(LINE3);
	MEXTI_voidEnableEXTI(LINE4);
	MNVIC_voidEnableInterrupt(9);
	MNVIC_voidEnableInterrupt(10);
	MNVIC_voidEnableInterrupt(18); /* EN ADC1_2 Interrupt from NVIC  */
	MNVIC_voidSetPriority(9,0,0);
	MNVIC_voidSetPriority(10,1,0);
	MNVIC_voidSetPriority(18,2,0);




	while(1)
	{
		/*if(MDIO_u8GetPinValue(DIOA, PIN3) == 1 )
		{
			MDIO_voidSetPinValue(DIOC, PIN13,DIO_HIGH);
		}
		else if(MDIO_u8GetPinValue(DIOA, PIN3) == 0)
		{
			MDIO_voidSetPinValue(DIOC, PIN13,DIO_LOW);
		}

		if(MDIO_u8GetPinValue(DIOA, PIN4) == 1 )
		{
			MDIO_voidSetPinValue(DIOC, PIN14,DIO_HIGH);
		}
		else if(MDIO_u8GetPinValue(DIOA, PIN4) == 0)
		{
			MDIO_voidSetPinValue(DIOC, PIN14,DIO_LOW);
		}*/

		/********************************************************************************************/
		/****************************** Check LDR ***************************************************/
		/*
		 *	Hint : We will not Enable the EOC interrupt to continue asking about ADC Values
		 *
		 */

		//ADC1_u8StartConversionAsynch(&ADC_Reading_For_LM35 , &FanAutoMode);
		//ADC2_voidEnableInterrupt();
		//LightnessAutoModeEnable ();
		//LightnessAutoModeDisable ();

		/********************************************************************************************/

		/********************************************************************************************/
		/****************************** Check LM35 ***************************************************/
		/*
		 *	Hint : We will not Enable the EOC interrupt to continue asking about ADC Values
		 *
		 */
		//ADC1_u8StartConversionAsynch(&ADC_Reading_For_LDR , &LightnessAutoMode);
		//ADC1_voidEnableInterrupt();
		//FanAutoModeEnable ();
		//FanAutoModeDisable ();

		/********************************************************************************************/

		/********************************************************************************************/

		/********************************************************************************************/
		/****************************** LDR & LM35 ***************************************************/
		/*
		 *	Hint : We will not Enable the EOC interrupt to continue asking about ADC Values
		 *
		 */
		ADC1_voidChangeCh(0);
		ADC1_u8StartConversionAsynch(&ADC_Reading_For_LDR , &LightnessAutoMode);
		ADC1_voidEnableInterrupt();
		ADC1_voidDisableInterrupt();

		ADC1_voidChangeCh(1);
		ADC1_u8StartConversionAsynch(&ADC_Reading_For_LM35 , &FanAutoMode);
		ADC1_voidEnableInterrupt();
		ADC1_voidDisableInterrupt();

		//FanAutoModeEnable ();
		//FanAutoModeDisable ();

		/********************************************************************************************/



	}
}
/**************************************************************************************************/
/*
 * Hint : LDR is a NC (Inverse relationship with lightness)
 *
 */
void LightnessAutoMode ()
{
	if(ADC_Reading_For_LDR<=500)
	{
		/* lighting on */
		//MDIO_voidSetPinValue(DIOA,PIN8,DIO_LOW);
		//MDIO_voidSetPinValue(DIOA,PIN11,DIO_LOW);
		MDIO_voidSetPinValue(DIOB, PIN0,DIO_LOW);


	}
	else
	{
		/* lighting off */
		//MDIO_voidSetPinValue(DIOA,PIN8,DIO_HIGH);
		//MDIO_voidSetPinValue(DIOA,PIN11,DIO_HIGH);
		MDIO_voidSetPinValue(DIOB, PIN0,DIO_HIGH);

	}

}
void LightnessAutoModeEnable ()
{
	/*
	 * Hint : We will control The Automatic mode By Change The Direction of PA1
	 * Enable --> i/p  &  Disable --> o/p
	 */
	MDIO_voidSetPinDirection  ( DIOA , PIN0   , INPUT_ANLOG   );
}
void LightnessAutoModeDisable ()
{
	/*
		 * Hint : We will control The Automatic mode By Change The Direction of PA1
		 * Enable --> i/p  &  Disable --> o/p
		 */
	MDIO_voidSetPinDirection(DIOA,PIN0,OUTPUT_SPEED_2MHZ_PP);
}
void FanAutoModeEnable ()
{
	/*
	 * Hint : We will control The Automatic mode By Change The Direction of PA1
	 * Enable --> i/p  &  Disable --> o/p
	 */
	MDIO_voidSetPinDirection  ( DIOA , PIN1   , INPUT_ANLOG   );
}
void FanAutoModeDisable ()
{
	/*
		 * Hint : We will control The Automatic mode By Change The Direction of PA1
		 * Enable --> i/p  &  Disable --> o/p
		 */
	MDIO_voidSetPinDirection(DIOA,PIN1,OUTPUT_SPEED_2MHZ_PP);
}
void LM35_GetTemp (u16 * Copy_TempVal)
{
		u16 Local_u16ADCReference = 3300 ;  // To Convert from ( V --> mV )

		u16 Local_u16AnalogValue = 0  ;
		Local_u16AnalogValue = (u16) ( ( (u32)ADC_Reading_For_LM35 * (u32)Local_u16ADCReference ) /4096UL ) ;


		/* Convert ( mv --> Temp ) */
		(* Copy_TempVal) = ( Local_u16AnalogValue / 10 ) ;

}

void FanAutoMode ()
{
	LM35_GetTemp (&LM35_u16TempValue);
	if((LM35_u16TempValue>0) && (LM35_u16TempValue<=25))
	{
		/* Fan Off */
		MDIO_voidSetPinValue(DIOB,PIN1,DIO_LOW);
		MDIO_voidSetPinValue(DIOB,PIN2,DIO_LOW);
		MDIO_voidSetPinValue(DIOB,PIN3,DIO_LOW);
	}
	else if ((LM35_u16TempValue>25) && (LM35_u16TempValue<=35))
	{
		/*Speed1 */
		MDIO_voidSetPinValue(DIOB,PIN1,DIO_HIGH);
		MDIO_voidSetPinValue(DIOB,PIN2,DIO_LOW);
		MDIO_voidSetPinValue(DIOB,PIN3,DIO_LOW);
	}
	else if ((LM35_u16TempValue>35)  && (LM35_u16TempValue<39))
	{
		/*Speed2 */
		MDIO_voidSetPinValue(DIOB,PIN1,DIO_LOW);
		MDIO_voidSetPinValue(DIOB,PIN2,DIO_HIGH);
		MDIO_voidSetPinValue(DIOB,PIN3,DIO_LOW);

	}
	else if ((LM35_u16TempValue>=39) && (LM35_u16TempValue<60))
	{
		/*Speed3 */
		MDIO_voidSetPinValue(DIOB,PIN1,DIO_LOW);
		MDIO_voidSetPinValue(DIOB,PIN2,DIO_LOW);
		MDIO_voidSetPinValue(DIOB,PIN3,DIO_HIGH);
	}

}



