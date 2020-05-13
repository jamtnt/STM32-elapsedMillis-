int main(void)
{

  while (1)
  {
      // elapsedMillis 1 starts ---------------------
      static const uint32_t interval_1 = 1000;

      static uint32_t timeElapsed_1 = 0;

      if(HAL_GetTick() - timeElapsed_1 > interval_1)
      {
          HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);

          timeElapsed_1 = HAL_GetTick();
      }
      // elapsedMillis 1 ends -----------------------


      // elapsedMillis 2 starts ---------------------
      static const uint32_t interval_2 = 500;

      static uint32_t timeElapsed_2 = 0;

      if(HAL_GetTick() - timeElapsed_2 > interval_2)
      {

         HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_7);

         timeElapsed_2 = HAL_GetTick();
      }
      // elapsedMillis 2 ends -----------------------
  }

}
