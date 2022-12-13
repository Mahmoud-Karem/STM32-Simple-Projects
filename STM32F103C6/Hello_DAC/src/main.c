/*

 * main.c
 *
 *  Created on: Jul 9, 2021
 *      Author: mahmoud
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "RCC_interface.h"
#include "STK_interface.h"

#include "DIO_private.h"

#include "arr.h"


volatile u16 i=0 ;

void voidSetDAC ()
{
	DIOA_ODR = alasr_arm_raw[i] ;
	i++;
	if(i == 40059)
	{
		i=0;
	}
}

void main ()
{
	RCC_voidInitSysClock();
	RCC_voidEnablePeripheralClock(APB2_BUS,GPIOA_RCC);

	MDIO_voidSetPortDirection(DIOA,DIO_LOW,OUTPUT_SPEED_2MHZ_PP);

	MSTK_voidInit();
	MSTK_voidSetIntervalPeriodic(125,voidSetDAC);
	while(1)
	{

	}


}

