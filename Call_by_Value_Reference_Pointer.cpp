/*
Call by Value (Copy of Variable Passed):
 The function receives a copy of the variable.
 Changes inside the function do NOT affect the original variable.

 Call by Reference:
 The function receives a reference (alias) to the original variable.
 Changes inside the function modify the original variable.

 Call by Pointer:
 The function receives the address of the variable.
 Pointer is used to modify the value.

*/

#include <iostream>
using namespace std;

//C++ examples for Call by Value, Call by Reference, and Call by Pointer
void modifyValue(int x)
{
    x = x + 10;
    cout << "Inside function: " << x << endl;
}
void modifyReference(int& x)
{
    x = x + 10;
    cout << "Inside function: " << x << endl;
}
void modifyPointer(int* x)
{
    *x = *x + 10;
    cout << "Inside function: " << *x << endl;
}

//Swap using Call by Value
void swapValue(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;

    cout << "Inside function: a=" << a << " b=" << b << endl;
}
//Swap using Call by Reference
void swapReference(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
//Swap using Call by Pointer
void swapPointer(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
	cout << "Call by Value:" << endl;
    int num = 5;
    cout << "Before function call: " << num << endl;
        //Original variable num not changed.
    modifyValue(num);
    cout << "After function call: " << num << endl;

	cout << "\nCall by Reference:" << endl;
    int num1 = 5;
    cout << "Before function call: " << num1 << endl;
    // Original variable num1 changed.
    modifyReference(num);
    cout << "After function call: " << num1 << endl;

	cout << "\nCall by Pointer:" << endl;
    int num2 = 5;
    cout << "Before function call: " << num2 << endl;
	// Original variable num2 changed.
    modifyPointer(&num);
    cout << "After function call: " << num2 << endl;

    //Swap two variables using Call by Value, Call by Reference, and Call by Pointer.
	cout << "\nSwap TWO variable :" << endl;
    int x = 10;
    int y = 20;
    cout << "Before swap: x=" << x << " y=" << y << endl;
    //Swap fails because values are copied.
    swapValue(x, y);
    cout << "After swap: x=" << x << " y=" << y << endl;
    
    int x1 = 10;
    int y1 = 20;
    cout << "\nBefore swap: x1=" << x << " y1=" << y1 << endl;
    swapReference(x1, y1);
    cout << "After swap: x1=" << x1 << " y1=" << y1 << endl;

    int x2 = 10;
    int y2 = 20;
    cout << "\nBefore swap: x2=" << x2 << " y2=" << y2 << endl;
    swapPointer(&x2, &y2);
    cout << "After swap: x2=" << x2 << " y2=" << y2 << endl;

    return 0;
}