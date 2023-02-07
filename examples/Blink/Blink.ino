#include "TaskManager.h" // include the TaskManager class

#define MAX_TASKS 2
const int LED_PIN = LED_BUILTIN; // the pin for the on-board LED

TaskManager tm(MAX_TASKS); // create a new TaskManager object
bool isLedOn = false;

void ledTask() {
  if(isLedOn) {
    digitalWrite(LED_PIN, LOW); // turn the LED off
    isLedOn = false;
    return;
  }

  digitalWrite(LED_PIN, HIGH); // turn the LED on
  isLedOn = true;
  return;
}

void setup() {
  pinMode(LED_PIN, OUTPUT); // set the LED pin as an output

  // add the ledTask function to the TaskManager with a 1000ms interval
  int ledOnTaskId = tm.addTask(1000, ledTask);
}

void loop() {
  tm.update(); // update the tasks in the TaskManager
}