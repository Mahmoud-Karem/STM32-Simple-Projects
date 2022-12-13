/*
 * GPIO_interface.h
 *
 *  Created on: 20 Sep 2021
 *      Author: mymorning017
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

#define GPIO_PORTA 0
#define GPIO_PORTB 1
#define GPIO_PORTC 2


#define GPIO_PIN0  0
#define GPIO_PIN1  1
#define GPIO_PIN2  2
#define GPIO_PIN3  3
#define GPIO_PIN4  4
#define GPIO_PIN5  5
#define GPIO_PIN6  6
#define GPIO_PIN7  7
#define GPIO_PIN8  8
#define GPIO_PIN9  9
#define GPIO_PIN10 10
#define GPIO_PIN11 11
#define GPIO_PIN12 12
#define GPIO_PIN13 13
#define GPIO_PIN14 14
#define GPIO_PIN15 15

#define GPIO_INPUT_FLOATING          0b0100
#define GPIO_INPUT_PULLUP            0b1000
#define GPIO_INPUT_PULLDOWN          0b1000
#define GPIO_INPUT_ANALOG            0b0000

#define GPIO_OUTPUT_2MHZ_PUSHPULL    0b0010
#define GPIO_OUTPUT_2MHZ_OPENDRAIN   0b0110

#define GPIO_OUTPUT_10MHZ_PUSHPULL   0b0001
#define GPIO_OUTPUT_10MHZ_OPENDRAIN  0b0101

#define GPIO_OUTPUT_50MHZ_PUSHPULL   0b0011
#define GPIO_OUTPUT_50MHZ_OPENDRAIN  0b0111

#define GPIO_HIGH 1
#define GPIO_LOW  0


typedef struct{
	u8 PortId  ;
	u8 PinId   ;
	u8 Mode    ;

}GPIO_config_t;


u8 GPIO_u8PinInit    (const GPIO_config_t * Copy_Structptr);
u8 GPIO_u8SetPinValue(const GPIO_config_t * Copy_Structptr , u8 Copy_u8PinValue   );
u8 GPIO_u8GetPinValue(const GPIO_config_t * Copy_Structptr , u8 * Copy_u8ptrData  );
u8 GPIO_u8TogPinValue(const GPIO_config_t * Copy_Structptr);

u8 GPIO_u8PortInit    (const GPIO_config_t * Copy_Structptr);
u8 GPIO_u8SetPortValue(const GPIO_config_t * Copy_Structptr , u8 Copy_u8PortValue   );
u8 GPIO_u8GetPortValue(const GPIO_config_t * Copy_Structptr , u16 * Copy_u16ptrData );
u8 GPIO_u8TogPortValue(const GPIO_config_t * Copy_Structptr);


#endif /* GPIO_INTERFACE_H_ */
