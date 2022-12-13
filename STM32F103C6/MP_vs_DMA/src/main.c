/*

 * main.c
 *
 *  Created on: Jul 10, 2021
 *      Author: mahmoud
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "NVIC_interface.h"
#include "DMA_interface.h"

u32 SOURCE[1000]={0};
u32 DESTINATION[1000];

u32 SOURCE2[1000]={0};
u32 DESTINATION2[1000];

u16 i = 0;

void DMA_CallBack(void){

	MDMA_voidClearFlag             ( CHANNEL1 , DMA_TCIF );

}

int main(void){


	RCC_voidInitSysClock                  ();
	RCC_voidEnablePeripheralClock (  AHB_BUS , DMA1_RCC  );

	MNVIC_voidSetPriority          ( DMA_ID , 1 , NO_SUB_PRIORITY  );
	MNVIC_voidEnableInterrupt     ( DMA_ID );

	MDMA_voidSetCallBackChannel1   ( DMA_CallBack );

	MDMA_voidSetConfiguration      ( CHANNEL1 , MEM_TO_MEM , DMA_DISABLE_CIRCULAR , PERIPHERAL_INCREMENT_ENABLE ,
							        MEM_INCREMENT_ENABLE , WORD , WORD , DMA_VERY_HIGH );

	MDMA_voidSetAddress            ( CHANNEL1 , SOURCE , DESTINATION , 1000 );
	MDMA_voidInerruptEnable        ( CHANNEL1 , DMA_TCIE );
	MDMA_voidDMAEnable             ( CHANNEL1 );

	//For Processor
	for( i = 0 ; i < 1000 ;i++ ){

		DESTINATION2[i]=SOURCE2[i];

	}

	while(1){

	}

	return 0;
}



