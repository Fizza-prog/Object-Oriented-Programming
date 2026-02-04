#include "Task.h"
#include <iostream>

Task::Task() : title(""), date(), time() {}

Task::Task(const String& t, const Date& d, const Time& ti) 
    : title(t), date(d), time(ti) {}

void Task::show() const {
    std::cout << "Title: ";
    title.display();
    std::cout << ", Date: ";
    date.print();
    std::cout << ", Time: ";
    time.print();
}

String Task::getTitle() const { return title; }
Date Task::getDate() const { return date; }
Time Task::getTime() const { return time; }
