/*

 * main.c
 *
 *  Created on: Jul 5, 2021
 *      Author: Mahmoud
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "RCC_interface.h"
#include "NVIC_interface.h"

void main(void)
{
	/* initialize CLK */
	RCC_voidInitSysClock();
	RCC_voidEnablePeripheralClock(APB2_BUS,GPIOA_RCC);

	/*  pin modes  */
	MDIO_voidSetPinDirection(DIOA,PIN0,OUTPUT_SPEED_2MHZ_PP);
	MDIO_voidSetPinDirection(DIOA,PIN1,OUTPUT_SPEED_2MHZ_PP);
	MDIO_voidSetPinDirection(DIOA,PIN2,OUTPUT_SPEED_2MHZ_PP);

	/* initialize NVIC */
	MNVIC_voidInit();

	MNVIC_voidSetPriority(EXT0,1,1); //Group1 Sub1
	MNVIC_voidSetPriority(EXT1,0,1); //Group0 Sub1

	/* Enable EXTI0 interrupt from NVIC */
	MNVIC_voidEnableInterrupt(EXT0);
	MNVIC_voidEnableInterrupt(EXT1);


	MNVIC_voidSetPendingFlag(EXT0);


	while(1)
	{

	}
}

void EXTI0_IRQHandler(void)
{
	MDIO_voidSetPinValue(DIOA,PIN0,DIO_HIGH);
	MNVIC_voidSetPendingFlag(EXT1);
	MDIO_voidSetPinValue(DIOA,PIN1,DIO_HIGH);

	/* Imp HINT :-
	 *
	 *  interrupt 1 can't excute untill interrupt 2 finish
	 *  Cuz : INT1 & INT2 in the same Group
	 *  So : led1 then led2 then led3
	 *  pin0 --> pin1 -->pin2
	 *
	 * You Could Verify By Debugging
	 * I change the periority and make INT1 (Group0) higher than INT2 (Group0)
	 * So it will be pin0 --> pin2 -->pin1
	 *
	 *  */
}
void EXTI1_IRQHandler(void)
{
	MDIO_voidSetPinValue(DIOA,PIN2,DIO_HIGH);
}




