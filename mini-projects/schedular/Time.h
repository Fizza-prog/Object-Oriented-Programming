#ifndef TIME_H
#define TIME_H

class Time {
public:
    int hour;
    int minute;

    Time(int h = 0, int m = 0) : hour(h), minute(m) {}

    void print() const;
};

#endif
