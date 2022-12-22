#include "TaskManager.h"

uint8_t TaskManager::addTask(uint32_t interval, void (*func)()) {
  // make sure the array of tasks is not full
  if (taskCount < maxTasks) {
    // create a new Task and add it to the array of tasks
    tasks[taskCount] = {taskCount, func, interval, millis(), 0, true};
    taskCount++;

    // return the task's unique identifier
    return taskCount - 1;
  }

  // return an error value if the array of tasks is full
  return -1;
}

uint8_t TaskManager::addTask(uint32_t interval, uint16_t times, void (*func)()) {
  // make sure the array of tasks is not full
  if (taskCount < maxTasks) {
    // create a new Task and add it to the array of tasks
    tasks[taskCount] = {taskCount, func, interval, millis(), times, false};
    taskCount++;

    // return the task's unique identifier
    return taskCount - 1;
  }

  // return an error value if the array of tasks is full
  return -1;
}

void TaskManager::removeTask(uint8_t index) {
  // iterate over all the remaining tasks in the array
  for (int i = index; i < taskCount - 1; i++) {
    // move the next task in the array to the current position
    tasks[i] = tasks[i + 1];
  }

  // decrement the task count to account for the removed task
  taskCount--;
}

void TaskManager::update() {
  // iterate over all the tasks in the array
  for (int i = 0; i < taskCount; i++) {
    Task& task = tasks[i];

    // if the task's interval has passed since the last time this code was executed
    if (millis() > task.previousMillis + task.interval) {

      // save the current time plus the task's interval for the next time this code is executed
      task.previousMillis = millis();

      // call the task's function
      task.func();

      // if the task is not set to repeat indefinitely, decrement the number of times it should run
      if (!task.repeat) {
        task.times--;

        // if the task has run the specified number of times, remove it from the array of tasks
        if (task.times == 0) {
          removeTask(i);
        }
      }
    }
  }
}