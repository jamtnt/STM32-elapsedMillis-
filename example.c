// STM32F407VE system clock set to 100 Mhz

uint32_t i = 0;  // make this gloabal for Live Expression wiev in STM32CubeIDE

int main(void)
{
  __HAL_RCC_TIM5_CLK_ENABLE();
  TIM5->PSC = HAL_RCC_GetPCLK1Freq() / 250000;
  TIM5->CR1 = TIM_CR1_CEN;
  TIM5->CNT = -10;

  while (1)
  {
      // elapsedMillis 1 starts ---------------------
      uint32_t microSeconds = TIM5->CNT << 1;
    
      static uint32_t interval_1 = 1000000;

      static uint32_t timeElapsed_1 = 0;

      if(microSeconds - timeElapsed_1 > interval_1)
      {
            HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);

            timeElapsed_1 = microSeconds;
      }
      // elapsedMillis 1 ends -----------------------


      // elapsedMillis 2 starts ---------------------
      static uint32_t interval_2 = 500000;

      static uint32_t timeElapsed_2 = 0;

      if(microSeconds - timeElapsed_2 > interval_2)
      {

           HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_7);

           timeElapsed_2 = microSeconds;
      }
      // elapsedMillis 2 ends -----------------------
      
    
      // elapsedMillis 3 starts ---------------------
      static uint32_t interval_3 = 2000000;

	    static uint32_t timeElapsed_3 = 0;
    
      //static uint32_t i = 0;

	    if(microSeconds - timeElapsed_3 > interval_3)
	    {

            i++;

            timeElapsed_3 = microSeconds;
	    }
      // elapsedMillis 3 ends -----------------------
  }

}
