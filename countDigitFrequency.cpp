/*
Find the frequency of a digit in a given number
Input: 11235321

Output:
Digit Occurrences:
1 -> 3
2 -> 2
3 -> 2
5 -> 1

*/

#include <iostream>
using namespace std;

// Reusable function using raw array
void countDigitFrequency(long long number, int frequency[10])
{
    // Initialize array to 0
    for (int i = 0; i < 10; ++i)
    {
        frequency[i] = 0;
    }

    // Handle negative numbers
    if (number < 0)
        number = -number;

    // Special case: number = 0
    if (number == 0)
    {
        frequency[0] = 1;
        return;
    }

    // Count digits
    while (number > 0)
    {
        int digit = number % 10;   // Extract last digit
        frequency[digit]++;        // Increment count
        number /= 10;              // Remove last digit
    }
}

int main()
{
    long long number = 11235321;
   
    int frequency[10];   // Raw array

    // Call reusable function
    countDigitFrequency(number, frequency);

    cout << "Digit Occurrences:\n";
    for (int i = 0; i < 10; ++i)
    {
        if (frequency[i] > 0)
        {
            cout << i << " -> " << frequency[i] << endl;
        }
    }

    return 0;
}