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

	HTFT_voidFillColor(BLACK);


	u8 I[] = {65, 65, 127, 65, 65};

	u8 L[] = {127, 64, 64, 64, 64};
	u8 O[] = {28, 34, 34, 34, 28};
	u8 V[] = {31, 32, 32, 31, 0};
	u8 E[] = {127, 73, 73, 73, 65};

	u8 U[] = {63, 64, 64, 64, 63};







	HTFT_voidWriteChar ( I     , 30  , 70 , BLUE   );

	HTFT_voidWriteChar ( L     , 40  , 70 , RED   );
	HTFT_voidWriteChar ( O     , 48  , 70 , RED   );
	HTFT_voidWriteChar ( V     , 56  , 70 , RED   );
	HTFT_voidWriteChar ( E     , 64  , 70 , RED   );

	HTFT_voidWriteChar ( U     , 74  , 70 , BLUE   );

	while(1)
	{

	}



}

