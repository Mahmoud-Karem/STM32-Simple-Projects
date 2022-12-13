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

		MDIO_voidSetPinDirection(DIOA,PIN0,OUTPUT_SPEED_10MHZ_PP);
		MDIO_voidSetPinDirection(DIOA,PIN1,OUTPUT_SPEED_10MHZ_PP);
		MDIO_voidSetPinDirection(DIOA,PIN2,OUTPUT_SPEED_10MHZ_PP);
		MDIO_voidSetPinDirection(DIOA,PIN3,OUTPUT_SPEED_10MHZ_PP);
		MDIO_voidSetPinDirection(DIOA,PIN4,OUTPUT_SPEED_10MHZ_PP);
		MDIO_voidSetPinDirection(DIOA,PIN5,OUTPUT_SPEED_10MHZ_PP);
		MDIO_voidSetPinDirection(DIOA,PIN6,OUTPUT_SPEED_10MHZ_PP);
		MDIO_voidSetPinDirection(DIOA,PIN7,OUTPUT_SPEED_10MHZ_PP);

	    //u16 w=500;
		while(1)
		{
			MDIO_voidSetPinValue(DIOA,PIN0,DIO_LOW);
			MDIO_voidSetPinValue(DIOA,PIN1,DIO_HIGH);
			MDIO_voidSetPinValue(DIOA,PIN2,DIO_HIGH);
			MDIO_voidSetPinValue(DIOA,PIN3,DIO_LOW);
			MDIO_voidSetPinValue(DIOA,PIN4,DIO_LOW);
			MDIO_voidSetPinValue(DIOA,PIN5,DIO_LOW);
			MDIO_voidSetPinValue(DIOA,PIN6,DIO_LOW);
			MDIO_voidSetPinValue(DIOA,PIN7,DIO_LOW);

			/*// DELAY Using Assembly ( 0.5 sec )
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
			}*/

		}
	return 0;
}
