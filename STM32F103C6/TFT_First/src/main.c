/*

 * main.c
 *
 *  Created on: Jul 12, 2021
 *      Author: mahmoud
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "RCC_interface.h"
#include "SPI_interface.h"
#include "STK_interface.h"

#include "TFT_interface.h"

#include "image.h"

void main (void)
{
	RCC_voidInitSysClock();
	RCC_voidEnablePeripheralClock(APB2_BUS,2); //GPIO
	RCC_voidEnablePeripheralClock(APB2_BUS,12); //SPI

	MDIO_voidSetPinDirection(DIOA,1,OUTPUT_SPEED_2MHZ_PP); //A0
	MDIO_voidSetPinDirection(DIOA,2,OUTPUT_SPEED_2MHZ_PP); //RST
	MDIO_voidSetPinDirection(DIOA,5,OUTPUT_SPEED_10MHZ_AFPP); //CLK
	MDIO_voidSetPinDirection(DIOA,7,OUTPUT_SPEED_10MHZ_AFPP); //MOSI

	/* peripherals Init */
	MSTK_voidInit();
	MSPI_voidInit();
	HTFT_voidInitialize();

	HTFT_voidDisplayImage(image);

	while(1)
	{

	}



}

