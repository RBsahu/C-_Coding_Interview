/************************************************************
 C++ Rule of Five Example
 If a class manages resources (heap memory, file handle, socket),
 usually define these 5 special member functions:

1. Destructor
2. Copy Constructor
3. Copy Assignment Operator
4. Move Constructor
5. Move Assignment Operator

The Five Special Member Functions
Destructor: 
Frees resources (like dynamic memory or file handles) when an object goes out of scope.
Copy Constructor: 
Creates a new object as a "deep copy" of an existing object.
Copy Assignment Operator: 
Assigns the values from one existing object to another existing object.
Move Constructor: 
Transfers ownership of resources from a temporary (rvalue) object to a new object, avoiding expensive copies.
Move Assignment Operator:
Transfers ownership of resources from a temporary object to an existing object
************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Base
{
private:
    char* data;

public:
    // Constructor
    Base(const char* str = "")
    {
        cout << "Constructor\n";
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }
    // 1. Destructor
    ~Base()
    {
        cout << "Destructor\n";
        delete[] data;
    }
    // 2. Copy Constructor (deep copy)
    Base(const Base& other)
    {
        cout << "Copy Constructor\n";
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }
    // 3. Copy Assignment Operator
    Base& operator=(const Base& other)
    {
        cout << "Copy Assignment\n";

        if (this != &other)
        {
            delete[] data;

            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        }
        return *this;
    }
    // 4. Move Constructor
    Base(Base&& other) noexcept
    {
        data = other.data;
        other.data = nullptr;
        cout << "Move Constructor\n";
    }
    // 5. Move Assignment Operator
    Base& operator=(Base&& other) noexcept
    {
        cout << "Move Assignment\n";

        if (this != &other)
        {
            delete[] data;

            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }
    void display() const
    {        
        cout << data  << endl;
    }
};

int main()
{   
    Base obj1("Rule of Five");    
    Base obj2 = obj1;
    
    Base obj3;
    obj3 = obj1;
   
    Base obj4 = move(obj1);
    
    Base obj5;
    obj5 = move(obj2);

    cout << "\nDisplay Objects\n";
    obj3.display();
    obj4.display();
    obj5.display();

    return 0;
}