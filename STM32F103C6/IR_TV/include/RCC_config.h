#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_


/* 
* SYS_CLK
* options : -
*
* 1- HSI_CLK
* 2- HSE_CLK
* 3- PLL_CLK
*
*/


#define SYS_CLK HSI_CLK

/* 
* CSS_STATUS
* options : -
*
* 1- CSS_ENABLE
* 2- CSS_DISABLE
*
*/

#define CSS_STATUS CSS_DISABLE


/*
* HSE_BYPASS
* if HSE is bypassed     --> RC clk is selected
* if HSE is not bypassed --> Crystal/Ceramic clk is selected
*
* options : -
*
* 1- HSE_NOT_BYPASSED
* 2- HSE_BYPASSED
*
*/

#define HSE_BYPASS HSE_NOT_BYPASSED


/*
* PLL_SRC 
* options : -
*
* 1- HSI_CLK_DIV_BY_2
* 2- HSE_CLK
*
*/

#define PLL_SRC HSI_CLK_DIV_BY_2


/* 
* PLL_HSE_DIV
* options : -
*
* 1- DIV_BY_2
* 2- NO_DIV
*
*/

#define PLL_HSE_DIV HSE_NOT_DIV




/* 
* PLL_MUL
* options : -
*
* 1-  MUL_BY_2
* 2-  MUL_BY_3
* 3-  MUL_BY_4
* 4-  MUL_BY_5
* 5-  MUL_BY_6
* 6-  MUL_BY_7
* 7-  MUL_BY_8
* 8-  MUL_BY_9
* 9-  MUL_BY_10
* 10- MUL_BY_11
* 11- MUL_BY_12
* 12- MUL_BY_13
* 13- MUL_BY_14
* 14- MUL_BY_15
* 15- MUL_BY_16
*
*/

#define PLL_MUL MUL_BY_2




/* 
* options : -
*
* 1- NO_DIV
* 2- DIV_BY_2
* 3- DIV_BY_4
* 4- DIV_BY_8
* 5- DIV_BY_16
*
*/

#define APB2_PRESCALER NO_DIV


/* 
* options : -
*
* 1- NO_DIV
* 2- DIV_BY_2
* 3- DIV_BY_4
* 4- DIV_BY_8
* 5- DIV_BY_16
*
*/

#define APB1_PRESCALER NO_DIV



/* 
* options : -
*
* 1- NO_DIV
* 2- DIV_BY_2
* 3- DIV_BY_4
* 4- DIV_BY_8
* 5- DIV_BY_16
* 6- DIV_BY_64
* 7- DIV_BY_128
* 8- DIV_BY_256
* 9- DIV_BY_512
*
*/

#define AHB_PRESCALER NO_DIV


/* 
* options : -
*
* 1- NO_CLK
* 2- HSI_CLK
* 3- HSE_CLK
* 4- PLL_CLK
*
*/

#define MCO_CLK NO_CLK

#endif
