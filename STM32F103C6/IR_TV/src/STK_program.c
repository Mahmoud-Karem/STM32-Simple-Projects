#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include"stm32f103c8.h"

#include "STK_interface.h"
#include "STK_config.h"
#include "STK_private.h"

void STK_voidInit(void){
	
	CLR_BIT( STK->CTRL , 2 );
	
	CLR_BIT( STK->CTRL , 1 );
	

	
}

void STK_voidSetBusyWait(u32 Copy_u32Ticks){
	
	/* Load ticks to load register */
	STK -> LOAD = Copy_u32Ticks;
	
	/* Start Timer */
	SET_BIT(STK->CTRL, 0);
	
	/* Wait till flag is raised */
	while( (GET_BIT(STK->CTRL,16)) == 0);
	
	/* Stop Timer */
	SET_BIT(STK->CTRL, 0);
	STK -> LOAD = 0;
	STK -> VAL  = 0;
	
}
