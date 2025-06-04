#ifndef RCC_REGISTER_H_
#define RCC_REGISTER_H_


#define Base_Address 0x40021000  //  RCC base address


typedef struct {
	volatile uint32_t CR;              /* RCC Clock control  Register                      Address offset 0x00 */
	volatile uint32_t CFGR;			   /* RCC Clock Configuration  Register                Address offset 0x04 */
	volatile uint32_t CIR;			   /* RCC Clock Interrupt   Register                   Address offset 0x08 */
	volatile uint32_t APB2RSTR;		   /* RCC APB2 Peripheral Reset Register               Address offset 0x0C */
	volatile uint32_t APB1RSTR;		   /* RCC APB1 Peripheral Reset Register               Address offset 0x10 */
	volatile uint32_t AHBENR;		   /* RCC AHB  Peripheral clock Control Enable         Address offset 0x14 */
	volatile uint32_t APB2ENR;		   /* RCC APB2  Peripheral clock Control Enable        Address offset 0x18 */
	volatile uint32_t APB1ENR;		   /* RCC APB1  Peripheral clock Control Enable        Address offset 0x1C */
	volatile uint32_t BDCR;			   /* RCC Backup domain control Register               Address offset 0x20 */
	volatile uint32_t CSR;			   /* RCC Control/status Register                      Address offset 0x24 */

}RCC_REG;

/* Use one of this expressions */
// #define RCC ((volatile RCC_REG*)Base_Address)
//RCC_REG* RCC=(RCC_REG*)Base_Address;

typedef enum{
	HSION ,HSIRDY ,HSITRIM0=3,HSITRIM1,HSITRIM2,HSITRIM3,HSITRIM4,HSEON=16,HSERDY,HSEBYP,CSSON,PLLON=24,PLLRDY
	}RCC_CR_PINS;


typedef enum{
	 SW0 ,SW1 ,SWS0,SWS1,HPRE0,HPRE1,HPRE2,HPRE3,PPRE1_0,PPRE1_1,PPRE1_2,PPRE2_0,PPRE2_1,PPRE2_2,ADCPRE0,ADCPRE1,PLLSRC,PLLXTPRE,
	 PLLMUL0,PLLMUL1,PLLMUL2,PLLMUL3,OTGFSPRE,MCO0=24,MCO1,MCO2
	 }RCC_CFGR_PINS;

typedef enum {
	  LSIRDYF, LSERDYF, HSIRDYF, HSERDYF, PLLRDYF, CSSF = 7,LSIRDYIE = 8, LSERDYIE, HSIRDYIE, HSERDYIE, PLLRDYIE,
	  LSIRDYC = 16, LSERDYC, HSIRDYC, HSERDYC, PLLRDYC, CSSC=23
	 } RCC_CIR_PINS;
typedef enum {
	  AFIOEN, IOPAEN = 2, IOPBEN, IOPCEN, IOPDEN, IOPEEN,ADC1EN=9, ADC2EN, TIM1EN, SPI1EN, USART1EN=14
	 } RCC_APB2ENR_PINS;


typedef enum {
	  TIM2EN, TIM3EN, TIM4EN, TIM5EN, TIM6EN, TIM7EN,WWDGEN = 11,SPI2EN = 14, SPI3EN,USART2EN = 17, USART3EN, UART4EN, UART5EN,
	  I2C1EN, I2C2EN,CAN1EN = 25,BKPEN , PWREN, DACEN
	 } RCC_APB1ENR_PINS;

typedef enum {
	  DMA1EN, DMA2EN, SRAMEN , FLITFEN = 4, CRCEN = 6
	 } RCC_AHBENR_PINS;
typedef enum {
 LSEON,LSERDY,LSEBYP , RTCSEL0 = 8,   RTCSEL1,   RTCEN= 15,  BDRST
	 }RCC_BDCR_PINS;

typedef enum {
	 LSION = 0,LSIRDY,RMVF = 24,PINRSTF,PORRSTF,SFTRSTF,IWDGRSTF,WWDGRSTF,LPWRRSTF
	 } RCC_CSR_PINS;

#endif /* RCC_REGISTER_H_ */
