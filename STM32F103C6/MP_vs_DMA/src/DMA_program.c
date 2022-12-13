/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    DMA_program.c   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mahmoud Karem Zamel
 *  Date    : 10/7/2021
 *  Vertion : V01
 *  Layer   : MCAL
 * 
 */ 
 
//==============================================================================================================
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_Config.h"


//==============================================================================================================

void ( *DMA_CallBackChannel1 )( void );

void MDMA_voidSetConfiguration( u8 Copy_u8Channel , u8 Copy_u8Direction , u8 Copy_u8DMAMode , u8 Copy_u8PINC ,
		u8 Copy_u8MINC , u8 Copy_MEMSize , u8 Copy_u8PERSize , u8 Copy_u8ChannelPriority ){

	//Disable DMA

	CLR_BIT( DMA->CHANNEL[ Copy_u8Channel ].CCR , 0 );
	// Wait Until DMA Disable
	while( GET_BIT(  DMA->CHANNEL[ Copy_u8Channel ].CCR , 0 ) == 1 );

	///////////////////////Direction/////////////////////////////////////
	if( Copy_u8Direction == MEM_TO_MEM ){

		SET_BIT( DMA->CHANNEL[ Copy_u8Channel ].CCR , 14 );

	}else if ( Copy_u8Direction == PREI_TO_MEM ){

		CLR_BIT( DMA->CHANNEL[ Copy_u8Channel ].CCR , 4  );

	}else if( Copy_u8Direction == MEM_TO_PERI ){

		SET_BIT( DMA->CHANNEL[ Copy_u8Channel ].CCR , 4  );

	}
	/////////////////////////////DMA MODE//////////////////////////////////
	if( Copy_u8DMAMode == DMA_ENABLE_CIRCULAR ){

		SET_BIT( DMA->CHANNEL[ Copy_u8Channel ].CCR , 5  );

	}else if( Copy_u8DMAMode == DMA_DISABLE_CIRCULAR ){

		CLR_BIT( DMA->CHANNEL[ Copy_u8Channel ].CCR , 5  );

	}
	//////////////////////////// PINC ////////////////////////////////////
	if( Copy_u8PINC == PERIPHERAL_INCREMENT_ENABLE ){

		SET_BIT( DMA->CHANNEL[ Copy_u8Channel ].CCR , 6  );

	}else if ( Copy_u8PINC == PERIPHERAL_INCREMENT_DISABLE ){

		CLR_BIT( DMA->CHANNEL[ Copy_u8Channel ].CCR , 6  );

	}
	/////////////////////////// MINC //////////////////////////////
	if( Copy_u8MINC == MEM_INCREMENT_ENABLE ){

		SET_BIT( DMA->CHANNEL[ Copy_u8Channel ].CCR , 7  );

	}else if ( Copy_u8MINC == MEM_INCREMENT_DISABLE ){

		CLR_BIT( DMA->CHANNEL[ Copy_u8Channel ].CCR , 7  );

	}
	////////////////////////// MEMORY SIZE //////////////////////////////
	if( Copy_MEMSize == BYTE ){

		CLR_BIT( DMA->CHANNEL[ Copy_u8Channel ].CCR , 10 );
		CLR_BIT( DMA->CHANNEL[ Copy_u8Channel ].CCR , 11 );

	}else if( Copy_MEMSize == HALF_WORD  ){

		SET_BIT( DMA->CHANNEL[ Copy_u8Channel ].CCR , 10 );
		CLR_BIT( DMA->CHANNEL[ Copy_u8Channel ].CCR , 11 );

	}else if ( Copy_MEMSize == WORD ){

		CLR_BIT( DMA->CHANNEL[ Copy_u8Channel ].CCR , 10 );
		SET_BIT( DMA->CHANNEL[ Copy_u8Channel ].CCR , 11 );

	}
	//////////////////////// PERIPHERAL SIZE //////////////////////
	if( Copy_u8PERSize == BYTE ){

		CLR_BIT( DMA->CHANNEL[ Copy_u8Channel ].CCR , 8 );
		CLR_BIT( DMA->CHANNEL[ Copy_u8Channel ].CCR , 9 );

	}else if( Copy_u8PERSize == HALF_WORD  ){

		SET_BIT( DMA->CHANNEL[ Copy_u8Channel ].CCR , 8 );
		CLR_BIT( DMA->CHANNEL[ Copy_u8Channel ].CCR , 9 );

	}else if ( Copy_u8PERSize == WORD ){

		CLR_BIT( DMA->CHANNEL[ Copy_u8Channel ].CCR , 8 );
		SET_BIT( DMA->CHANNEL[ Copy_u8Channel ].CCR , 9 );

	}
	//////////////////////// CHANNEL PRIORITY ///////////////////////////
	if( Copy_u8ChannelPriority == DMA_LOW ){

		CLR_BIT( DMA->CHANNEL[ Copy_u8Channel ].CCR , 12 );
		CLR_BIT( DMA->CHANNEL[ Copy_u8Channel ].CCR , 13 );

	}else if( Copy_u8ChannelPriority == DMA_MEDIUM ){

		SET_BIT( DMA->CHANNEL[ Copy_u8Channel ].CCR , 12 );
		CLR_BIT( DMA->CHANNEL[ Copy_u8Channel ].CCR , 13 );

	}else if( Copy_u8ChannelPriority == DMA_HIGH ){

		CLR_BIT( DMA->CHANNEL[ Copy_u8Channel ].CCR , 12 );
		SET_BIT( DMA->CHANNEL[ Copy_u8Channel ].CCR , 13 );

	}else if( Copy_u8ChannelPriority == DMA_VERY_HIGH ){

		SET_BIT( DMA->CHANNEL[ Copy_u8Channel ].CCR , 12 );
		SET_BIT( DMA->CHANNEL[ Copy_u8Channel ].CCR , 13 );

	}

}


void MDMA_voidDMAEnable( u8 Copy_u8Channel ){

	MDMA_voidClearFlag( Copy_u8Channel , DMA_GIF  );
	MDMA_voidClearFlag( Copy_u8Channel , DMA_TCIF );
	MDMA_voidClearFlag( Copy_u8Channel , DMA_HTIF );
	MDMA_voidClearFlag( Copy_u8Channel , DMA_TEIF );

	SET_BIT( DMA->CHANNEL[ Copy_u8Channel ].CCR , DMA_ENABLE );

}

void MDMA_voidDMADisable( u8 Copy_u8Channel ){

	CLR_BIT( DMA->CHANNEL[ Copy_u8Channel ].CCR , 0 );

}

void MDMA_voidInerruptEnable( u8 Copy_u8Channel , u8 Copy_u8INTSource ){

	SET_BIT( DMA->CHANNEL[ Copy_u8Channel ].CCR , Copy_u8INTSource );

}

void MDMA_voidSetAddress( u8 Copy_u8Channel , u32 * PeripheralAddress , u32 * MemoryAddress , u16 Copy_u16NDT ){

	DMA->CHANNEL[ Copy_u8Channel ].CPAR  = (u32)PeripheralAddress ;
	DMA->CHANNEL[ Copy_u8Channel ].CMAR  = (u32)MemoryAddress ;
	DMA->CHANNEL[ Copy_u8Channel ].CNDTR =  Copy_u16NDT ;

}


void MDMA_voidClearFlag( u8 Copy_u8Channel , u8 Copy_u8Flag ){

	Copy_u8Channel *= 4 ;

	SET_BIT( DMA->IFCR , (Copy_u8Channel + Copy_u8Flag) );

}


u8 MDMA_u8GetFlag( u8 Copy_u8Channel , u8 Copy_u8Flag ){

	u8 LOC_u8Result = 0;

	Copy_u8Channel *= 4 ;

	LOC_u8Result = GET_BIT( DMA->ISR , ( Copy_u8Channel + Copy_u8Flag ) );

	return LOC_u8Result ;

}

/*----------------------------------------------------------------------------------------------------------*/
void MDMA_voidSetCallBackChannel1( void ( *Ptr ) ( void ) ){

	DMA_CallBackChannel1 = Ptr ;

}

void DMA1_Channel1_IRQHandler(void){

	DMA_CallBackChannel1();

}



//==============================================================================================================
