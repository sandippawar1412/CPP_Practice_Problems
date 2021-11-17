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

enum EmployeeType
{
    FTEMPLOYEE,
    PTEMPLOYEE,
    INTERN,
};

class Employee //this should be abstact class, how to do it in cpp, without using help of any method
{
private:
    string name;
    string email;
    string contact;
    int sal;
    EmployeeType type;

public:
    int getSal()
    {
        return sal;
    }
    int tax;
    Employee(string name, string email, string contact, int sal, EmployeeType type) : name(name), email(email), contact(contact), sal(sal), type(type) {}
    // virtual void calculateTax(){}; //go for abstract
    // virtual void calculateTax() = 0; //no to interface, its for behavior
    void printTax()
    {
        cout << "Tax Amount: " << tax << endl;
    }
    EmployeeType getType()
    {
        return type;
    }
};

//Interface
class Tax
{
public:
    virtual int calculateTax(Employee *) = 0;
};

class TaxType1 : public Tax
{
public:
    int calculateTax(Employee *emp)
    {
        return emp->getSal() * 0.3 + emp->getSal() * 0.03 + emp->getSal() * 0.02; //PT + EC + ST
    }
};

class TaxType2 : public Tax
{
public:
    int calculateTax(Employee *emp)
    {
        return emp->getSal() * 0.2; //PT
    }
};

class TaxType3 : public Tax
{
public:
    int calculateTax(Employee *emp)
    {
        return emp->getSal() * 0.2 + emp->getSal() * 0.05 + emp->getSal() * 0.02; //PT + GST + ST
    }
};
class TaxCalFactory
{
public:
    Tax *getTaxCal(Employee *e)
    {
        switch (e->getType())
        {
        case FTEMPLOYEE:
            return new TaxType1;
        case PTEMPLOYEE:
            return new TaxType2;
        case INTERN:
            return new TaxType3;
        }
        return nullptr;
    }
};

class FTEmployee : public Employee
{
    Tax *taxObj;

public:
    FTEmployee(string name, string email, string contact, int sal, Tax *taxObj) : Employee(name, email, contact, sal, FTEMPLOYEE), taxObj(taxObj)
    {
        calculateTax();
    }
    int calculateTax()
    {
        tax = taxObj->calculateTax(this);
        return tax;
    }
};

class Intern : public Employee
{
    Tax *taxObj;

public:
    Intern(string name, string email, string contact, int sal, Tax *taxObj) : Employee(name, email, contact, sal, INTERN), taxObj(taxObj)
    {
        calculateTax();
    }
    int calculateTax()
    {
        tax = taxObj->calculateTax(this);
        return tax;
    }
};

class PTEmployee : public Employee
{
    Tax *taxObj;

public:
    PTEmployee(string name, string email, string contact, int sal, Tax *taxObj) : Employee(name, email, contact, sal, PTEMPLOYEE), taxObj(taxObj)
    {
        calculateTax();
    }
    int calculateTax()
    {
        tax = taxObj->calculateTax(this);
        return tax;
    }
};

int main()
{
    Employee *e1 = new FTEmployee("Sandeep", "sandeep.pawar810@gmail.com", "9876543210", 100000, new TaxType1());
    e1->printTax();

    Employee *e2 = new PTEmployee("Sandeep2", "sandeep.pawar810@gmail.com", "9876543210", 30000, new TaxType2());
    e2->printTax();

    Employee *e3 = new Intern("Sandeep3", "sandeep.pawar810@gmail.com", "9876543210", 65000, new TaxType3());
    e3->printTax();

    TaxCalFactory taxCalFact;

    cout << taxCalFact.getTaxCal(e1)->calculateTax(e1) << endl;
    cout << taxCalFact.getTaxCal(e2)->calculateTax(e2) << endl;
    cout << taxCalFact.getTaxCal(e3)->calculateTax(e3) << endl;
    return 0;
}