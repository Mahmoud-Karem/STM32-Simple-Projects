/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    USART_private.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mahmoud Karem Zamel
 *  Date    : 11/7/2021
 *  Vertion : V01
 *  Layer   : MCAL
 * 
 */ 
#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

typedef struct{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;
}USART_Type;


#define USART1 ( ( volatile USART_Type* ) 0x40013800 )

#define USART2 ( ( volatile USART_Type* ) 0x40004400 )

#define USART3 ( ( volatile USART_Type* ) 0x40004800 )

#define UART4 (  ( volatile USART_Type* ) 0x40004C00 )

#define UART5 (  ( volatile USART_Type* ) 0x40005000 )


#endif
