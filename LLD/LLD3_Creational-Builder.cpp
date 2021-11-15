/*Creationd Design pattern: Builder
    1. Class with many attributes
    2. Some attributes are mandatory
    3. Object should be immutable
*/

#include <bits/stdc++.h>
using namespace std;

class Student
{
    string fName;
    string lName;
    int age;

public:
    void printMe()
    {
        cout << "Name: " << fName << " " << lName << endl;
        cout << "Age: " << age << endl;
    }

public:
    class Builder
    {
        string fName, lName;
        int age;

    public:
        Builder setFirstName(string fName)
        {
            this->fName = fName;
            return *this;
        }
        Builder setLastName(string lName)
        {
            this->lName = lName;
            return *this;
        }

        Builder setAge(int age)
        {
            this->age = age;
            return *this;
        }

        Student build()
        {
            Student std;
            std.age = age;
            std.fName = fName;
            std.lName = lName;
            return std;
        }
    };
};

int main()
{

    Student::Builder builder; // = new Student::Builder();
    builder.setFirstName("Sandeep");
    builder.setLastName("Pawar");
    builder.setAge(30);

    builder.setFirstName("Sandeep2").setLastName("Pawar").setAge(30);

    Student std = builder.build();
    std.printMe();

    return 0;
}