#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

TaskHandle_t taskHandle1;

void myTask(void *pvParameter) {
  for (;;) {
    Serial.println("Running myTask...");
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void controllerTask(void *pvParameter) {
  int counter = 0;
  for (;;) {
    counter++;

    if (counter == 5) {
      Serial.print("Task state at 5 : ");
      Serial.println(eTaskGetState(taskHandle1));
    } 
    else if (counter == 10) {
      vTaskSuspend(taskHandle1);
      Serial.println("myTask Suspended");
    } 
    else if (counter == 15) {
      Serial.print("Task state at 15: ");
      Serial.println(eTaskGetState(taskHandle1));
    } 
    else if (counter == 20) {
      vTaskResume(taskHandle1);
      Serial.println("myTask Resumed");
    } 
    else if (counter == 25) {
      Serial.print("Task state at 25: ");
      Serial.println(eTaskGetState(taskHandle1));
    } 
    else if (counter == 30) {
      vTaskDelete(taskHandle1);
      taskHandle1 = NULL;  
      Serial.println("myTask Deleted");
    } 
    else if (counter == 35) {
      if (taskHandle1 == NULL) {
        Serial.println("myTask handle is NULL (deleted)");
      } else {
        Serial.print("Task state at 35: ");
        Serial.println(eTaskGetState(taskHandle1));
      }
    }

    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void setup() {
  Serial.begin(115200);


  xTaskCreatePinnedToCore(myTask, "MyTask", 2048, NULL, 1, &taskHandle1, 0);

  xTaskCreatePinnedToCore(controllerTask, "ControllerTask", 2048, NULL, 1, NULL, 1);
}

void loop() {

}
