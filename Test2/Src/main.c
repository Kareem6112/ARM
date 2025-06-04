/*
 ******************************************************************************
 *
 ******************************************************************************
 * File           : main.c
 * Author         : Kareem Mohammed Mohammed Glela
 * Brief          : RCC Driver
 ******************************************************************************
 *
 ******************************************************************************
 */

#include <stdint.h>
/*#include "../MCAL/RCC/RCC_interface.h"
#include "../MCAL/RCC/RCC_register.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPE.h"*/
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{


    while(1)
    {
        // Main loop
    }

    return 0;
}

