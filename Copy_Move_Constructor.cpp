/*
This program demonstrates:
Deep Copy using Copy Constructor
Resource Transfer using Move Constructor
Copy Assignment Operator
Move Assignment Operator
Dynamic Memory Handling
Implementation of Rule of Five

The class manages a dynamically allocated C-style string and ensures safe memory handling
using copy and move semantics to avoid:
Shallow copy problems
Double deletion
Memory leaks
Performance overhead due to unnecessary copying

When the Copy Constructor is Called
Object Initialization from Another Object
Test t1("Ram");
Test t2 = t1;     // Copy Constructor called
Test t2(t1);      // Copy Constructor called
Test t3 = t2;     // Copy Constructor called here
Passing Object by Value to Function
void fun(Test t)
{
}
Test t1("Ram");
fun(t1);          // Copy Constructor called
Returning Object by Value from Function
Test fun()
{
    Test temp("Ram");
    return temp;      // Copy Constructor (may be optimized by RVO)
}
Object Used in Initialization List
Test t1("Ram");
Test t2 = Test(t1);    // Copy Constructor
*/
#include <iostream>
#include <cstring>
using namespace std;

inline void safeStringCopy(char* dest, size_t size, const char* src)
{
#ifdef _WIN32
    strcpy_s(dest, size, src);   // Windows
#else
    strcpy(dest, src);           // Linux / GCC
#endif
}

class Test
{
private:
    char* str;

public:

    // Default Constructor
    Test()
    {
        str = new char[1];      // allocate 1 byte
        str[0] = '\0';         // initialize empty string
        cout << "Default Constructor called" << endl;
    }

    // Parameterized Constructor
    Test(const char* s)
    {
        cout << "Parameterized Constructor called" << endl;
        size_t len = strlen(s) + 1;
        str = new char[len];       // allocate memory
        //strcpy(str, s);            // deep copy
        safeStringCopy(str, len, s);
    }

    // Copy Constructor (Deep Copy)
    Test(const Test& t)
    {
        cout << "Copy Constructor called" << endl;
        size_t len = strlen(t.str) + 1;
        str = new char[len];
        //strcpy(str, t.str);
        safeStringCopy(str, len, t.str);
    }

    // Move Constructor
    Test(Test&& t) noexcept
    {
        cout << "Move Constructor called" << endl;
        str = t.str;       // transfer ownership
        t.str = nullptr;   // avoid double delete
    }

    // Copy Assignment Operator
    Test& operator=(const Test& t)
    {
        cout << "Copy Assignment called" << endl;
        if (this != &t)
        {
            delete[] str;                       // free old memory
            size_t len = strlen(t.str) + 1;
            str = new char[len];
            //strcpy(str, t.str);
            safeStringCopy(str, len, t.str);
        }
        return *this;
    }

    // Move Assignment Operator
    Test& operator=(Test&& t) noexcept
    {
        cout << "Move Assignment called" << endl;
        if (this != &t)
        {
            delete[] str;       // free old memory
            str = t.str;        // transfer ownership
            t.str = nullptr;    // avoid double delete
        }
        return *this;
    }

    // Destructor
    ~Test()
    {
        delete[] str;
    }

    void printString() const
    {
        if (str)
            cout << str << endl;
        else
            cout << "Null" << endl;
    }
};
int main()
{
    Test t1;
    Test t2("Ram");

    t1 = t1;        // self assignment safe

    cout << "Object 2: ";
    t2.printString();

    Test t3 = t2;   // copy constructor
    cout << "Object 3: ";
    t3.printString();

    Test t4 = move(t3);  // move constructor
    cout << "Object 4: ";
    t4.printString();

    cout << "Object 3 after move: ";
    t3.printString();    // safe

    Test t5;
    Test t6("Sahu");

    t5 = move(t6);       // move assignment
    cout << "Object 5: ";
    t5.printString();

    return 0;
}
