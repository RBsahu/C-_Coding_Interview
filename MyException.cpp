/********************************************************************
 C++ Exception Handling – Examples of Common Types
 Covers:
 1. Basic try-catch
 2. catch(int)
 3. catch(double)
 4. catch(char const*)
 5. catch(string)
 6. catch(...)
 7. Multiple catch blocks
 8. Nested try-catch
 9. Throw from function
10. Standard exceptions
11. Custom exception class
12. Rethrow exception
********************************************************************/

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// Custom Exception Class
class MyException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Custom Exception Occurred!";
    }
};

// Function throwing exception
void divide(int a, int b)
{
    if (b == 0)
        throw runtime_error("Divide by Zero Error");

    cout << "Result = " << a / b << endl;
}

// Function for rethrow
void testRethrow()
{
    try
    {
        throw invalid_argument("Invalid Argument");
    }
    catch (...)
    {
        cout << "Caught inside function, rethrowing...\n";
        throw;
    }
}

int main()
{
    cout << "===== 1. Basic try-catch =====\n";
    try
    {
        throw 10;
    }
    catch (int x)
    {
        cout << "Caught Integer: " << x << endl;
    }

    cout << "\n===== 2. catch(double) =====\n";
    try
    {
        throw 5.5;
    }
    catch (double d)
    {
        cout << "Caught Double: " << d << endl;
    }

    cout << "\n===== 3. catch(char const*) =====\n";
    try
    {
        throw "Error Message";
    }
    catch (const char* msg)
    {
        cout << "Caught String Literal: " << msg << endl;
    }

    cout << "\n===== 4. catch(string) =====\n";
    try
    {
        throw string("std::string Exception");
    }
    catch (string s)
    {
        cout << "Caught std::string: " << s << endl;
    }

    cout << "\n===== 5. catch(...) Generic =====\n";
    try
    {
        throw 'A';
    }
    catch (...)
    {
        cout << "Caught Unknown Exception\n";
    }

    cout << "\n===== 6. Multiple Catch Blocks =====\n";
    try
    {
        throw 3.14;
    }
    catch (int x)
    {
        cout << "Integer: " << x << endl;
    }
    catch (double y)
    {
        cout << "Double: " << y << endl;
    }

    cout << "\n===== 7. Nested try-catch =====\n";
    try
    {
        try
        {
            throw 100;
        }
        catch (int x)
        {
            cout << "Inner Catch: " << x << endl;
            throw; // rethrow
        }
    }
    catch (int x)
    {
        cout << "Outer Catch: " << x << endl;
    }

    cout << "\n===== 8. Exception from Function =====\n";
    try
    {
        divide(10, 0);
    }
    catch (runtime_error& e)
    {
        cout << e.what() << endl;
    }

    cout << "\n===== 9. Standard Exceptions =====\n";
    try
    {
        throw out_of_range("Out of Range Error");
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
    }

    cout << "\n===== 10. Custom Exception =====\n";
    try
    {
        throw MyException();
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
    }

    cout << "\n===== 11. Rethrow Exception =====\n";
    try
    {
        testRethrow();
    }
    catch (exception& e)
    {
        cout << "Main caught: " << e.what() << endl;
    }

    cout << "\nProgram Completed Successfully\n";

    return 0;
}