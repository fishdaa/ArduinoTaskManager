#include "TaskManager.h"

#define MAX_TASKS 2

TaskManager tm(MAX_TASKS);

void setup() {
    Serial.begin(115200);

    tm.addTask(3000, [](){
        Serial.println("3000");
    });

    tm.addTask(5000, [](){
        Serial.println("5000");
    });
}

void loop() {
    tm.update();
}