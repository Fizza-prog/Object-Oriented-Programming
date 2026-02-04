#include<iostream>
#include "Matrix.h"
using namespace std;

// Default Constructor
template<typename T>
Matrix<T>::Matrix()
{
    rows = 0;
    columns = 0;
}

// Parameterized Constructor
template<typename T>
Matrix<T>::Matrix(int r, int c)
{
    rows = r;
    columns = c;
    data.resize(r);
    for (int i = 0; i < r; i++)
    {
        data[i].resize(c);
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            data[i][j] = 0;
        }
    }
}

// Copy Constructor
template<typename T>
Matrix<T>::Matrix(const Matrix<T>& other)
{
    rows = other.rows;
    columns = other.columns;
    data.resize(rows);
    for (int i = 0; i < rows; i++)
    {
        data[i].resize(columns);
        for (int j = 0; j < columns; j++)
        {
            data[i][j] = other.data[i][j];
        }
    }
}

// Copy Assignment Operator
template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other)
{
    if (this != &other)
    {
        rows = other.rows;
        columns = other.columns;

        data.resize(rows);
        for (int i = 0; i < rows; i++)
        {
            data[i].resize(columns);
            for (int j = 0; j < columns; j++)
            {
                data[i][j] = other.data[i][j];
            }
        }
    }
    return *this;
}

// Destructor
template<typename T>
Matrix<T>::~Matrix()
{
    rows = 0;
    columns = 0;
}

// Subscript Operator (non-const)
template<typename T>
Array<T>& Matrix<T>::operator[](int index)
{
    return data[index];
}

// Subscript Operator (const)
template<typename T>
const Array<T>& Matrix<T>::operator[](int index) const
{
    return data[index];
}

// Get Rows
template<typename T>
int Matrix<T>::getRows() const
{
    return rows;
}

// Get Columns
template<typename T>
int Matrix<T>::getColumns() const
{
    return columns;
}

// Print Matrix
template<typename T>
void Matrix<T>::print() const
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << data[i][j] << " ";
        }
        cout << "\n";
    }
}

// Equality Operator
template<typename T>
bool Matrix<T>::operator==(const Matrix<T>& r) const
{
    if (rows != r.rows || columns != r.columns)
    {
        return false;
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (data[i][j] != r.data[i][j])
                return false;
        }
    }
    return true;
}

// Transpose
template<typename T>
Matrix<T> Matrix<T>::transpose() const
{
    Matrix<T> t(columns, rows);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            t.data[j][i] = data[i][j];
        }
    }
    return t;
}

// Check Symmetric
template<typename T>
bool Matrix<T>::isSymmetric() const
{
    if (rows != columns)
    {
        return false;
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = i + 1; j < columns; j++)
        {
            if (data[i][j] != data[j][i])
                return false;
        }
    }
    return true;
}

// Resize Matrix
template<typename T>
void Matrix<T>::resize(int newRows, int newCols)
{
    data.resize(newRows);
    for (int i = 0; i < newRows; i++)
    {
        data[i].resize(newCols);
    }
    rows = newRows;
    columns = newCols;
}

// Add Matrices
template<typename T>
Matrix<T> Matrix<T>::add(const Matrix<T>& other) const
{
    if (rows != other.rows || columns != other.columns)
    {
        cout << "Error: Matrices must have the same dimensions to add.\n";
        exit(1);
    }
    Matrix<T> result(rows, columns);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            result[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

// Multiply Matrices
template<typename T>
Matrix<T> Matrix<T>::multiply(const Matrix<T>& other) const
{
    if (columns != other.rows)
    {
        cout << "Error: Incompatible matrix dimensions for multiplication.\n";
        exit(1);
    }
    Matrix<T> result(rows, other.columns);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < other.columns; j++)
        {
            T sum = 0;  // Changed from int to T for template type
            for (int k = 0; k < columns; k++)
            {
                sum = sum + (data[i][k] * other.data[k][j]);
            }
            result[i][j] = sum;
        }
    }
    return result;
}

// Explicit template instantiation
template class Matrix<int>;
template class Matrix<float>;
template class Matrix<double>;