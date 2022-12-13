



#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "stm32f103c8.h"

#include "RCC_interface.h"
#include "RCC_config.h"
#include "RCC_private.h"






void RCC_voidInitSysClk(void){

#if SYS_CLK == HSI_CLK
	SET_BIT( RCC -> CR   , 0 );
	CLR_BIT( RCC -> CFGR , 0 );
	CLR_BIT( RCC -> CFGR , 1 );

#elif SYS_CLK == HSE_CLK
	CLR_BIT( RCC -> CR   , 16 );
	#if HSE_BYPASS == HSE_NOT_BYPASSED
		CLR_BIT( RCC -> CR , 18 );
	#elif HSE_BYPASS == HSE_BYPASSED
		SET_BIT( RCC -> CR , 18 );
	#else
		#error("You chosed wrong clock type")
	#endif
	SET_BIT( RCC -> CR   , 16 );
	SET_BIT( RCC -> CFGR , 0  );
	CLR_BIT( RCC -> CFGR , 1  );


#elif SYS_CLK == PLL_CLK
	SET_BIT( RCC -> CR , 24);
	CLR_BIT( RCC -> CFGR , 0 );
	SET_BIT( RCC -> CFGR , 1 );
#else
	#error("You chosed wrong clock type")
#endif

}


u8 RCC_u8EnablePeripheralClk(u8 Copy_u8BusId , u8 Copy_u8PeriId){
	u8 Loc_u8ErrorStatus = STD_TYPES_OK;

	if(Copy_u8PeriId < 32 )
	{
		switch( Copy_u8BusId )
		{
		case RCC_AHB_BUS:
			SET_BIT( RCC->AHBENR , Copy_u8PeriId );
			break;
		case RCC_APB1_BUS:
			SET_BIT( RCC->APB1ENR , Copy_u8PeriId);
			break;
		case RCC_APB2_BUS:
			SET_BIT( RCC->APB2ENR , Copy_u8PeriId );
			break;
		default:
			Loc_u8ErrorStatus = STD_TYPES_NOK;

		}
	}
	else
	{
		Loc_u8ErrorStatus = STD_TYPES_NOK;
	}

	return Loc_u8ErrorStatus;
}

u8 RCC_u8DisablePeripheralClk(u8 Copy_u8BusId , u8 Copy_u8PeriId){
	u8 Loc_u8ErrorStatus = STD_TYPES_OK;

	if(Copy_u8PeriId < 32 )
	{
		switch( Copy_u8BusId )
		{
		case RCC_AHB_BUS:
			CLR_BIT( RCC->AHBENR , Copy_u8PeriId );
			break;
		case RCC_APB1_BUS:
			CLR_BIT( RCC->APB1ENR , Copy_u8PeriId);
			break;
		case RCC_APB2_BUS:
			CLR_BIT( RCC->APB2ENR , Copy_u8PeriId );
			break;
		default:
			Loc_u8ErrorStatus = STD_TYPES_NOK;

		}
	}
	else
	{
		Loc_u8ErrorStatus = STD_TYPES_NOK;
	}

	return Loc_u8ErrorStatus;

}
