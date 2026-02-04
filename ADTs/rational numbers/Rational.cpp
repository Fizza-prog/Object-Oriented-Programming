#include "Rational.h"

int Rational::gcd(int a, int b) const {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void Rational::reduce() {
    int g = gcd(numerator, denominator);
    numerator /= g;
    denominator /= g;
}

Rational::Rational(int n, int d) : numerator(n), denominator(d) {
    if (denominator == 0) denominator = 1; // avoid zero division
    reduce();
}

Rational Rational::operator+(const Rational& other) const {
    return Rational(numerator * other.denominator + other.numerator * denominator,
                    denominator * other.denominator);
}

Rational Rational::operator-(const Rational& other) const {
    return Rational(numerator * other.denominator - other.numerator * denominator,
                    denominator * other.denominator);
}

Rational Rational::operator*(const Rational& other) const {
    return Rational(numerator * other.numerator, denominator * other.denominator);
}

Rational Rational::operator/(const Rational& other) const {
    return Rational(numerator * other.denominator, denominator * other.numerator);
}

void Rational::print() const {
    std::cout << numerator << "/" << denominator;
}
