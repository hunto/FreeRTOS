#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "misc.h"
#include "beep.h"


void LED0_Task(void * pvParameters);
void LED1_Task(void * pvParameters);

int main(void)
{
 
    xTaskCreate(LED0_Task, (const char *)"LED0", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 3, NULL);
    xTaskCreate(LED1_Task, (const char *)"LED1", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 4, NULL);

    vTaskStartScheduler();
}

void LED0_Task(void * pvParameters)
{
		Beep1_Init();
    while (1)
    {
				GPIO_SetBits(GPIO_PORT(BEEP1_GPIO_PORT_NUM),GPIO_PIN(BEEP1_GPIO_PIN_NUM));
        vTaskDelay(1000 / portTICK_RATE_MS);
				GPIO_ResetBits(GPIO_PORT(BEEP1_GPIO_PORT_NUM),GPIO_PIN(BEEP1_GPIO_PIN_NUM));
				vTaskDelay(100 / portTICK_RATE_MS);
    }
}

void LED1_Task(void * pvParameters)
{
	Beep2_Init();
    while (1)
    {
        GPIO_SetBits(GPIO_PORT(BEEP2_GPIO_PORT_NUM),GPIO_PIN(BEEP2_GPIO_PIN_NUM));
        vTaskDelay(10000 / portTICK_RATE_MS);
				GPIO_ResetBits(GPIO_PORT(BEEP2_GPIO_PORT_NUM),GPIO_PIN(BEEP2_GPIO_PIN_NUM));
				vTaskDelay(12 / portTICK_RATE_MS);
    }
}
