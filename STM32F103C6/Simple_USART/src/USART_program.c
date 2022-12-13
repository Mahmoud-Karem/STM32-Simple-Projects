/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    USART_program.c   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mahmoud Karem Zamel
 *  Date    : 11/7/2021
 *  Vertion : V01
 *  Layer   : MCAL
 * 
 */ 
 
//=====================================================================================================================
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"


//=====================================================================================================================

#define THRESHOLD_VALUE  9000000UL

void (*USART1_CallBack)(void);

void MUSART1_voidInit(void)
{
	
	/*********************** simple code   **********************************/

	/*
	//	baud rate = 9600		
	USART1 -> BRR = 0x341;

	SET_BIT((USART1-> CR[0]), 3);			// Enabling Transmitter 
	SET_BIT((USART1-> CR[0]), 2);			// Enabling Receiver 
	SET_BIT((USART1-> CR[0]), 13);			// Enabling USART 
	
	USART1 -> SR = 0;						// Clearing status register 
	
	*/
	
	/*********************** More Init   **********************************/
	
	u32 LOC_u64Mantissa = ( F_CPU ) / ( 16 * USART1_BAUD_RATE ) ;

	u32 LOC_u64Fraction = ( ( ( F_CPU * 100 ) / ( 16 * USART1_BAUD_RATE )  ) % 100 ) * 16 ;

	if( LOC_u64Fraction > 1500 ){ LOC_u64Mantissa += 1 ; LOC_u64Fraction  = 0 ; }

	#if USART1_STATUS == USART1_ENABLE

		USART1 -> SR = 0 ;

		#if   USART1_WORD_LENGTH == _8BIT_WORD_LENGTH

					CLR_BIT( USART1 -> CR1 , 12 );

		#elif USART1_WORD_LENGTH == _9BIT_WORD_LENGTH

					SET_BIT( USART1 -> CR1 , 12 );

		#endif

		#if   USART1_PARITY == PARITY_DISABLE

					CLR_BIT( USART1 -> CR1 , 10 );

		#elif USART1_PARITY == EVEN_PARITY

					SET_BIT( USART1 -> CR1 , 10 );
					CLR_BIT( USART1 -> CR1 , 11 );

		#elif USART1_PARITY == ODD_PARITY

					SET_BIT( USART1 -> CR1 , 10 );
					SET_BIT( USART1 -> CR1 , 11 );

		#endif

		#if  USART1_INTERRUPT == INT_DISABLE

					CLR_BIT( USART1 -> CR1 , 5 );
					CLR_BIT( USART1 -> CR1 , 6 );
					CLR_BIT( USART1 -> CR1 , 7 );

		#elif USART1_INTERRUPT == TXE_INT_ENABLE

					SET_BIT( USART1 -> CR1 , 7 );

		#elif USART1_INTERRUPT == TCE_INT_ENABLE

					SET_BIT( USART1 -> CR1 , 6 );

		#elif USART1_INTERRUPT == RXNE_INT_ENABLE

					SET_BIT( USART1 -> CR1 , 5 );

		#endif

		#if   USART1_TRANSMITTER == TRANSMITTER_ENABLE

					SET_BIT( USART1 -> CR1 , 3 );

		#elif USART1_TRANSMITTER == TRANSMITTER_DISABLE

					CLR_BIT( USART1 -> CR1 , 3 );

		#endif

		#if   USART1_RECEIVER == RECEIVER_ENABLE

					SET_BIT( USART1 -> CR1 , 2 );

		#elif USART1_RECEIVER == RECEIVER_DISBLE

					CLR_BIT( USART1 -> CR1 , 2 );

		#endif

		#if   USART1_STOP_BITS == ONE_STOP_BIT

					CLR_BIT( USART1 -> CR2 , 12 ); CLR_BIT( USART1 -> CR2 , 13 );

		#elif USART1_STOP_BITS == HALF_STOP_BIT

					SET_BIT( USART1 -> CR2 , 12 ); CLR_BIT( USART1 -> CR2 , 13 );

		#elif USART1_STOP_BITS == TWO_STOP_BIT

					CLR_BIT( USART1 -> CR2 , 12 ); SET_BIT( USART1 -> CR2 , 13 );

		#elif USART1_STOP_BITS == ONE_AND_HALF_STOP_BIT

					SET_BIT( USART1 -> CR2 , 12 ); SET_BIT( USART1 -> CR2 , 13 );


		#endif

		USART1 -> BRR = ( LOC_u64Mantissa << 4  ) | ( LOC_u64Fraction / 100 ) ;
		SET_BIT( USART1 -> CR1 , 13 );

	#elif USART1_STATUS == USART1_DISABLE
		CLR_BIT( USART1 -> CR1 , 0 );

	#endif

}

void MUSART1_voidTransmit(u8 arr[])
{
	u8 LOC_u8Iterator = 0;
	while(arr[LOC_u8Iterator] != '\0'){
		USART1 -> DR = arr[LOC_u8Iterator];
		/* wait until Tx is comblete  */
		while((GET_BIT((USART1 -> SR), 6)) == 0); // while(((USART1 -> SR) & 0x40) == 0);
		LOC_u8Iterator++;
	}
	
}

u8 MUSART1_u8Receive(void)
{
	u8 Loc_u8ReceivedData = 0;
	/* wait until Rx is comblete  */
	while((GET_BIT((USART1 -> SR), 5)) == 0);
	/* recieve 8bit Data */
	Loc_u8ReceivedData = ( 0xFF & (USART1 -> DR) );
	return (Loc_u8ReceivedData);
}


void MUSART1_voidSetCallBack( void (*ptr) (void) ){

	USART1_CallBack = ptr ;

}

void USART1_IRQHandler(void){

	USART1 -> SR = 0 ;
	USART1_CallBack();

}
