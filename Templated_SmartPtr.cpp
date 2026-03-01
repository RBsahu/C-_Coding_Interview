/*
Definition – Templated SmartPtr
A Templated SmartPtr is a user-defined RAII wrapper class that:
Manages dynamically allocated memory (new)
Automatically releases memory in destructor
Works for any data type using templates
Prevents memory leaks
Implements Rule of Five for safe ownership management

Uses of Templated SmartPtr
1. Resource Acquisition Is Initialization (RAII)

Ensures:
No memory leak
No manual delete
Exception safety

*/

#include <iostream>
using namespace std;

template<typename T>
class Smartptr
{
private:
    T* ptr;

public:

    // 1️ Constructor
    explicit Smartptr(T* p = nullptr)
        : ptr(p)
    {
    }

    // 2️ Destructor
    ~Smartptr()
    {
        delete ptr;  // safe if nullptr
    }

    // 3️ Copy Constructor (Deep Copy)
    Smartptr(const Smartptr& other)
    {
        if (other.ptr)
            ptr = new T(*other.ptr);  // allocate new copy
        else
            ptr = nullptr;
    }

    // 4️ Move Constructor
    Smartptr(Smartptr&& other) noexcept
        : ptr(other.ptr)
    {
        other.ptr = nullptr;  // release source
    }

    // 5️ Copy Assignment (Strong Exception Safe - Copy/Swap)
    Smartptr& operator=(const Smartptr& other)
    {
        if (this != &other)
        {
            Smartptr temp(other);  // may throw, but safe
            swap(ptr, temp.ptr);   // commit change
        }
        return *this;
    }

    // 6️ Move Assignment
    Smartptr& operator=(Smartptr&& other) noexcept
    {
        if (this != &other)
        {
            delete ptr;            // release current
            ptr = other.ptr;       // steal resource
            other.ptr = nullptr;   // reset source
        }
        return *this;
    }

    // Dereference
    T& operator*() const
    {
        return *ptr;
    }

    // Arrow operator
    T* operator->() const
    {
        return ptr;
    }

    // Utility
    T* get() const
    {
        return ptr;
    }
};

class Test
{
public:
    int value;

    Test(int v) : value(v)
    {
        cout << "Constructor\n";
    }

    ~Test()
    {
        cout << "Destructor\n";
    }

    void show() const
    {
        cout << "Value: " << value << endl;
    }
};

int main()
{
    // Memory automatically freed when p1 goes out of scope.
    Smartptr<Test> p1(new Test(10));

    // Copy Constructor
    Smartptr<Test> p2 = p1;

    p2->value = 50;

    cout << "\nAfter copy:\n";
    p1->show();
    p2->show();

    // Move Constructor
    Smartptr<Test> p3 = std::move(p1);

    cout << "\nAfter move:\n";
    if (p1.get() == nullptr)
        cout << "p1 is empty\n";

    p3->show();

    // Copy Assignment
    Smartptr<Test> p4;
    p4 = p2;

    cout << "\nAfter copy assignment:\n";
    p4->show();

    // Move Assignment
    Smartptr<Test> p5;
    p5 = std::move(p2);

    cout << "\nAfter move assignment:\n";
    if (p2.get() == nullptr)
        cout << "p2 is empty\n";

    p5->show();

    return 0;
}