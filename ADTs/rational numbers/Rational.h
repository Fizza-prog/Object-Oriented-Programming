#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational {
    int numerator;
    int denominator;

    void reduce(); // reduce fraction to lowest terms
    int gcd(int a, int b) const;

public:
    Rational(int n = 0, int d = 1);
    Rational operator+(const Rational& other) const;
    Rational operator-(const Rational& other) const;
    Rational operator*(const Rational& other) const;
    Rational operator/(const Rational& other) const;

    void print() const;
};

#endif
