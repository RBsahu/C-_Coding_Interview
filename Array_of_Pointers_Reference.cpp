/*
Array of Pointers: 
An array where each element stores the address of a variable instead of the variable itself.
Reference: 
An alias for another variable, allow you to access or modify the original variable directly.

A simple diagram to visualize array of pointers + reference:

Variables:       x      y      z
                 5      10     15

Array of Pointers:
   ptrArray[0]  = &x
   ptrArray[1]  = &y
   ptrArray[2]  = &z

Reference to pointer value:
   ref = *ptrArray[1]  // ref is a reference to y
   ref += 5             // modifies y directly

After modification:
   x = 5, y = 15, z = 15

Explanation:
ptrArray[i] stores the address of a variable.
*ptrArray[i] gives the value stored at that address.
int &ref = *ptrArray[i] creates a reference (alias) to that value.
Changing ref changes the original variable directly.

*/
#include <iostream>
using namespace std;

int main() 
{
    int x = 1;
    int y = 2;
    int z = 3;
    
    //int* ptrArray[3] = { &x, &y, &z };

	int* ptrArray[3];
	ptrArray[0] = &x;
	ptrArray[1] = &y;
	ptrArray[2] = &z;

    cout << "Original values:" << endl;
    for (int i = 0; i < 3; i++) 
    {
        cout << *ptrArray[i] << " ";
    }
    cout << endl;

    // Use reference to modify values via pointers
    for (int i = 0; i < 3; i++) 
    {
        int& ref = *ptrArray[i];  // reference to value pointed by pointer
        ref += 10;                // modify original variable
    }

    cout << "After modification via references:" << endl;
    for (int i = 0; i < 3; i++) 
    {
        cout << *ptrArray[i] << " ";
    }
    cout << endl;

    return 0;
}