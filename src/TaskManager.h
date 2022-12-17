#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <Arduino.h>

class TaskManager {
  public:
    TaskManager(uint8_t maxTasks) : tasks(new Task[maxTasks]) { this->maxTasks = maxTasks; }
    ~TaskManager() { delete[] tasks; }

    typedef void (*TaskFunc)();

    // add a task that will run indefinitely
    uint8_t addTask(uint32_t interval, TaskFunc func);

    // add a task that will run for a specified number of times
    uint8_t addTask(uint32_t interval, uint16_t times, TaskFunc func);

    // remove a task from the array of tasks
    void removeTask(uint8_t taskId);

    // update all the tasks in the TaskManager
    void update();
    
  private:
    // this struct holds a function, its associated interval, and the number of times it should run
    struct Task {
      uint8_t taskId;
      TaskFunc func;
      uint32_t interval;
      uint32_t previousMillis;
      uint16_t times;
      bool repeat;
    };

    uint8_t maxTasks = 10; // the maximum number of tasks the TaskManager can hold
    Task* tasks; // a dynamic array to hold the tasks
    uint8_t taskCount = 0; // the number of tasks in the array
};

#endif