#ifndef TASK_H
#define TASK_H

#include "Date.h"
#include "Time.h"
#include "String.h"

class Task {
    String title;
    Date date;
    Time time;

public:
    Task();
    Task(const String& t, const Date& d, const Time& ti);

    void show() const;

    String getTitle() const;
    Date getDate() const;
    Time getTime() const;
};

#endif
