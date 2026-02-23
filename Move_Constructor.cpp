/*
Move Constructor:
Move constructor transfers ownership instead of copying
Source object must be left in valid but unspecified state
Always set moved object pointer to nullptr
Mark move constructor noexcept for STL optimization
Implement move assignment operator (Rule of Five)
Destructor safely handles nullptr
*/


#include <iostream>
#include <utility>   // Required for std::move
using namespace std;

class Test
{
    int* data;   // Raw pointer to dynamically allocated memory

public:
    // Parameterized Constructor
    Test(int val)
    {
        data = new int(val);   // Allocate memory on heap
    }

    // Move Constructor
    Test(Test&& obj) noexcept   // noexcept improves STL performance
    {
        data = obj.data;        // Transfer ownership of resource
        obj.data = nullptr;     // Avoid double deletion
    }

    // Move Assignment Operator (Rule of Five)
    Test& operator=(Test&& obj) noexcept
    {
        if (this != &obj)       // Avoid self-assignment
        {
            delete data;        // Free existing resource
            data = obj.data;    // Transfer ownership
            obj.data = nullptr; // Nullify source
        }
        return *this;
    }

    // Print function with null check
    void printData()
    {
        if (data)
            cout << "\nData: " << *data;
        else
            cout << "\nData: nullptr ";
    }

    // Destructor
    ~Test()
    {
        delete data;   // Safe even if data is nullptr
    }
};

int main()
{
    Test t1(10);
    t1.printData();

    Test t2 = std::move(t1);  // Move constructor called
    t2.printData();

    t1.printData();           // Now safe (nullptr check added)

    return 0;
}