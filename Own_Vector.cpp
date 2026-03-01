/*
Implementation – Own Vector
Design of Vector

A vector needs:
T* data = dynamically allocated array
size_t size = number of elements
size_t capacity = allocated storage
Growth strategy:
When full = double capacity

This Implementation Covers
 Dynamic memory management
 Doubling growth strategy
 Rule of Five
 Move semantics
 Deep copy
 Constant time push

Capacity growth pattern:
1  2  4  8  16

*/
#include <iostream>
using namespace std;

template<typename T>
class MyVector
{
private:
    T* data_;
    size_t size_;
    size_t capacity_;

    // Reallocate memory when capacity is full
    void reallocate(size_t newCapacity)
    {
        T* newData = new T[newCapacity];

        for (size_t i = 0; i < size_; ++i)
        {
            newData[i] = move(data_[i]);
        }

        delete[] data_;
        data_ = newData;
        capacity_ = newCapacity;
    }

public:

    // 1️ Default Constructor
    MyVector()
        : data_(nullptr), size_(0), capacity_(0)
    {
    }

    // 2️ Destructor
    ~MyVector()
    {
        delete[] data_;
    }

    // 3️ Copy Constructor
    MyVector(const MyVector& other)
        : size_(other.size_), capacity_(other.capacity_)
    {
        data_ = new T[capacity_];
        for (size_t i = 0; i < size_; ++i)
        {
            data_[i] = other.data_[i];
        }
    }

    // 4️ Move Constructor
    MyVector(MyVector&& other) noexcept
        : data_(other.data_), size_(other.size_), capacity_(other.capacity_)
    {
        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }

    // 5️ Copy Assignment
    MyVector& operator=(const MyVector& other)
    {
        if (this != &other)
        {
            delete[] data_;

            size_ = other.size_;
            capacity_ = other.capacity_;

            data_ = new T[capacity_];
            for (size_t i = 0; i < size_; ++i)
            {
                data_[i] = other.data_[i];
            }
        }
        return *this;
    }

    // 6️ Move Assignment
    MyVector& operator=(MyVector&& other) noexcept
    {
        if (this != &other)
        {
            delete[] data_;

            data_ = other.data_;
            size_ = other.size_;
            capacity_ = other.capacity_;

            other.data_ = nullptr;
            other.size_ = 0;
            other.capacity_ = 0;
        }
        return *this;
    }

    // Add element
    void push_back(const T& value)
    {
        if (size_ == capacity_)
        {
            size_t newCapacity = (capacity_ == 0) ? 1 : capacity_ * 2;
            reallocate(newCapacity);
        }

        data_[size_++] = value;
    }

    // Move version
    void push_back(T&& value)
    {
        if (size_ == capacity_)
        {
            size_t newCapacity = (capacity_ == 0) ? 1 : capacity_ * 2;
            reallocate(newCapacity);
        }

        data_[size_++] = std::move(value);
    }

    // Access operator
    T& operator[](size_t index)
    {
        return data_[index];
    }

    const T& operator[](size_t index) const
    {
        return data_[index];
    }

    size_t size() const { return size_; }
    size_t capacity() const { return capacity_; }
};
int main()
{
    MyVector<int> vec;

    for (int i = 1; i <= 10; ++i)
    {
        vec.push_back(i * 10);
        cout << "Size: " << vec.size()
            << " Capacity: " << vec.capacity() << endl;
    }

    cout << "\nElements:\n";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << " ";
    }

    cout << endl;

    return 0;
}