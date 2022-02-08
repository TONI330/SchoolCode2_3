#include <Arduino.h>

TaskHandle_t Task1;
TaskHandle_t Task2;
void Task1code( void * parameter ){
 Serial.print("Task1 running on core ");
 Serial.println(xPortGetCoreID());
 for(;;){}
}
void Task2code( void * pvParameters ){
 Serial.print("Task2 running on core ");
 Serial.println(xPortGetCoreID());
 for(;;){}
}
void setup() {
 Serial.begin(115200);
 xTaskCreatePinnedToCore(Task1code,"Task1",10000,NULL,1,&Task1,0);
 xTaskCreatePinnedToCore(Task2code,"Task2",10000,NULL,1,&Task2,1);

}
void loop() {
}