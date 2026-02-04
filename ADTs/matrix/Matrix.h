#ifndef MATRIX_H
#define MATRIX_H

#include "Array.h"

template<typename T>
class Matrix
{
    int rows, columns;
    Array<Array<T>> data;
    
public:
    Matrix();
    Matrix(int r, int c);
    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);
    ~Matrix();
    
    Array<T>& operator[](int index);
    const Array<T>& operator[](int index) const;
    
    int getRows() const;
    int getColumns() const;
    void print() const;
    
    bool operator==(const Matrix& r) const;
    Matrix transpose() const;
    bool isSymmetric() const;
    
    void resize(int newRow, int newCol);
    Matrix add(const Matrix& r) const;
    Matrix multiply(const Matrix& r) const;
};
#endif