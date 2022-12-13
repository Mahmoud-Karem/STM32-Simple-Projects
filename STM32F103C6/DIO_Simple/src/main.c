/*
 * main.c
 *
 *  Created on: Jul 3, 2021
 *      Author: Mahmoud
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"

int main (void)
{
	RCC_voidInitSysClock();

	/*Enable RCC for GPIOA */
	RCC_voidEnablePeripheralClock(APB2_BUS,GPIOA_RCC);

	/*Enable RCC for GPIOB */
    RCC_voidEnablePeripheralClock(APB2_BUS,GPIOB_RCC);

	/*Enable RCC for GPIOC */
	RCC_voidEnablePeripheralClock(APB2_BUS,GPIOC_RCC);

	MDIO_voidSetPinDirection(DIOB,PIN0,OUTPUT_SPEED_10MHZ_PP);
    u16 w=500;
	while(1)
	{
		MDIO_voidSetPinValue(DIOB,PIN0,DIO_HIGH);

		// DELAY Using Assembly ( 0.5 sec )
		for (u16 i=0 ; i<w ; i++)
		{
			for(u16 j=0 ; j<w ; j++)
			{
				asm("NOP");
			}
		}

		MDIO_voidSetPinValue(DIOB,PIN0,DIO_LOW);

		// DELAY Using Assembly ( 0.5 sec )
		for (u16 i=0 ; i<w ; i++)
		{
			for(u16 j=0 ; j<w ; j++)
			{
				asm("NOP");
			}
		}

	}
	return 0;
}
