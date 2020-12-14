#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include <xc.h>
#include "semphr.h"
#include "user_structures.h"
#include "user_tasks.h"

fila_clothes_t f_clothes;
machine_t w_machine;
machine_t i_machine;

/*
Implementação das tarefas
 */
/*void ledVermelho() 
{
  TRISCbits.TRISC2 = 0;

  while (1) {
    PORTCbits.RC2 = !PORTCbits.RC2;
    vTaskDelay(50);
  }

}*/

/*void ledVerde() 
{
  TRISCbits.TRISC1 = 0;

  while (1) {
    PORTCbits.RC1 = !PORTCbits.RC1;
    vTaskDelay(50);
  }
}*/

/*
Função principal - coloca o kernel em execução e cria as tarefas
 */
int main(void) {
  
  config_tasks();
 
  xTaskCreate(task_read_buttons, (signed char*) "task_read_buttons", configMINIMAL_STACK_SIZE, NULL, 3, NULL);
  xTaskCreate(check_wash, (signed char*) "check_wash", configMINIMAL_STACK_SIZE, NULL, 3, NULL);
  xTaskCreate(check_ironing, (signed char*) "check_ironing", configMINIMAL_STACK_SIZE, NULL, 3, NULL);  
  
  
  vTaskStartScheduler();
}


