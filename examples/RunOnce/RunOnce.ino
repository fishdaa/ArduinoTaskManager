#include "TaskManager.h"

#define MAX_TASKS 2

TaskManager tm(MAX_TASKS);

void setup() {
    Serial.begin(115200);

    // this function will always run after 3000 seconds
    tm.addTask(3000, [](){
        Serial.println("3000");
    });

    // this function will run only once after 5 seconds
    tm.addTask(5000, 1, [](){
        Serial.println("5000");
    });
}

void loop() {
    tm.update();
}