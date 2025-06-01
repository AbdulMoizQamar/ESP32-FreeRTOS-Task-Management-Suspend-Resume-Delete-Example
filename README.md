# ESP32-FreeRTOS-Task-Management-Suspend-Resume-Delete-Example
This project demonstrates dynamic task control in ESP32 using FreeRTOS within the Arduino framework.
📝 Description:
This project demonstrates dynamic task control in ESP32 using FreeRTOS within the Arduino framework. A task (myTask) is created and then monitored and controlled by a separate controllerTask. Based on a timer, it performs operations such as:
Checking task state using eTaskGetState()
Suspending the task with vTaskSuspend()
Resuming the task with vTaskResume()
Deleting the task using vTaskDelete()
Each operation is logged to the serial monitor, making it easy to observe how FreeRTOS task states change over time.

✅ Features:
Dynamic task lifecycle control
Use of TaskHandle_t for tracking and manipulating tasks
Demonstrates inter-task communication and control logic
Periodic task execution and timing using vTaskDelay()

📦 Requirements:
ESP32 board
Arduino IDE or PlatformIO
FreeRTOS (comes with ESP32 core)
