/*

 * main.c
 *
 *  Created on: Jul 7, 2021
 *      Author: Mahmoud
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "RCC_interface.h"
#include "STK_interface.h"

#include "HLEDMAT_interface.h"
#include "HLEDMAT_private.h"
#include "HLEDMAT_config.h"


 //0, 66, 126, 66, 0, 0, 12, 18, 34, 68, 34, 18, 12, 0, 0, 30, 32, 32, 32, 30, 0 ,239, 82, 84, 226, 15, 0, 239, 82, 84, 226, 15, 0

    u8 arr1[8]={0, 66, 126, 66, 0, 0, 12, 18};
	u8 arr2[8]={ 66, 126, 66, 0, 0, 12, 18, 34};
	u8 arr3[8]={ 126, 66, 0, 0, 12, 18, 34, 68};
	u8 arr4[8]={  66, 0, 0, 12, 18, 34, 68, 34};
	u8 arr5[8]={ 0, 0, 12, 18, 34, 68, 34, 18};
	u8 arr6[8]={ 0, 12, 18, 34, 68, 34, 18, 12};
	u8 arr7[8]={ 12, 18, 34, 68, 34, 18, 12, 0};
	u8 arr8[8]={ 18, 34, 68, 34, 18, 12, 0, 0};
	u8 arr9[8]={  34, 68, 34, 18, 12, 0, 0, 30 };
	u8 arr10[8]={ 68, 34, 18, 12, 0, 0, 30, 32};
	u8 arr11[8]={ 34, 18, 12, 0, 0, 30, 32, 32};
	u8 arr12[8]={ 18, 12, 0, 0, 30, 32, 32, 32};
	u8 arr13[8]={ 12, 0, 0, 30, 32, 32, 32, 30};
	u8 arr14[8]={ 0, 0, 30, 32, 32, 32, 30, 0};
	u8 arr15[8]={ 0, 30, 32, 32, 32, 30, 0 ,239};
	u8 arr16[8]={ 30, 32, 32, 32, 30, 0 ,239, 82};
	u8 arr17[8]={ 32, 32, 32, 30, 0 ,239, 82, 84};
	u8 arr18[8]={ 32, 32, 30, 0 ,239, 82, 84, 226};
	u8 arr19[8]={ 32, 30, 0 ,239, 82, 84, 226, 15};
	u8 arr20[8]={ 30, 0 ,239, 82, 84, 226, 15, 0};
	u8 arr21[8]={ 0 ,239, 82, 84, 226, 15, 0, 239};
	u8 arr22[8]={ 239, 82, 84, 226, 15, 0, 239, 82};
	u8 arr23[8]={ 82, 84, 226, 15, 0, 239, 82, 84};
	u8 arr24[8]={ 84, 226, 15, 0, 239, 82, 84, 226};
	u8 arr25[8]={ 226, 15, 0, 239, 82, 84, 226, 15};
	u8 arr26[8]={ 15, 0, 239, 82, 84, 226, 15, 0};





void main(void)
{
	RCC_voidInitSysClock();

	RCC_voidEnablePeripheralClock(APB2_BUS,GPIOA_RCC);
	RCC_voidEnablePeripheralClock(APB2_BUS,GPIOB_RCC);

	MSTK_voidInit();

	HLEDMAT_voidInit();
	

	while(1)
	{

		/*  speed  */
		u16 w=5;

		// Display Frame1
		for (u16 i=0 ; i<w ; i++)
				{
					for(u16 j=0 ; j<w ; j++)
					{
						HLEDMAT_voidDisplayFrame(arr1);
					}
				}
		//=============================================
		// Display Frame2
		for (u16 i=0 ; i<w ; i++)
				{
					for(u16 j=0 ; j<w ; j++)
					{
						HLEDMAT_voidDisplayFrame(arr2);
					}
				}
		//=============================================
		// Display Frame3
		for (u16 i=0 ; i<w ; i++)
				{
					for(u16 j=0 ; j<w ; j++)
					{
						HLEDMAT_voidDisplayFrame(arr3);
					}
				}
		//=============================================
		// Display Frame4
		for (u16 i=0 ; i<w ; i++)
				{
					for(u16 j=0 ; j<w ; j++)
					{
						HLEDMAT_voidDisplayFrame(arr4);
					}
				}
		//=============================================
		// Display Frame5
		for (u16 i=0 ; i<w ; i++)
				{
					for(u16 j=0 ; j<w ; j++)
					{
						HLEDMAT_voidDisplayFrame(arr5);
					}
				}
		//=============================================
		// Display Frame6
		for (u16 i=0 ; i<w ; i++)
				{
					for(u16 j=0 ; j<w ; j++)
					{
						HLEDMAT_voidDisplayFrame(arr6);
					}
				}
		//=============================================
		// Display Frame7
		for (u16 i=0 ; i<w ; i++)
				{
					for(u16 j=0 ; j<w ; j++)
					{
						HLEDMAT_voidDisplayFrame(arr7);
					}
				}
		//=============================================
		// Display Frame8
		for (u16 i=0 ; i<w ; i++)
				{
					for(u16 j=0 ; j<w ; j++)
					{
						HLEDMAT_voidDisplayFrame(arr8);
					}
				}
		//=============================================
		// Display Frame9
		for (u16 i=0 ; i<w ; i++)
				{
					for(u16 j=0 ; j<w ; j++)
					{
						HLEDMAT_voidDisplayFrame(arr9);
					}
				}
		//=============================================
		// Display Frame10
		for (u16 i=0 ; i<w ; i++)
				{
					for(u16 j=0 ; j<w ; j++)
					{
						HLEDMAT_voidDisplayFrame(arr10);
					}
				}
		//=============================================
		// Display Frame11
		for (u16 i=0 ; i<w ; i++)
				{
					for(u16 j=0 ; j<w ; j++)
					{
						HLEDMAT_voidDisplayFrame(arr11);
					}
				}
		//=============================================
		// Display Frame12
		for (u16 i=0 ; i<w ; i++)
				{
					for(u16 j=0 ; j<w ; j++)
					{
						HLEDMAT_voidDisplayFrame(arr12);
					}
				}
		//=============================================
		// Display Frame13
		for (u16 i=0 ; i<w ; i++)
				{
					for(u16 j=0 ; j<w ; j++)
					{
						HLEDMAT_voidDisplayFrame(arr13);
					}
				}
		//=============================================
		// Display Frame14
		for (u16 i=0 ; i<w ; i++)
				{
					for(u16 j=0 ; j<w ; j++)
					{
						HLEDMAT_voidDisplayFrame(arr14);
					}
				}
		//=============================================
		// Display Frame15
		for (u16 i=0 ; i<w ; i++)
				{
					for(u16 j=0 ; j<w ; j++)
					{
						HLEDMAT_voidDisplayFrame(arr15);
					}
				}
		//=============================================
		// Display Frame16
		for (u16 i=0 ; i<w ; i++)
				{
					for(u16 j=0 ; j<w ; j++)
					{
						HLEDMAT_voidDisplayFrame(arr16);
					}
				}
		//=============================================
		// Display Frame17
		for (u16 i=0 ; i<w ; i++)
				{
					for(u16 j=0 ; j<w ; j++)
					{
						HLEDMAT_voidDisplayFrame(arr17);
					}
				}
		//=============================================
		// Display Frame18
		for (u16 i=0 ; i<w ; i++)
				{
					for(u16 j=0 ; j<w ; j++)
					{
						HLEDMAT_voidDisplayFrame(arr18);
					}
				}
		//=============================================
		// Display Frame19
		for (u16 i=0 ; i<w ; i++)
				{
					for(u16 j=0 ; j<w ; j++)
					{
						HLEDMAT_voidDisplayFrame(arr19);
					}
				}
		//=============================================
		// Display Frame20
		for (u16 i=0 ; i<w ; i++)
				{
					for(u16 j=0 ; j<w ; j++)
					{
						HLEDMAT_voidDisplayFrame(arr20);
					}
				}
		//=============================================
		// Display Frame21
		for (u16 i=0 ; i<w ; i++)
				{
					for(u16 j=0 ; j<w ; j++)
					{
						HLEDMAT_voidDisplayFrame(arr21);
					}
				}
		//=============================================
		// Display Frame22
		for (u16 i=0 ; i<w ; i++)
				{
					for(u16 j=0 ; j<w ; j++)
					{
						HLEDMAT_voidDisplayFrame(arr22);
					}
				}
		//=============================================
		// Display Frame23
		for (u16 i=0 ; i<w ; i++)
				{
					for(u16 j=0 ; j<w ; j++)
					{
						HLEDMAT_voidDisplayFrame(arr23);
					}
				}
		//=============================================
		// Display Frame24
		for (u16 i=0 ; i<w ; i++)
				{
					for(u16 j=0 ; j<w ; j++)
					{
						HLEDMAT_voidDisplayFrame(arr24);
					}
				}
		//=============================================
		// Display Frame25
		for (u16 i=0 ; i<w ; i++)
				{
					for(u16 j=0 ; j<w ; j++)
					{
						HLEDMAT_voidDisplayFrame(arr25);
					}
				}
		//=============================================
		// Display Frame26
		for (u16 i=0 ; i<w ; i++)
				{
					for(u16 j=0 ; j<w ; j++)
					{
						HLEDMAT_voidDisplayFrame(arr26);
					}
				}
		//=============================================


	}

}


