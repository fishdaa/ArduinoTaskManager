#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <Arduino.h>


class TaskManager {
  public:
    TaskManager(uint8_t maxTasks) : tasks(new Task[maxTasks]) { this->maxTasks = maxTasks; }
    ~TaskManager() { delete[] tasks; }

    /// @brief Add a task that will run indefinitely.
    /// @param interval The time before the task is executed.
    /// @param func The task to execute.
    /// @return The task id.
    uint8_t addTask(uint32_t interval, void (*func)());

    /// @brief Add a task that will run for a specified number of times
    /// @param interval The time before the task is executed.
    /// @param iterations The number of times the task is executed before it is removed.
    /// @param func The task to execute.
    /// @return The task id.
    uint8_t addTask(uint32_t interval, uint16_t iterations, void (*func)());

    /// @brief Remove a task from the array of tasks
    /// @param taskId The task id to be removed.
    void removeTask(uint8_t taskId);

    /// @brief Updates all the tasks in the TaskManager
    void update();
    
  private:
    // This struct holds a function, its associated interval, and the number of times it should run
    struct Task {
      uint8_t taskId;
      void (*func)();
      uint32_t interval;
      uint32_t previousMillis;
      uint16_t times;
      bool repeat;
    };

    uint8_t maxTasks = 10; // The maximum number of tasks the TaskManager can hold
    Task* tasks; // A dynamic array to hold the tasks
    uint8_t taskCount = 0; // The number of tasks in the array
};

#endif