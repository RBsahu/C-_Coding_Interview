/*
Friend function: 
quick access to private data without needing an object method.
Friend class:
a whole class can access private data, useful for printing, calculations, or utilities.

Key Points:
friend is not a member of the class.
Friend functions or classes can access private/protected members.
Used for tight coupling between classes or external functions that need direct access.

Explanation:
Student keeps name and marks private.
showStudentInfo() is a friend function and can access private members directly.
StudentPrinter is a friend class and all its member functions can access 
private members of Student.
Both can read (and even modify) the private data without making it public.

*/

#include <iostream>
using namespace std;

// Main class
class Student 
{
private:
    string name;
    int marks;

public:
    Student(string n, int m) : name(n), marks(m) {}

    // Friend function declaration
    friend void showStudentInfo(Student s);

    // Friend class declaration
    friend class StudentPrinter;
};

// Friend function definition
void showStudentInfo(Student s) 
{
    cout << "Friend Function:" << endl;
    cout << " Name = " << s.name
        << ", Marks = " << s.marks << endl;
}

// Friend class definition
class StudentPrinter 
{
public:
    void printDetails(Student s) 
    {
		cout << "Friend Class:" << endl;
        cout << " Name = " << s.name
            << ", Marks = " << s.marks << endl;
    }
};

int main() {
    Student s1("Ram", 95);

    // Using friend function
    showStudentInfo(s1);

    // Using friend class
    StudentPrinter printer;
    printer.printDetails(s1);

    return 0;
}