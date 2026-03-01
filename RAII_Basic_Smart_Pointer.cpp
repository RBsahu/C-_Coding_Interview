/*
Basic RAII Smart Pointer example.
What is Rule of Three?
Answer:

If a class manages a resource and defines a destructor, it must also define a 
copy constructor and copy assignment operator to ensure correct deep copy semantics 
and avoid resource duplication issues such as double deletion.


If your class manages a resource (like dynamic memory, file handle, socket, mutex, 
etc.), the compiler-generated copy operations will perform shallow copy.

That leads to:
Double delete 
Memory corruption 
Undefined behavior 

Smartptr p1(new int(10));
Smartptr p2 = p1;  // shallow copy

p1.ptr = 0x1000
p2.ptr = 0x1000

When both destructors run:
delete 0x1000;  
delete 0x1000;  

Rule of Zero
If possible, don’t manage resources manually.
Use:
std::unique_ptr
std::shared_ptr
std::vector
std::string

*/

#include <iostream>
using namespace std;

// A simple unique ownership smart pointer
class Smartptr
{
    int* ptr;  // raw pointer being managed

public:
    // Constructor - takes ownership of raw pointer
    explicit Smartptr(int* p = nullptr)
        : ptr(p)   // member initializer list
    {
    }

    // Destructor - releases owned memory
    ~Smartptr()
    {
        delete ptr;   // safe even if ptr == nullptr
    }

    // Delete copy constructor (avoid shallow copy)
    // Smartptr(const Smartptr&) = delete;

    // Copy Constructor (Deep Copy)
    Smartptr(const Smartptr& other)
    {
        if (other.ptr)
            ptr = new int(*other.ptr);  // allocate new memory and copy value
        else
            ptr = nullptr;
    }

    // Delete copy assignment (avoid shallow copy)
    //Smartptr& operator=(const Smartptr&) = delete;

       // Copy Assignment Operator (Deep Copy)
    Smartptr& operator=(const Smartptr& other)
    {
        if (this != &other)   // protect against self-assignment
        {
            delete ptr;       // delete current resource

            if (other.ptr)
                ptr = new int(*other.ptr);  // deep copy
            else
                ptr = nullptr;
        }
        return *this;
    }

    // Move constructor (transfer ownership)
    Smartptr(Smartptr&& other) noexcept
        : ptr(other.ptr)
    {
        other.ptr = nullptr;  // release ownership from source
    }

    // Move assignment operator
    Smartptr& operator=(Smartptr&& other) noexcept
    {
        if (this != &other)
        {
            delete ptr;           // delete existing resource
            ptr = other.ptr;      // transfer ownership
            other.ptr = nullptr;  // release source
        }
        return *this;
    }

    // Dereference operator
    int& operator*() const
    {
        return *ptr;
    }

    // Arrow operator (for class types - optional here)
    int* operator->() const
    {
        return ptr;
    }
};

int main()
{
    Smartptr ptr(new int());   // allocate memory
    *ptr = 20;                 // assign value
    cout << *ptr << endl;      // print value

    // Move example
    Smartptr ptr2 = std::move(ptr);

    if (&ptr2)
        cout << "Ownership transferred successfully\n";

    Smartptr p3;
    p3 = ptr2;  // Copy assignment

    cout << "p3 value: " << *p3 << endl;  // 10

	Smartptr p4 = p3;  // Copy constructor
	cout << "p4 value: " << *p4 << endl;  // 10

    return 0;
}