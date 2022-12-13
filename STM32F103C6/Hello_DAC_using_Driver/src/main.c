/*

 * main.c
 *
 *  Created on: Jul 9, 2021
 *      Author: mahmoud
 */

#include "STD_TYPES.h"

#include "RCC_interface.h"

#include "DAC_interface.h"

//  1-Connect PORTA LOW with 8Bit DAC
//  2-Connect The Output Of the DAC  To The POT
//  3-Connect the Divider Of The POT To The input of amplifier
//  4-Connect The Output Of The Amplifier To The bread board
//  5-Then We Connect The Left & Right headphone Pins With The Output Of The Amplifier In The BreadBoard


//                             DAC CODE Sorat Al ASR (sh Yaser Eldosary)


int main (void){

	RCC_voidInitSysClock();
	RCC_voidEnablePeripheralClock(APB2_BUS,GPIOA_RCC);

	MDAC_voidInit();

	MDAC_voidPlay();

	while(1);

	return 0;
}


