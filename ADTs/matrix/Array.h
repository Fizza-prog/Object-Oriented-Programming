#include <iostream>
using namespace std;

template <typename T> 
class Array
{
    T* data;
    int capacity;

    bool isValid(int ind) const
    {
        return ind >= 0 && ind < capacity;
    }

public:
    Array(int s = 0);

    Array(initializer_list<T> initList);

    Array(const Array<T>& other);

    Array<T>& operator=(const Array<T>& other);

    int getCapacity() const;

    ~Array();

    void resize(int newCap);

    T& operator[](int index);

    const T& operator[](int index) const;

    const T* begin()const;

    const T* end()const;

    Array(Array<T>&& other);

    Array<T>& operator=(Array<T>&&);

    template <typename T>
    friend ostream& operator<<(ostream& os, const Array<T>& arr);

    template <typename T>
    friend istream& operator>>(istream& in, Array<T>& arr);
};

//<<operator
template <typename T> //modified to handle newline and spaces
ostream& operator<<(ostream& os, const Array<T>& arr)
{
        for (int i = 0; i < arr.capacity; i++) {
            os << arr.data[i];               
            if (i != arr.capacity - 1)
                os << ' ';                  
            else
                os << '\n';               
        }
        return os;
   }
 /*ostream& operator<<(ostream& out, const Array& arr) {
    for (int i = 0; i < arr.size; i++)
        out << arr.data[i] << " ";
    return out;
}*/


//>>operator
template <typename T>
istream& operator>>(istream& in, Array<T>& arr)
{
    for (int i = 0; i < arr.capacity; i++)
        in >> arr.data[i];
    return in;
}

// Constructor
template <typename T>
Array<T>::Array(int s)
{
    if (s > 0)
    {
        capacity = s;
        data = new T[capacity];
    }
    else
    {
        capacity = 0;
        data = nullptr;
    }
}

// Copy constructor
template <typename T>
Array<T>::Array(const Array<T>& other)
{
    capacity = other.capacity;
    if (capacity > 0)
    {
        data = new T[capacity];
        for (int i = 0; i < capacity; i++)
            data[i] = other.data[i];
    }
    else
    {
        data = nullptr;
    }
}

// Copy assignment
template <typename T> 
Array<T>& Array<T>::operator=(const Array<T>& other)   
{
    if (this != &other)
    {
        delete[] data;
        capacity = other.capacity;
        if (capacity > 0)
        {
            data = new T[capacity];
            for (int i = 0; i < capacity; i++)
                data[i] = other.data[i];
        }
        else
        {
            data = nullptr;
        }
    }
    return *this;
}

// Get capacity
template <typename T>
int Array<T>::getCapacity() const
{
    return capacity;
}

// Destructor
template <typename T>
Array<T>::~Array()
{
    delete[] data;
    data = nullptr;
    capacity = 0;
}

// Resize
template <typename T>
void Array<T>::resize(int newCap)
{
    if (newCap <= 0)
    {
        delete[] data;
        data = nullptr;
        capacity = 0;
        return;
    }
    T* temp = new T[newCap];
    int i = 0;
    while (i < capacity && i < newCap)
    {
        temp[i] = data[i];
        i++;
    }
    delete[] data;
    data = temp;
    capacity = newCap;
}

// Non-const operator[]
template <typename T>
T& Array<T>::operator[](int index)
{
    if (!isValid(index))
    {
        cout << "Index out of bounds!" << endl;
        exit(1);
    }
    return data[index];
}

// Const operator[]
template <typename T>
const T& Array<T>::operator[](int index) const
{
    if (!isValid(index))
    {
        cout << "Index out of bounds!" << endl;
        exit(1);
    }
    return data[index];
}

//initializer list ctor
template <typename T>
Array<T>::Array(initializer_list<T> initList)
    : capacity(initList.size()) 
{
    data = new T[capacity];
    int i = 0;
    for (const auto& item : initList) {
        data[i++] = item;
    }
}

//begin function
template<typename T>
const T* Array<T>::begin()const 
{
    return &data[0];
}

//end function
template<typename T>
const T* Array<T>::end()const
{
    return &data[capacity];
}

//move ctor
template<typename T>
Array<T>::Array(Array<T>&& other)
{
    if (this != &other)
    {
        data = other.data;
        capacity = other.capacity;
    }
    other.data = nullptr;
    other.capacity = 0;
}

//mov assignment
template<typename T>
 Array<T>& Array<T>::operator=(Array<T>&& other)
{
     if (this != &other)
      { 
         delete[] data;
         data = other.data;
         capacity = other.capacity;
         other.data = nullptr;
         other.capacity = 0;
                        
       }
      return *this;
}

