#include "Schedular.h"
#include <iostream>

Schedular::Schedular() {
    capacity = 10;
    count = 0;
    tasks = new Task[capacity];
}

Schedular::~Schedular() {
    delete[] tasks;
}

void Schedular::resize() {
    int newCapacity = capacity * 2;
    Task* newTasks = new Task[newCapacity];

    for (int i = 0; i < count; i++) {
        newTasks[i] = tasks[i];
    }

    delete[] tasks;
    tasks = newTasks;
    capacity = newCapacity;
}

void Schedular::addTask(const Task& task) {
    if (count == capacity) {
        resize();
    }
    tasks[count] = task;
    count++;
}

void Schedular::showTasks() const {
    if (count == 0) {
        std::cout << "No tasks scheduled.\n";
        return;
    }

    for (int i = 0; i < count; i++) {
        std::cout << "Task " << i + 1 << ": ";
        tasks[i].show();
        std::cout << "\n";
    }
}
