/*********************************************************************************/
/* Author    : Ahmed Atia                                                        */
/* Version   : V01                                                               */
/* Date      : 12 August 2020                                                    */
/*********************************************************************************/
#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H


#define GPIOA_Base_Address        0x40010800            // define the boundary address of GPIO port A
#define GPIOB_Base_Address        0x40010C00            // define the boundary address of GPIO port B
#define GPIOC_Base_Address        0x40011000            // define the boundary address of GPIO port C

        /*       REGISTERS ADDRESSES FOR Port A        */

#define GPIOA_CRL                 *((u32*)(GPIOA_Base_Address + 0x00))
#define GPIOA_CRH                 *((u32*)(GPIOA_Base_Address + 0x04))
#define GPIOA_IDR                 *((u32*)(GPIOA_Base_Address + 0x08))
#define GPIOA_ODR                 *((u32*)(GPIOA_Base_Address + 0x0c))
#define GPIOA_BSR                 *((u32*)(GPIOA_Base_Address + 0x10))
#define GPIOA_BRR                 *((u32*)(GPIOA_Base_Address + 0x14))
#define GPIOA_LCK                 *((u32*)(GPIOA_Base_Address + 0x18))

        /*       REGISTERS ADDRESSES FOR Port B        */

#define GPIOB_CRL                 *((u32*)(GPIOB_Base_Address + 0x00))
#define GPIOB_CRH                 *((u32*)(GPIOB_Base_Address + 0x04))
#define GPIOB_IDR                 *((u32*)(GPIOB_Base_Address + 0x08))
#define GPIOB_ODR                 *((u32*)(GPIOB_Base_Address + 0x0c))
#define GPIOB_BSR                 *((u32*)(GPIOB_Base_Address + 0x10))
#define GPIOB_BRR                 *((u32*)(GPIOB_Base_Address + 0x14))
#define GPIOB_LCK                 *((u32*)(GPIOB_Base_Address + 0x18))

        /*       REGISTERS ADDRESSES FOR Port C        */

#define GPIOC_CRL                 *((u32*)(GPIOC_Base_Address + 0x00))
#define GPIOC_CRH                 *((u32*)(GPIOC_Base_Address + 0x04))
#define GPIOC_IDR                 *((u32*)(GPIOC_Base_Address + 0x08))
#define GPIOC_ODR                 *((u32*)(GPIOC_Base_Address + 0x0c))
#define GPIOC_BSR                 *((u32*)(GPIOC_Base_Address + 0x10))
#define GPIOC_BRR                 *((u32*)(GPIOC_Base_Address + 0x14))
#define GPIOC_LCK                 *((u32*)(GPIOC_Base_Address + 0x18))

#endif