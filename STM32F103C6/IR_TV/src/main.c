#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"


void MAIN_voidSendSquareWave( GPIO_config_t * Copy_ptrStructPin , u8 Copy_u8HalfCycleTime_usec , u32 Copy_u8Cycles );

int main(void){

	u8 Loc_u8Data;
	RCC_voidInitSysClk();
	RCC_u8EnablePeripheralClk( RCC_APB2_BUS , IOPA );
	STK_voidInit();
	GPIO_config_t LED1 = {GPIO_PORTA , GPIO_PIN0 , GPIO_OUTPUT_10MHZ_PUSHPULL};
	GPIO_config_t PowerOff = {GPIO_PORTA , GPIO_PIN1 , GPIO_INPUT_PULLUP};

	GPIO_u8PinInit( &LED1 );
	GPIO_u8PinInit(&PowerOff);



	while(1){



		GPIO_u8GetPinValue( &PowerOff , &Loc_u8Data);

		if(Loc_u8Data == GPIO_LOW)
		{
			STK_voidSetBusyWait(50000);
			GPIO_u8GetPinValue( &PowerOff , &Loc_u8Data);
			if(Loc_u8Data == GPIO_LOW)
			{
				// Start
				MAIN_voidSendSquareWave( &LED1 , 13 , 172);
				GPIO_u8SetPinValue(&LED1 , GPIO_LOW);
				STK_voidSetBusyWait(4523);
				// DATA

				//E0E0 -> Address of samsung ->1110 0000 1110 0000

				// 1
				MAIN_voidSendSquareWave( &LED1 , 13 , 15);

				GPIO_u8SetPinValue(&LED1 , GPIO_LOW);
				STK_voidSetBusyWait(1683);
				//1
				MAIN_voidSendSquareWave( &LED1 , 13 , 15);

				GPIO_u8SetPinValue(&LED1 , GPIO_LOW);
				STK_voidSetBusyWait(1683);
				//1
				MAIN_voidSendSquareWave( &LED1 , 13 , 15);

				GPIO_u8SetPinValue(&LED1 , GPIO_LOW);
				STK_voidSetBusyWait(1683);
				//0
				MAIN_voidSendSquareWave( &LED1 , 13 , 15);

				GPIO_u8SetPinValue(&LED1 , GPIO_LOW);
				STK_voidSetBusyWait(394);
				//0
				MAIN_voidSendSquareWave( &LED1 , 13 , 15);

				GPIO_u8SetPinValue(&LED1 , GPIO_LOW);
				STK_voidSetBusyWait(394);
				//0
				MAIN_voidSendSquareWave( &LED1 , 13 , 15);

				GPIO_u8SetPinValue(&LED1 , GPIO_LOW);
				STK_voidSetBusyWait(394);
				//0
				MAIN_voidSendSquareWave( &LED1 , 13 , 15);

				GPIO_u8SetPinValue(&LED1 , GPIO_LOW);
				STK_voidSetBusyWait(394);
				//0
				MAIN_voidSendSquareWave( &LED1 , 13 , 15);

				GPIO_u8SetPinValue(&LED1 , GPIO_LOW);
				STK_voidSetBusyWait(394);
				//1
				MAIN_voidSendSquareWave( &LED1 , 13 , 15);

				GPIO_u8SetPinValue(&LED1 , GPIO_LOW);
				STK_voidSetBusyWait(1683);
				//1

				MAIN_voidSendSquareWave( &LED1 , 13 , 15);

				GPIO_u8SetPinValue(&LED1 , GPIO_LOW);
				STK_voidSetBusyWait(1683);
				//1
				MAIN_voidSendSquareWave( &LED1 , 13 , 15);

				GPIO_u8SetPinValue(&LED1 , GPIO_LOW);
				STK_voidSetBusyWait(1683);
				//0
				MAIN_voidSendSquareWave( &LED1 , 13 , 15);

				GPIO_u8SetPinValue(&LED1 , GPIO_LOW);
				STK_voidSetBusyWait(394);

				//0
				MAIN_voidSendSquareWave( &LED1 , 13 , 15);

				GPIO_u8SetPinValue(&LED1 , GPIO_LOW);
				STK_voidSetBusyWait(394);
				//0
				MAIN_voidSendSquareWave( &LED1 , 13 , 15);

				GPIO_u8SetPinValue(&LED1 , GPIO_LOW);
				STK_voidSetBusyWait(394);
				//0
				MAIN_voidSendSquareWave( &LED1 , 13 , 15);

				GPIO_u8SetPinValue(&LED1 , GPIO_LOW);
				STK_voidSetBusyWait(394);
				//0
				MAIN_voidSendSquareWave( &LED1 , 13 , 15);

				GPIO_u8SetPinValue(&LED1 , GPIO_LOW);
				STK_voidSetBusyWait(394);



				//NEXT IS COMMAND
				// ON/OFF COMMAND -> 40BF -> 0100 0000 1011 1111

				//0
				MAIN_voidSendSquareWave( &LED1 , 13 , 15);

				GPIO_u8SetPinValue(&LED1 , GPIO_LOW);
				STK_voidSetBusyWait(394);
				//1
				MAIN_voidSendSquareWave( &LED1 , 13 , 15);

				GPIO_u8SetPinValue(&LED1 , GPIO_LOW);
				STK_voidSetBusyWait(1683);
				//0
				MAIN_voidSendSquareWave( &LED1 , 13 , 15);

				GPIO_u8SetPinValue(&LED1 , GPIO_LOW);
				STK_voidSetBusyWait(394);
				//0
				MAIN_voidSendSquareWave( &LED1 , 13 , 15);

				GPIO_u8SetPinValue(&LED1 , GPIO_LOW);
				STK_voidSetBusyWait(394);

				//0
				MAIN_voidSendSquareWave( &LED1 , 13 , 15);

				GPIO_u8SetPinValue(&LED1 , GPIO_LOW);
				STK_voidSetBusyWait(394);
				//0
				MAIN_voidSendSquareWave( &LED1 , 13 , 15);

				GPIO_u8SetPinValue(&LED1 , GPIO_LOW);
				STK_voidSetBusyWait(394);
				//0
				MAIN_voidSendSquareWave( &LED1 , 13 , 15);

				GPIO_u8SetPinValue(&LED1 , GPIO_LOW);
				STK_voidSetBusyWait(394);
				//0
				MAIN_voidSendSquareWave( &LED1 , 13 , 15);

				GPIO_u8SetPinValue(&LED1 , GPIO_LOW);
				STK_voidSetBusyWait(394);

				//1
				MAIN_voidSendSquareWave( &LED1 , 13 , 15);

				GPIO_u8SetPinValue(&LED1 , GPIO_LOW);
				STK_voidSetBusyWait(1683);
				//0
				MAIN_voidSendSquareWave( &LED1 , 13 , 15);

				GPIO_u8SetPinValue(&LED1 , GPIO_LOW);
				STK_voidSetBusyWait(394);
				//1
				MAIN_voidSendSquareWave( &LED1 , 13 , 15);

				GPIO_u8SetPinValue(&LED1 , GPIO_LOW);
				STK_voidSetBusyWait(1683);
				//1
				MAIN_voidSendSquareWave( &LED1 , 13 , 15);

				GPIO_u8SetPinValue(&LED1 , GPIO_LOW);
				STK_voidSetBusyWait(1683);

				//1
				MAIN_voidSendSquareWave( &LED1 , 13 , 15);

				GPIO_u8SetPinValue(&LED1 , GPIO_LOW);
				STK_voidSetBusyWait(1683);
				//1
				MAIN_voidSendSquareWave( &LED1 , 13 , 15);

				GPIO_u8SetPinValue(&LED1 , GPIO_LOW);
				STK_voidSetBusyWait(1683);
				//1
				MAIN_voidSendSquareWave( &LED1 , 13 , 15);

				GPIO_u8SetPinValue(&LED1 , GPIO_LOW);
				STK_voidSetBusyWait(1683);
				//1
				GPIO_u8SetPinValue(&LED1 , GPIO_HIGH);
				STK_voidSetBusyWait(394);
				GPIO_u8SetPinValue(&LED1 , GPIO_LOW);
				STK_voidSetBusyWait(1683);


				//END SIGNAL
				MAIN_voidSendSquareWave( &LED1 , 13 , 15);

				GPIO_u8SetPinValue(&LED1 , GPIO_LOW);
				STK_voidSetBusyWait(44000);

			}
		}
	}




	return 0;
}


void MAIN_voidSendSquareWave( GPIO_config_t * Copy_ptrStructPin , u8 Copy_u8HalfCycleTime_usec , u32 Copy_u8Cycles){

	u32 Loc_u32Cycles = Copy_u8Cycles;
	while(Loc_u32Cycles){

	GPIO_u8SetPinValue(Copy_ptrStructPin , GPIO_HIGH);
	STK_voidSetBusyWait(Copy_u8HalfCycleTime_usec);

	GPIO_u8SetPinValue(Copy_ptrStructPin , GPIO_LOW);
	STK_voidSetBusyWait(Copy_u8HalfCycleTime_usec);

	Loc_u32Cycles--;
	}


}
