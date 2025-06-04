#include <stdint.h>
#include "../LIB/STD_TYPE.h"
#include "../LIB/BIT_MATH.h"
#include "RCC_register.h"
#include "RCC_interface.h"

RCC_REG* RCC=(RCC_REG*)Base_Address;
Erorr_Status RCC_voidEnableClock(uint8_t Copy_u8SysClock)
{
	uint32_t time_counter=0;
	switch(Copy_u8SysClock)
	{
	    case HSI:
	        SET_BIT(RCC->CR, HSION);
	        time_counter=0;
	        while(GET_BIT(RCC->CR, HSIRDY) == 0 ){if(++time_counter>timeout)return Time_out_Erorr;}

	        break;

	    case HSE:
	        SET_BIT(RCC->CR, HSEON);
	        time_counter=0;
	        while(GET_BIT(RCC->CR, HSERDY) == 0 ){if(++time_counter>timeout)return Time_out_Erorr;}

	        break;

	    case PLL:
	        SET_BIT(RCC->CR, PLLON);
	        time_counter=0;
	        while(GET_BIT(RCC->CR, PLLRDY) == 0 ){if(++time_counter>timeout)return Time_out_Erorr;}

	        break;

	    case LSI:
	        SET_BIT(RCC->CSR, LSION);
	        time_counter=0;
	        while(GET_BIT(RCC->CSR, LSIRDY) == 0 ){if(++time_counter>timeout)return Time_out_Erorr;}

	        break;

	    case LSE:
	    	 SET_BIT(RCC->BDCR, LSEON);
	    	 time_counter=0;
	    	 while(GET_BIT(RCC->CSR, LSERDY) == 0 ){if(++time_counter>timeout)return Time_out_Erorr;}

	    	 break;
	    case BYP:
	    	CLR_BIT(RCC->CR, HSEON);
	    	SET_BIT(RCC->CR, HSEBYP);
	    	SET_BIT(RCC->CR, HSEON);
	    	time_counter=0;
	    	  while(GET_BIT(RCC->CR, HSERDY) == 0 ){if(++time_counter>timeout)return Time_out_Erorr;}
	         break;

	    default:
	               return Invalid_Clock_Source;
	}
		return NO_Erorr;
}
void RCC_voidDisableClock(uint8_t Copy_u8SysClock)
{
	switch(Copy_u8SysClock)
	{
	    case HSI:
	       CLR_BIT(RCC->CR, HSION);

	        break;

	    case HSE:
	        CLR_BIT(RCC->CR, HSEON);


	        break;

	    case PLL:
	        CLR_BIT(RCC->CR, PLLON);

	        break;

	    case LSI:
	        CLR_BIT(RCC->CSR, LSION);

	        break;

	    case LSE:
	    	 CLR_BIT(RCC->CSR, LSEON);

	    	 break;
	}

}
void RCC_voidPLL_configuration(uint8_t Copy_u8ClkSourse, uint8_t copy_u8Mul)
{
	CLR_BIT(RCC->CR, PLLON);
	while(GET_BIT(RCC->CR, PLLRDY) !=0);

	switch(Copy_u8ClkSourse)
	{
	case HSI_CLK_devided_by_2:
			CLR_BIT(RCC->CFGR,PLLSRC);
		break;

	case HSE_CLK:
		SET_BIT(RCC->CFGR,PLLSRC);
		CLR_BIT(RCC->CFGR,PLLXTPRE);
		break;

	case HSE_CLK_devided_by_2:
		SET_BIT(RCC->CFGR,PLLSRC);
		SET_BIT(RCC->CFGR,PLLXTPRE);
		break;
	}
	RCC->CFGR= (RCC->CFGR & PLL_configuration_Mask) |(copy_u8Mul<<PLLMUL0);
}

void RCC_voidSelectSystemClock(uint8_t Copy_u8ClockSource)
{
	RCC->CFGR &= ~(0b11 << SW0);
	RCC->CFGR |=  (Copy_u8ClockSource << SW0);
}


void RCC_voidAHB_Prescaler(uint8_t Copy_u8Prescaler)
{
	RCC->CFGR =(RCC->CFGR & 0xFFFFFF0F) |(Copy_u8Prescaler <<HPRE0);
}
void RCC_voidAPB1_Prescaler(uint8_t Copy_u8Prescaler)
{
	RCC->CFGR =(RCC->CFGR & 0xFFFFF8FF) |(Copy_u8Prescaler <<PPRE1_0);
}
void RCC_voidAPB2_Prescaler(uint8_t Copy_u8Prescaler)
{
	RCC->CFGR =(RCC->CFGR & 0xFFFFC7FF) |(Copy_u8Prescaler <<PPRE2_0);
}
void RCC_voidADC_Prescaler(uint8_t Copy_u8Prescaler)
{
	RCC->CFGR =(RCC->CFGR & 0xFFFF3FFF) |(Copy_u8Prescaler <<ADCPRE0);
}

void RCC_voidAHB_PeripheralEnable(uint8_t copy_u8peripheral)
{
	SET_BIT(RCC->AHBENR,copy_u8peripheral);
}
void RCC_voidAHB_PeripheralDisable(uint8_t copy_u8peripheral)
{
	CLR_BIT(RCC->AHBENR,copy_u8peripheral);

}

void RCC_voidAPB2_PeripheralEnable(uint8_t copy_u8peripheral)
{
	SET_BIT(RCC->APB2ENR,copy_u8peripheral);

}
void RCC_voidAPB2_PeripheralDisable(uint8_t copy_u8peripheral)
{
	CLR_BIT(RCC->APB2ENR,copy_u8peripheral);

}
void RCC_voidAPB1_PeripheralEnable(uint8_t copy_u8peripheral)
{
	SET_BIT(RCC->APB1ENR,copy_u8peripheral);

}
void RCC_voidAPB1_PeripheralDisable(uint8_t copy_u8peripheral)
{
	CLR_BIT(RCC->APB1ENR,copy_u8peripheral);

}
void RCC_voidMCO_Select(uint8_t MCO_source) {
    RCC->CFGR = (RCC->CFGR & ~(0b111 << MCO0)) | (MCO_source << MCO0);
}

