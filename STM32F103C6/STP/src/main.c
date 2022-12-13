/*

 * main.c
 *
 *  Created on: Jul 10, 2021
 *      Author: mahmoud
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "STK_interface.h"


#include "STP_interface.h"


int main(void){

	RCC_voidInitSysClock();

	HSTP_voidInit();

	MSTK_voidInit();

	u8 i=0;

	while(1){

		for (i=0;i<8;i++)
		{
			HSTP_voidSendSynchronus(1<<i); //shift left
			MSTK_voidSetBusyWait(300000);
		}

	}

	return 0;
}
