#include "TaskManager.h"

#define MAX_TASKS 2

TaskManager tm(MAX_TASKS);

void print1() {
    Serial.println("3000");
}

void print2() {
    Serial.println("3000");
}

void setup() {
    Serial.begin(115200);
    tm.addTask(print1, 3000);
    tm.addTask(print2, 5000);
}

void loop() {
    tm.update();
}