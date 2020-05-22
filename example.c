// STM32F407VE system clock set to 168 Mhz

#include "main.h"

uint16_t interval_1 = 500;
uint16_t timeElapsed_1 = 0;

uint16_t interval_2 = 250;
uint16_t timeElapsed_2 = 0;

int main(void)
{
	

  while (1){
	  
	uint16_t milliSeconds = HAL_GetTick();              //Get value from HAL_GetTick() per one loop cycle!
	uint16_t getTime1 = milliSeconds - timeElapsed_1;   //Solution for overflow!
	uint16_t getTime2 = milliSeconds - timeElapsed_2;   //Solution for overflow!

        if(getTime1 > interval_1)
        {
            HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);

            timeElapsed_1 += interval_1;                    //Solution for elapsed time synchronisation!
        }
	  
        if(getTime2 > interval_2)
        {
    	    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_7);

    	    timeElapsed_2 += interval_2;                    //Solution for elapsed time synchronisation!
        }
	  
  }; //while ends

}
