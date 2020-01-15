#include "leon3.h"
#include "bubblesort.h"
#include "gpio.h"

#include <stdio.h>
#include <stdlib.h>

#define __INLINE __attribute__((always_inline)) 

#define FILLING 6
#define SORTING 7
#define NOTSORTED 8

#define IRUNS 50
#define CALC 6
#define FIN 7
#define ERR 8



volatile uint8_t c0Running = 1;
volatile uint8_t c1Running = 1;
volatile uint32_t C0total = 0;
volatile uint32_t C1total = 0;
uint8_t bsArray0[BSIZE];


int main(){
	if(get_proc_index() == 0){//CPU0
		uint8_t bsArray0[BSIZE];
		int x =0;

		start_processor(1);//start CPU1
	
		for(x=0;x<=500;x++){

		}	
			
		c0Running = 1;

		C0total = 0;
		do{

			fillArray(bsArray0);
			bubblesort(bsArray0);
			C0total++;

		}while(checkarr(bsArray0)!=0);


		c0Running = 0;

	} //fin CPU0
	else{ //CPU(!=0)
		uint8_t bsArray1[BSIZE];
		c1Running = 1;

		C1total = 0;
		do{
			fillArray(bsArray1);
			bubblesort(bsArray1);
			C1total++;
		}while(c1Running == 1);




	}//fin CPU(!=0)

	return 0;
}
