/*
 * main.c

 *
 *  Created on: Jul 8 2021
 *      Author: Mahmoud
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"

/*
 * volatile :
 * Because those variables change inside the interrupt (ISR)
 *
 */
volatile u8   u8StartFlag       = 0; //for start bit
volatile u32  u32FrameData[50]  = {0};
volatile u8   u8EdgeCounter     = 0;
volatile u8   u8Data            = 0;



void voidPlay(void)
{
	switch (u8Data)
	{

	case 12: MDIO_voidSetPinValue(DIOA,1,DIO_HIGH); break;  /* 1 = RED ON */
	case 24: MDIO_voidSetPinValue(DIOA,1,DIO_LOW); break;   /* 2 = RED OFF */

	case 8: MDIO_voidSetPinValue(DIOA,2,DIO_HIGH); break;  /* 4 = Green ON */
	case 0: MDIO_voidSetPinValue(DIOA,2,DIO_LOW); break;   /* 5= Blue OFF */

	case 66: MDIO_voidSetPinValue(DIOA,3,DIO_HIGH); break;  /* 7 = RED ON */
	case 82: MDIO_voidSetPinValue(DIOA,3,DIO_LOW); break;   /* 8 = RED OFF */

	case 69:
		     MDIO_voidSetPinValue(DIOA,1,DIO_LOW);
		     MDIO_voidSetPinValue(DIOA,2,DIO_LOW);
		     MDIO_voidSetPinValue(DIOA,3,DIO_LOW);
	         break;	/* power = OFF ALL */
	}
}

void voidTakeAction(void)
{
	u8 i;
	u8Data = 0;

	if ( (u32FrameData[0] >= 10000) && (u32FrameData[0] <= 14000) )
	{
		for (i=0;i<8;i++)
		{
			/* BIT No 17 => LSB   */
			if (  (u32FrameData[17+i] >= 2000) && (u32FrameData[17+i] <=2300) )
			{
				SET_BIT(u8Data,i); //BIT 1
			}

			else
			{
				CLR_BIT(u8Data,i); // BIT 0
			}
		}

		voidPlay();
	}

	else
	{
		// Invalid Frame
	}

	u8StartFlag     = 0;
	u32FrameData[0] = 0;
	u8EdgeCounter   = 0;
}


void voidGetFrame(void)
{

	// check/debug :asm ("NOP");
	if (u8StartFlag == 0)
	{
		// Start Timer (1sec)
		MSTK_voidSetIntervalSingle(1000000,voidTakeAction);
		u8StartFlag = 1;
	}

	else
	{
		u32FrameData[u8EdgeCounter] = MSTK_u32GetElapsedTime();
		MSTK_voidSetIntervalSingle(1000000,voidTakeAction); // Start timer again
		u8EdgeCounter++;
	}
}


void main(void)
{
	/* RCC Initialize */
	RCC_voidInitSysClock();
	RCC_voidEnablePeripheralClock(APB2_BUS,2); /* DIOA Enable Clock */

	/* IO Pins Initialization */
	MDIO_voidSetPinDirection(DIOA,0,INPUT_FLOATING); /* A0 Input Floating        */
	MDIO_voidSetPinDirection(DIOA,1,OUTPUT_SPEED_2MHZ_PP); /* A1 Output PP "RED"       */
	MDIO_voidSetPinDirection(DIOA,2,OUTPUT_SPEED_2MHZ_PP); /* A1 Output PP "GREEN"     */
	MDIO_voidSetPinDirection(DIOA,3,OUTPUT_SPEED_2MHZ_PP); /* A1 Output PP "BLUE"      */


	/* EXTI Initializtion */
	MEXTI0_voidSetCallBack(voidGetFrame);
	MEXTI_voidInit(); /* A0 EXTI0 Enabled / Falling Edge */

	/* Enable EXTI0 from NVIC */
	MNVIC_voidInit();
	MNVIC_voidEnableInterrupt(EXTI0); /* EXTI0 */

	/* SysTick Init */
	MSTK_voidInit(); /* Enable SysTick AHB/8 = 1MHZ */

	while(1)
	{

	}

}
