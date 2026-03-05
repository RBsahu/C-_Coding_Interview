/*
Definition of l-value and r-value in C++
L-value Definition:
An l-value is an expression that refers to a memory location.
It represents an object that has a stable (identifiable) memory address.
An l-value can appear on the left-hand side of an assignment operator (=).
It represents named variables or objects stored in memory.
The address of an l-value can be taken using the address-of operator (&).

R-value Definition:
An r-value is an expression that represents a temporary value.
It does not have a persistent memory address that can be accessed by the program.
An r-value appears on the right-hand side of an assignment operator (=).
It represents temporary objects, literals, or results of expressions.
The address of an r-value cannot be taken using the address-of operator (&).
An r-value exists only during the evaluation of an expression and is destroyed afterward.

R-value references introduced to:
Enable move semantics
Improve performance
Avoid deep copies
Allow efficient STL container growth
Make generic programming powerful

When r-value is Mandatory to Use (in C++)
1. Right Side of Assignment
The right-hand side of an assignment contains an r-value.
It provides the value to be assigned.
    int x;
    x = 10;   // 10 is an r-value
2. Temporary Values in Expressions
Operations like addition, subtraction, multiplication produce temporary results (r-values).
    int a = 5;
    int b = 3;
    int c = a + b;   // a + b is an r-value
3. Function Return Values
When a function returns a temporary value, it is an r-value.
int add(int a, int b)
{
    return a + b;  // returned value is r-value
}
4. Move Semantics (Modern C++11)
r-values are required for move operations using r-value references (&&).
    string s1 = "Hello";
    string s2 = move(s1);   // move uses r-value
5. Passing Temporary Objects to Functions
Functions that accept r-value references (T&&) require r-values.
void process(int&& x)
{
    cout << x;
}
int main()
{
    process(10);  // 10 is r-value
}

Is this l-value or r-value?
int&& x = 10;
Answer:

10 = r-value
x = l-value because it has a name

Short Answer
r-values are mandatory when dealing with temporary values, arithmetic operations, 
function return values, and move semantics (C++11 r-value references).
*/

#include <iostream>
using namespace std;

void print(int& x) 
{
    cout << " L-value :"<<x;
}

void print(int&& x) 
{
    cout << "\n R-value :"<<x;
}

int main()
{
    int x = 10;   // x is an l-value
    x = 20;       // valid because x has a memory address   
    cout << "\n L Value :" << x << endl;

    int y = 10;      // 10 is an r-value
    int z = y + 5;   // (y + 5) is an r-value
    cout <<" R Value :"<< z << endl;

    int a = 5;
    print(a);      // L-value
    print(10);     // R-value

    cout << endl;
    return 0;
}