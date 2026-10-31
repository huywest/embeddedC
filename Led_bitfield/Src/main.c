

#include <stdint.h>
#include "main.h"

int main(void)
{
	RCC_AHB1ENR_t *pClkctrlReg = (RCC_AHB1ENR_t*) 0x40023830;
	GPIOx_MODER_t *pPortAmodelReg = (GPIOx_MODER_t*) 0x40020000;
	GPIOx_ODR_t *pPortAoutlReg = (GPIOx_ODR_t*) 0x40020014;

	//1. Enable the clock for GPIO peripheral in AHB1
	pClkctrlReg -> gpioa_en = 1;

	//2. Set PA5 as output for LED
	// Clear 10th and 11th bits
	pPortAmodelReg -> moder5 = 0;

	// Set to 01
	pPortAmodelReg -> moder5 = 1;

	//3. Set 5th bit of GPIO output data reg to 1
	pPortAoutlReg -> moder5 = 1;


	while(1);
}
