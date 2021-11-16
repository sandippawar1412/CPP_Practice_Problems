/*
Scaler:
--------------
Problem 1:

Different employees in our company
You know the employee salaries
Calculate tax for every employee
20% PT
3% EC


Problem 2: Future Requirments
Rule for tax calculation changes
FT EMployees
30% PT
3% EC
2% ST
Interns
20% PT
Part Time Employees
20% PT
5% GST
2% ST

Create a client that creates a few employees and assigns them random salaries and types and prints tax amount for each of them.
*/
#include <bits/stdc++.h>
using namespace std;

//Interface
class Tax
{
public:
    virtual int calculateTax(int sal) = 0;
};

class TaxType1 : public Tax
{
public:
    int calculateTax(int sal)
    {
        return sal * 0.3 + sal * 0.03 + sal * 0.02; //PT + EC + ST
    }
};

class TaxType2 : public Tax
{
public:
    int calculateTax(int sal)
    {
        return sal * 0.2; //PT
    }
};

class TaxType3 : public Tax
{
public:
    int calculateTax(int sal)
    {
        return sal * 0.2 + sal * 0.05 + sal * 0.02; //PT + GST + ST
    }
};

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
    Tax *taxObj;

public:
    FTEmployee(string name, string email, string contact, int sal, Tax *taxObj) : Employee(name, email, contact, sal), taxObj(taxObj)
    {
        calculateTax();
    }
    void calculateTax()
    {
        tax = taxObj->calculateTax(sal);
    }
};

class Intern : public Employee
{
    Tax *taxObj;

public:
    Intern(string name, string email, string contact, int sal, Tax *taxObj) : Employee(name, email, contact, sal), taxObj(taxObj)
    {
        calculateTax();
    }
    void calculateTax()
    {
        tax = taxObj->calculateTax(sal);
    }
};

class PTEmployee : public Employee
{
    Tax *taxObj;

public:
    PTEmployee(string name, string email, string contact, int sal, Tax *taxObj) : Employee(name, email, contact, sal), taxObj(taxObj)
    {
        calculateTax();
    }
    void calculateTax()
    {
        tax = taxObj->calculateTax(sal);
    }
};

int main()
{
    Employee *e = new FTEmployee("Sandeep", "sandeep.pawar810@gmail.com", "9876543210", 100000, new TaxType1());
    e->printTax();

    e = new PTEmployee("Sandeep2", "sandeep.pawar810@gmail.com", "9876543210", 30000, new TaxType2());
    e->printTax();

    e = new Intern("Sandeep3", "sandeep.pawar810@gmail.com", "9876543210", 65000, new TaxType3());
    e->printTax();

    return 0;
}