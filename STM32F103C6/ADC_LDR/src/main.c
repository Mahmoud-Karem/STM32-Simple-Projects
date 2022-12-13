#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "NVIC_interface.h"
#include "ADC_interface.h"

u16 ADC_Reading_For_LDR = 0 ;


void func ();

void LightnessAutoModeEnable ()
{
	/*
	 * Hint : We will control The Automatic mode By Change The Direction of PA1
	 * Enable --> i/p  &  Disable --> o/p
	 */
	MDIO_voidSetPinDirection  ( DIOA , PIN0   , INPUT_ANLOG   );
}
void LightnessAutoModeDisable ()
{
	/*
		 * Hint : We will control The Automatic mode By Change The Direction of PA1
		 * Enable --> i/p  &  Disable --> o/p
		 */
	MDIO_voidSetPinDirection(DIOA,PIN0,OUTPUT_SPEED_2MHZ_PP);
}


void main ()
{

	RCC_voidInitSysClock();

	/*Enable RCC for GPIOA */
	RCC_voidEnablePeripheralClock(APB2_BUS,DIOA_RCC);

	/* Enable Clock For ADC2 Peripheral */
	RCC_voidEnablePeripheralClock  ( APB2_BUS , ADC2_RCC );

	/* EN ADC1_2 Interrupt from NVIC  */
	MNVIC_voidEnableInterrupt(18);

	ADC2_voidInit();

	MDIO_voidSetPinDirection(DIOA,PIN8,OUTPUT_SPEED_2MHZ_PP);
	MDIO_voidSetPinDirection(DIOA,PIN11,OUTPUT_SPEED_2MHZ_PP);


	/* PA0 --> i/p pin */
	MDIO_voidSetPinDirection  ( DIOA , PIN0   , INPUT_ANLOG   );


	ADC2_u8StartConversionAsynch(&ADC_Reading_For_LDR , &func);



	while(1)
	{
		/*
		 *	Hint : We will not Enable the EOC interrupt to continue asking about ADC Values
		 *
		 */
		ADC2_voidEnableInterrupt();

		LightnessAutoModeDisable();
		LightnessAutoModeEnable();

	}
}


/*
 * Hint : LDR is a NC (Inverse relationship with lightness)
 *
 */
void func ()
{
	if(ADC_Reading_For_LDR<=1000)
	{
		/* lightness Off */
		MDIO_voidSetPinValue(DIOA,PIN2,DIO_LOW);
		MDIO_voidSetPinValue(DIOA,PIN11,DIO_LOW);

	}
	else
	{
		/* lightness On */
		MDIO_voidSetPinValue(DIOA,PIN2,DIO_HIGH);
		MDIO_voidSetPinValue(DIOA,PIN11,DIO_HIGH);
	}

}
