#ifndef SCHEDULAR_H
#define SCHEDULAR_H

#include "Task.h"

class Schedular {
    Task* tasks;
    int capacity;
    int count;

    void resize();

public:
    Schedular();
    ~Schedular();

    void addTask(const Task& task);
    void showTasks() const;
};

#endif
