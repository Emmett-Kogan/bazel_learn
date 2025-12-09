#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

static void task(void *params) {
    for (;;) {
        printf("Hello, World!\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}


int main() {
    if (pdPASS != xTaskCreate(task, "task", 2048, NULL, 1, NULL)) {
        printf("Failed to schedule task");
    }

    printf("Starting scheduler...\n");
    vTaskStartScheduler();

    return 0;
}