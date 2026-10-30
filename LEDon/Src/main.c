
#include <stdint.h>


int main(void)
{
   uint32_t *pClkctrlReg= (uint32_t*)0x40023830 ;  // addrs + offset = 0x40023800 + 0x30
   uint32_t *pPortAmodelReg= (uint32_t*)0x40020000 ;  // addrs + offset = 0x40020000 +  0x00
   uint32_t *pPortAoutlReg= (uint32_t*)0x40020014 ;  // addrs + offset = 0x40023800 +  0x14

   //1. Enable the clock for GPIO peripheral in AHB1
   *pClkctrlReg |= 1;

   //2. Set PA5 as output for LED
   // Clear 10th and 11th bits
   *pPortAmodelReg &= ~(3<<10);
   // Set to 01
   *pPortAmodelReg |= (1<<10);

   //3. Set 5th bit of GPIO output data reg to 1
   *pPortAoutlReg |= (1<<5);

   while(1);

}
