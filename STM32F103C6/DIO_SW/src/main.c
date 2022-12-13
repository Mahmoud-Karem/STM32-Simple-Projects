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

		MDIO_voidSetPinDirection(DIOB,PIN0,INPUT_PULLUP_PULLDOWN);

		MDIO_voidSetPinDirection(DIOB,PIN1,OUTPUT_SPEED_10MHZ_PP);


		/* for pull up   */
		MDIO_voidSetPinValue(DIOB,PIN0,DIO_HIGH);


	    //u16 w=500;
		while(1)
		{
			if (MDIO_u8GetPinValue(DIOB,PIN0)==0)
			{
				MDIO_voidSetPinValue(DIOB,PIN1,DIO_HIGH);
			}
			else
			{
				MDIO_voidSetPinValue(DIOB,PIN1,DIO_LOW);
			}
		}
	return 0;
}


