#include <bits/stdc++.h>
using namespace std;

class Employee
{
private:
    string name;
    string email;
    string contact;

protected:
    int sal;
    int tax;

public:
    Employee(string name, string email, string contact, int sal) : name(name), email(email), contact(contact), sal(sal) {}
    virtual void calculateTax() = 0;
    void printTax()
    {
        cout << "Tax Amount: " << tax << endl;
    }
};

class FTEmployee : public Employee
{
public:
    FTEmployee(string name, string email, string contact, int sal) : Employee(name, email, contact, sal)
    {
        calculateTax();
    }
    void calculateTax()
    {
        tax = sal * 0.3 + sal * 0.03 + sal * 0.02;
    }
};

class Intern : public Employee
{
public:
    Intern(string name, string email, string contact, int sal) : Employee(name, email, contact, sal)
    {
        calculateTax();
    }
    void calculateTax()
    {
        tax = sal * 0.2;
    }
};

class PTEmployee : public Employee
{
public:
    PTEmployee(string name, string email, string contact, int sal) : Employee(name, email, contact, sal)
    {
        calculateTax();
    }
    void calculateTax()
    {
        tax = sal * 0.2 + sal * 0.05 + sal * 0.02;
    }
};

int main()
{
    Employee *e = new FTEmployee("Sandeep", "sandeep.pawar810@gmail.com", "9876543210", 100000);
    e->printTax();

    e = new PTEmployee("Sandeep2", "sandeep.pawar810@gmail.com", "9876543210", 30000);
    e->printTax();

    e = new Intern("Sandeep3", "sandeep.pawar810@gmail.com", "9876543210", 65000);
    e->printTax();

    return 0;
}