#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

#define timeout   100000
#define PLL_configuration_Mask 0xFFC3FFFF

/*System Clock switch*/
typedef enum{
	HSI_SYS_CLK,HSE_SYS_CLK,PLL_SYS_CLK,HSE_BYP
}Clock_switch;

/* System Clock*/
typedef enum{
	HSI,HSE,PLL,LSI,LSE,BYP,RTC
}System_Clock;

/*PLL Source*/
typedef enum{
	HSI_CLK_devided_by_2,HSE_CLK,HSE_CLK_devided_by_2
}PLL_Source;

/* PLL Multiplication */
typedef enum{
	PLL_CLK_x2,PLL_CLK_x3,PLL_CLK_x4,PLL_CLK_x5,PLL_CLK_x6,PLL_CLK_x7,PLL_CLK_x8,PLL_CLK_x9,PLL_CLK_x10,PLL_CLK_x11,PLL_CLK_x12,PLL_CLK_x13,
	PLL_CLK_x14,PLL_CLK_x15,PLL_CLK_x16
}PLL_Multiplication;

/*AHB Prescaler*/
typedef enum{
	AHB_CLK_devided_by_1,AHB_CLK_devided_by_2,AHB_CLK_devided_by_4,AHB_CLK_devided_by_8,AHB_CLK_devided_by_16,AHB_CLK_devided_by_64,AHB_CLK_devided_by_128,
	AHB_CLK_devided_by_256,AHB_CLK_devided_by_512
}AHB_Prescaler;

/*APB2 Prescaler*/
typedef enum{
	APB2_CLK_devided_by_1,APB2_CLK_devided_by_2=4,APB2_CLK_devided_by_4,APB2_CLK_devided_by_8,APB2_CLK_devided_by_16
}APB2_Prescaler;

/*APB1 Prescaler*/
typedef enum{
	APB1_CLK_devided_by_1,APB1_CLK_devided_by_2=4,APB1_CLK_devided_by_4,APB1_CLK_devided_by_8,APB1_CLK_devided_by_16
}APB1_Prescaler;

typedef enum{
	SYS_CLK=4,HSI_MCO_CLK,HSE_MCO_CLK,PLL_MCO_CLK_devided_by_2
}MCO_CLK;

typedef enum {
	NO_Erorr,Time_out_Erorr, Invalid_Clock_Source
}Erorr_Status;


Erorr_Status RCC_voidEnableClock(uint8_t Copy_u8SysClock);
void RCC_voidDisableClock(uint8_t Copy_u8SysClock);
void RCC_voidPLL_configuration(uint8_t Copy_u8ClkSourse, uint8_t copy_u8Mul);
void RCC_voidSelectSystemClock(uint8_t Copy_u8ClockSource);
void RCC_voidAHB_Prescaler(uint8_t Copy_u8Prescaler);
void RCC_voidAPB1_Prescaler(uint8_t Copy_u8Prescaler);
void RCC_voidAPB2_Prescaler(uint8_t Copy_u8Prescaler);
void RCC_voidADC_Prescaler(uint8_t Copy_u8Prescaler);
void RCC_voidAHB_PeripheralEnable(uint8_t copy_u8peripheral);
void RCC_voidAHB_PeripheralDisable(uint8_t copy_u8peripheral);
void RCC_voidAPB2_PeripheralEnable(uint8_t copy_u8peripheral);
void RCC_voidAPB2_PeripheralDisable(uint8_t copy_u8peripheral);
void RCC_voidAPB1_PeripheralEnable(uint8_t copy_u8peripheral);
void RCC_voidAPB1_PeripheralDisable(uint8_t copy_u8peripheral);
void RCC_voidMCO_Select(uint8_t MCO_source) ;

# endif /*RCC_INTERFACE_H_*/
