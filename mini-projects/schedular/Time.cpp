#include "Time.h"
#include <iostream>

void Time::print() const {
    std::cout << hour << ":" << (minute < 10 ? "0" : "") << minute;
}
