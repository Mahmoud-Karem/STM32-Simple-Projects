#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "NVIC_interface.h"
#include "ADC_interface.h"

u16 ADC_Reading_For_LM35 = 0 ;
u16 LM35_u16TempValue = 0 ;


void func ();
void LM35_GetTemp (u16 * Copy_TempVal);

void FanAutoModeEnable ()
{
	/*
	 * Hint : We will control The Automatic mode By Change The Direction of PA1
	 * Enable --> i/p  &  Disable --> o/p
	 */
	MDIO_voidSetPinDirection  ( DIOA , PIN1   , INPUT_ANLOG   );
}
void FanAutoModeDisable ()
{
	/*
		 * Hint : We will control The Automatic mode By Change The Direction of PA1
		 * Enable --> i/p  &  Disable --> o/p
		 */
	MDIO_voidSetPinDirection(DIOA,PIN1,OUTPUT_SPEED_2MHZ_PP);
}


void main ()
{

	RCC_voidInitSysClock();

	/*Enable RCC for GPIOA */
	RCC_voidEnablePeripheralClock(APB2_BUS,DIOA_RCC);

	/*Enable RCC for GPIOB */
	RCC_voidEnablePeripheralClock(APB2_BUS,DIOB_RCC);

	/* Enable Clock For ADC1 Peripheral */
	RCC_voidEnablePeripheralClock  ( APB2_BUS , ADC1_RCC );

	/* EN ADC1_2 Interrupt from NVIC  */
	MNVIC_voidEnableInterrupt(18);

	ADC_voidInit();

	MDIO_voidSetPinDirection(DIOA,PIN8,OUTPUT_SPEED_2MHZ_PP);
	MDIO_voidSetPinDirection(DIOA,PIN9,OUTPUT_SPEED_2MHZ_PP);
	MDIO_voidSetPinDirection(DIOA,PIN10,OUTPUT_SPEED_2MHZ_PP);
	MDIO_voidSetPinDirection(DIOA,PIN11,OUTPUT_SPEED_2MHZ_PP);


	/* PA0 --> i/p pin */
	MDIO_voidSetPinDirection  ( DIOA , PIN1   , INPUT_ANLOG   );


	ADC_u8StartConversionAsynch(&ADC_Reading_For_LM35 , &func);



	while(1)
	{
		/*
		 *	Hint : We will not Enable the EOC interrupt to continue asking about ADC Values
		 *
		 */
		ADC_voidEnableInterrupt();

		FanAutoModeDisable();
		FanAutoModeEnable();

		MDIO_voidSetPinValue(DIOA,PIN11,DIO_HIGH);
	}
}


void LM35_GetTemp (u16 * Copy_TempVal)
{
		u16 Local_u16ADCReference = 3300 ;  // To Convert from ( V --> mV )

		u16 Local_u16AnalogValue = 0  ;
		Local_u16AnalogValue = (u16) ( ( (u32)ADC_Reading_For_LM35 * (u32)Local_u16ADCReference ) /4096UL ) ;


		/* Convert ( mv --> Temp ) */
		(* Copy_TempVal) = ( Local_u16AnalogValue / 10 ) ;

}

void func ()
{
	LM35_GetTemp (&LM35_u16TempValue);
	if((LM35_u16TempValue>0) && (LM35_u16TempValue<=25))
	{
		/* Motor Off */
		MDIO_voidSetPinValue(DIOA,PIN8,DIO_LOW);
		MDIO_voidSetPinValue(DIOA,PIN9,DIO_LOW);
		MDIO_voidSetPinValue(DIOA,PIN10,DIO_LOW);
	}
	else if ((LM35_u16TempValue>25) && (LM35_u16TempValue<=35))
	{
		/*Speed1 */
		MDIO_voidSetPinValue(DIOA,PIN8,DIO_HIGH);
		MDIO_voidSetPinValue(DIOA,PIN9,DIO_LOW);
		MDIO_voidSetPinValue(DIOA,PIN10,DIO_LOW);
	}
	else if ((LM35_u16TempValue>35)  && (LM35_u16TempValue<39))
	{
		/*Speed2 */
		MDIO_voidSetPinValue(DIOA,PIN8,DIO_LOW);
		MDIO_voidSetPinValue(DIOA,PIN9,DIO_HIGH);
		MDIO_voidSetPinValue(DIOA,PIN10,DIO_LOW);

	}
	else if ((LM35_u16TempValue>=39) && (LM35_u16TempValue<60))
	{
		/*Speed3 */
		MDIO_voidSetPinValue(DIOA,PIN8,DIO_LOW);
		MDIO_voidSetPinValue(DIOA,PIN9,DIO_LOW);
		MDIO_voidSetPinValue(DIOA,PIN10,DIO_HIGH);
	}

}
