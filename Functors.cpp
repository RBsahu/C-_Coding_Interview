/*
Functor in C++:
Definition: 
A Functor is an object that acts like a function because it overloads the 
function call operator ().

Syntax of Functor:
class ClassName
{
public:
    return_type operator()(parameters)
    {
        // function logic
    }
};
Usage:
ClassName obj;
obj(parameters);

Functors Used in STL:
sort
find_if
count_if
transform
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Add
{
public:
    int operator()(int a, int b) 
    {
        return a + b;
    }
};

class Descending
{
public:
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

//count_if Example (Using Functor)
class GreaterThanFive
{
public:
    bool operator()(int x)
    {
        return x > 5;
    }
};
//find_if Example (Using Functor)
class IsEven
{
public:
    bool operator()(int x)
    {
        return x % 2 == 0;
    }
};


int main()
{
    Add addObj;

    int result = addObj(10, 20);  // calling object like function
	cout << "\nBasic Code Example :" << endl;
    cout << "Result: " << result << endl;

    cout << "\nFunctors Used in STL :" << endl;
    vector<int> v1 = { 5,2,8,1,9 };

    //Descending() is a functor object passed to STL.
    sort(v1.begin(), v1.end(), Descending());

    for (int n : v1)
        cout << n << " ";

    cout << "\ncount_if Example (Using Functor) :" << endl;
    vector<int> v2 = { 2,7,4,9,3,8 };
    for (int n : v2)
        cout << n << " ";
    auto count = count_if(v2.begin(), v2.end(), GreaterThanFive());

    cout << "\nNumbers greater than 5: " << count << endl;

    cout << "\nfind_if Example (Using Functor) :" << endl;
    vector<int> v3 = { 2,3,5,7,8,9,6 };
    for (int n : v3)
        cout << n << " ";

    auto it = find_if(v3.begin(), v3.end(), IsEven());

    if (it != v3.end())
        cout << "\nFirst even number: " << *it << endl;
    else
        cout << "No even number found";

    auto evenCount = count_if(v3.begin(), v3.end(), IsEven());

    cout << "Total Even Numbers: " << evenCount << endl;

    cout << "\nremove_if Example (Using Functor) :" << endl;
    vector<int> v4 = { 1,2,3,4,5,6,7 };
    for (int n : v4)
        cout << n << " ";
	cout << "\nRemove even numbers :" << endl;
    auto it4 = remove_if(v4.begin(), v4.end(), IsEven());

    v4.erase(it4, v4.end());

    for (int x : v4)
        cout << x << " ";

	cout << endl;
    return 0;
}