/*
Find the Frequency of a Character in a String
Input: 
const char* text = "Ram Sahu 1123";
Output:
Character Frequency:
' ' -> 2
'1' -> 2
'2' -> 1
'3' -> 1
'R' -> 1
'S' -> 1
'a' -> 2
'h' -> 1
'm' -> 1
'u' -> 1
*/
#include <iostream>
using namespace std;

//  function to count character frequency
void countCharFrequency(const char* str, int frequency[256])
{
    // Initialize frequency array to 0
    for (int i = 0; i < 256; ++i)
    {
        frequency[i] = 0;
    }

    // Traverse string
    while (*str != '\0')
    {
        unsigned char ch = *str;  // Avoid negative indexing
        frequency[ch]++;          // Increment frequency
        str++;                    // Move to next character
    }
}

int main()
{    
    const char* text = "Ram Sahu 1123";

    int frequency[256];;

    // Call function
    countCharFrequency(text, frequency);

    cout << "Character Frequency:\n";

    for (int i = 0; i < 256; ++i)
    {
        if (frequency[i] > 0)
        {
            cout << "'" << (char)i << "' -> " << frequency[i] << endl;                
        }
    }
    return 0;
}