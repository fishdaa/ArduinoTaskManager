#include "TaskManager.h" // include the TaskManager class

const int LED_PIN = LED_BUILTIN; // the pin for the on-board LED

TaskManager tm(2); // create a new TaskManager object

void ledOn() {
  digitalWrite(LED_PIN, HIGH); // turn the LED on
}

void ledOff() {
  digitalWrite(LED_PIN, LOW); // turn the LED off
}

void setup() {
  pinMode(LED_PIN, OUTPUT); // set the LED pin as an output

  // add the ledOn() function to the TaskManager with a 500ms interval
  int ledOnTaskId = tm.addTask(ledOn, 500);

  // add the ledOff() function to the TaskManager with a 1000ms interval
  int ledOffTaskId = tm.addTask(ledOff, 1000);
}

void loop() {
  tm.update(); // update the tasks in the TaskManager
}