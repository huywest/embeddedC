
#include <stdint.h>
#include <stdio.h>

void delay(void){
	for(int32_t i =0; i<=300000; i++);
}

int main(void)
{
   uint32_t volatile *const pClkctrlReg = (uint32_t*)0x40023830;
   uint32_t volatile *const pPortmodelReg= (uint32_t*)0x40020800;
   uint32_t volatile *const pPortoutlReg= (uint32_t*)0x40020814;
   uint32_t volatile *const pPortinlReg= (uint32_t*)0x40020810;
   uint32_t volatile *const pPortpulllReg= (uint32_t*)0x4002080C;

   // Enable the clock for GPIO peripheral in AHB1 for port C
   *pClkctrlReg |= (1<<2);

   // Set PC0 1 2 3 as output
   *pPortmodelReg &= ~ (0xFF);
   *pPortmodelReg |= 0x55 ;

   // Set PC4 5 6 7 as input
   *pPortmodelReg &= ~(0xFF << 8);

   // Pull-up resistor for PC4 5 6 7
   *pPortpulllReg &= ~(0xFF << 8);
   *pPortpulllReg |= (0x55 << 8);

   while(1){
	   // Make all row high
	   *pPortoutlReg |= 0xF;
	   // Make r1 low
	   *pPortoutlReg &= ~1;

	   if ( !(*pPortinlReg & (1<<4))){
		   delay();
		   printf("1\n");
	   }

	   if ( !(*pPortinlReg & (1<<5))){
		   delay();
	   	   printf("2\n");
	      }

	   if ( !(*pPortinlReg & (1<<6))){
		   delay();
	   	   printf("3\n");
	      }

	   if ( !(*pPortinlReg & (1<<7))){
		   delay();
	   	   printf("A\n");
	      }

	   // Make all row high
	   *pPortoutlReg |= 0xF;
	   // Make r2 low
	   *pPortoutlReg &= ~(1<<1);

	   if ( !(*pPortinlReg & (1<<4))){
		   delay();
		   printf("4\n");
	   }

	   if ( !(*pPortinlReg & (1<<5))){
		   delay();
	   	   printf("5\n");
	      }

	   if ( !(*pPortinlReg & (1<<6))){
		   delay();
	   	   printf("6\n");
	      }

	   if ( !(*pPortinlReg & (1<<7))){
		   delay();
	   	   printf("B\n");
	      }

	   // Make all row high
	   *pPortoutlReg |= 0xF;
	   // Make r3 low
	   *pPortoutlReg &= ~(1<<2);

	   if ( !(*pPortinlReg & (1<<4))){
		   delay();
		   printf("7\n");
	   }

	   if ( !(*pPortinlReg & (1<<5))){
		   delay();
	   	   printf("8\n");
	      }

	   if ( !(*pPortinlReg & (1<<6))){
		   delay();
	   	   printf("9\n");
	      }

	   if ( !(*pPortinlReg & (1<<7))){
		   delay();
	   	   printf("C\n");
	      }

	   // Make all row high
	   *pPortoutlReg |= 0xF;
	   // Make r4 low
	   *pPortoutlReg &= ~(1<<3);

	   if ( !(*pPortinlReg & (1<<4))){
		   delay();
		   printf("*\n");
	   }

	   if ( !(*pPortinlReg & (1<<5))){
		   delay();
	   	   printf("0\n");
	      }

	   if ( !(*pPortinlReg & (1<<6))){
		   delay();
	   	   printf("#\n");
	      }

	   if ( !(*pPortinlReg & (1<<7))){
		   delay();
	   	   printf("D\n");
	      }
   }
}
