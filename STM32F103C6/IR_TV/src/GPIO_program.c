/*
 * GPIO_program.c
 *
 *  Created on: 20 Sep 2021
 *      Author: mymorning017
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "stm32f103c8.h"

#include "GPIO_interface.h"
#include "GPIO_config.h"
#include "GPIO_private.h"

static GPIO_REGDEF_T * GPIO_ArrPtrStruct [3] = {GPIOA , GPIOB , GPIOC};

u8 GPIO_u8PinInit    (const GPIO_config_t * Copy_Structptr){

	u8 Loc_u8ErrorStatus = STD_TYPES_OK;

	if( (Copy_Structptr != NULL) && (Copy_Structptr->PortId <= GPIOC) ){
		if(  Copy_Structptr->PinId <= GPIO_PIN7 ) //CRL_REG
		{
			(GPIO_ArrPtrStruct[Copy_Structptr->PortId]->CRL) &= ~(0b1111  << ( (Copy_Structptr->PinId) *4) );

			(GPIO_ArrPtrStruct[Copy_Structptr->PortId]->CRL) |=  ( Copy_Structptr->Mode << ( (Copy_Structptr->PinId)  *4) );

		}
		else if( Copy_Structptr->PinId <= GPIO_PIN15 ) //CRH_REG
		{
			(GPIO_ArrPtrStruct[Copy_Structptr->PortId]->CRH) &= ~(0b1111  << ( (Copy_Structptr->PinId - 8) *4) );

			(GPIO_ArrPtrStruct[Copy_Structptr->PortId]->CRH) |=  ( Copy_Structptr->Mode << ( (Copy_Structptr->PinId - 8)  *4) );
		}
		else
		{
			Loc_u8ErrorStatus = STD_TYPES_NOK;
		}
		switch(Copy_Structptr -> Mode)
		{
		case GPIO_INPUT_PULLUP:
			SET_BIT( (GPIO_ArrPtrStruct[Copy_Structptr->PortId]->BSRR) , Copy_Structptr->PinId);
			break;

		/*case GPIO_INPUT_PULLDOWN:
			SET_BIT( (GPIO_ArrPtrStruct[Copy_Structptr->PortId]->BRR) , Copy_Structptr->PinId);
			break;*/

		default:
			break;
		}
	}
	else{
		Loc_u8ErrorStatus = STD_TYPES_NOK;
	}
	return Loc_u8ErrorStatus;
}
u8 GPIO_u8SetPinValue(const GPIO_config_t * Copy_Structptr , u8 Copy_u8PinValue   ){
	u8 Loc_u8ErrorStatus = STD_TYPES_OK;

	if( (Copy_Structptr != NULL) && ( (Copy_Structptr->PortId) <= GPIOC) ){

		switch ( Copy_u8PinValue ){
		case GPIO_HIGH:
			SET_BIT( GPIO_ArrPtrStruct[Copy_Structptr->PortId]->BSRR , Copy_Structptr->PinId );
			break;

		case GPIO_LOW:
			SET_BIT( GPIO_ArrPtrStruct[Copy_Structptr->PortId]->BRR , Copy_Structptr->PinId );
			break;

		default:
			Loc_u8ErrorStatus = STD_TYPES_NOK;
			break;
		}

	}
	else{
		Loc_u8ErrorStatus = STD_TYPES_NOK;
	}
	return Loc_u8ErrorStatus;
}
u8 GPIO_u8GetPinValue(const GPIO_config_t * Copy_Structptr , u8 * Copy_u8ptrData  ){

	u8 Loc_u8ErrorStatus = STD_TYPES_OK;

	if( (Copy_Structptr != NULL) && ( Copy_Structptr->PortId  <= GPIO_PORTC ) ){

		*Copy_u8ptrData = GET_BIT( GPIO_ArrPtrStruct[ Copy_Structptr->PortId ] -> IDR , Copy_Structptr->PinId );

	}
	else{
		Loc_u8ErrorStatus = STD_TYPES_NOK;
	}



	return Loc_u8ErrorStatus;
}
u8 GPIO_u8TogPinValue(const GPIO_config_t * Copy_Structptr){

	u8 Loc_u8ErrorStatus = STD_TYPES_OK;

	if( (Copy_Structptr != NULL) && ( Copy_Structptr->PortId  <= GPIO_PORTC ) ){

		TOG_BIT( GPIO_ArrPtrStruct[ Copy_Structptr->PortId ] -> ODR , Copy_Structptr->PinId );

	}
	else{
		Loc_u8ErrorStatus = STD_TYPES_NOK;
	}



	return Loc_u8ErrorStatus;
}

u8 GPIO_u8PortInit    (const GPIO_config_t * Copy_Structptr){

	u8 Loc_u8ErrorStatus = STD_TYPES_OK;
	u8 Loc_u8Iterator = 0;
	if( (Copy_Structptr != NULL) && (Copy_Structptr->PortId <= GPIOC) ){

		(GPIO_ArrPtrStruct[Copy_Structptr->PortId]->CRL) = 0x00000000;
		(GPIO_ArrPtrStruct[Copy_Structptr->PortId]->CRH) = 0x00000000;

		for(  ; Loc_u8Iterator <= 7 ; Loc_u8Iterator++ ){

			(GPIO_ArrPtrStruct[Copy_Structptr->PortId]->CRL) |=  ( Copy_Structptr->Mode << ( (Copy_Structptr->PinId)  *4) );
			(GPIO_ArrPtrStruct[Copy_Structptr->PortId]->CRH) |=  ( Copy_Structptr->Mode << ( (Copy_Structptr->PinId)  *4) );
		}

		switch(Copy_Structptr -> Mode)
		{
		case GPIO_INPUT_PULLUP:
			(GPIO_ArrPtrStruct[Copy_Structptr->PortId]->BSRR) |=  0x0000FFFF ;
			break;

		/*case GPIO_INPUT_PULLDOWN:
			(GPIO_ArrPtrStruct[Copy_Structptr->PortId]->BRR) |=  0x0000FFFF ;
			break;*/

		default:
			break;
		}

	}
	else{
		Loc_u8ErrorStatus = STD_TYPES_NOK;
	}
	return Loc_u8ErrorStatus;
}
u8 GPIO_u8SetPortValue(const GPIO_config_t * Copy_Structptr , u8 Copy_u8PortValue   ){

	u8 Loc_u8ErrorStatus = STD_TYPES_OK;

	if( (Copy_Structptr != NULL) && (Copy_Structptr->PortId <= GPIOC) ){

		switch ( Copy_u8PortValue ){
		case GPIO_HIGH:
			(GPIO_ArrPtrStruct[Copy_Structptr->PortId]->BSRR) |=  0x0000FFFF ;
			break;

		case GPIO_LOW:
			(GPIO_ArrPtrStruct[Copy_Structptr->PortId]->BRR) |=  0x0000FFFF ;
			break;

		default:
			Loc_u8ErrorStatus = STD_TYPES_NOK;
			break;
		}

	}
	else{
		Loc_u8ErrorStatus = STD_TYPES_NOK;
	}
	return Loc_u8ErrorStatus;


}
u8 GPIO_u8GetPortValue(const GPIO_config_t * Copy_Structptr , u16 * Copy_u16ptrData ){

	u8 Loc_u8ErrorStatus = STD_TYPES_OK;

	if( (Copy_Structptr != NULL) && ( Copy_Structptr->PortId  <= GPIO_PORTC ) ){

		*Copy_u16ptrData =  GPIO_ArrPtrStruct[ Copy_Structptr->PortId ] -> IDR ;

	}
	else{
		Loc_u8ErrorStatus = STD_TYPES_NOK;
	}



	return Loc_u8ErrorStatus;
}
u8 GPIO_u8TogPortValue(const GPIO_config_t * Copy_Structptr){

	u8 Loc_u8ErrorStatus = STD_TYPES_OK;

	if( (Copy_Structptr != NULL) && ( Copy_Structptr->PortId  <= GPIO_PORTC ) ){

		(GPIO_ArrPtrStruct[ Copy_Structptr->PortId ] -> ODR ) ^= 0xFFFFFFFF;
	}
	else{
		Loc_u8ErrorStatus = STD_TYPES_NOK;
	}



	return Loc_u8ErrorStatus;

}
