#ifndef DATE_H
#define DATE_H

class Date {
public:
    int day;
    int month;
    int year;

    Date(int d = 1, int m = 1, int y = 2000)
        : day(d), month(m), year(y) {}

    void print() const;
};

#endif
