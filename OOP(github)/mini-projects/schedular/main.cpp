#include"Schedular.h"
#include"Task.h"
#include"Date.h"
#include"Time.h"
#include"String.h"
#include<iostream>

int main() {
    Scheduler sched;

    Task t1(String("Study C++"), Date(4, 2, 2026), Time(14, 30));
    Task t2(String("Gym"), Date(4, 2, 2026), Time(17, 0));

    sched.addTask(t1);
    sched.addTask(t2);

    std::cout << "Scheduled Tasks:\n";
    sched.showTasks();

    return 0;
}
