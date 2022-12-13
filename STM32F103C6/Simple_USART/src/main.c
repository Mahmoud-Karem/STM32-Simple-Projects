/*
 * main.c
 *
 *  Created on: Jul 11, 2021
 *      Author: mahmoud
 */



#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "USART_interface.h"

int main(void)
{
	RCC_voidInitSysClock();
	RCC_voidEnablePeripheralClock(APB2_BUS, 2);		    /* Enable DIOA Clock */
	RCC_voidEnablePeripheralClock(APB2_BUS, 14);		/* Enable USART1 Clock */

	/* Setting A9:TX pin as Output alternate function push pull w max speed 50 MHz */
	MDIO_voidSetPinDirection(DIOA,PIN9,OUTPUT_SPEED_50MHZ_AFPP);
	/* Setting A10:RX pin as input floating */
	MDIO_voidSetPinDirection(DIOA,PIN10,INPUT_FLOATING);

	MDIO_voidSetPinDirection(DIOA,PIN0,OUTPUT_SPEED_2MHZ_PP);

	MUSART1_voidInit();

		u8 x;

		while(1)
		{
			MUSART1_voidTransmit("97");
			x = MUSART1_u8Receive();
			if(x == '5')
			{
				MDIO_voidSetPinValue(DIOA,PIN0,DIO_HIGH);
			}
			if(x == 'r')
			{
				MDIO_voidSetPinValue(DIOA,PIN0,DIO_LOW);
			}
		}



	return 0;
}



