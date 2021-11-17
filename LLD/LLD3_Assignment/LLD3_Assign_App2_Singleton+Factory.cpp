/* //Using singleton and Factory
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
    int sal;
    EmployeeType type;

public:
    Employee(EmployeeType type) : type(type) {}
    // virtual void calculateTax(){}; //go for abstract
    // virtual void calculateTax() = 0; //no to interface, its for behavior
    int getSal()
    {
        return sal;
    }

    void setSal(int sal)
    {
        this->sal = sal;
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
    TaxType1(){};
    static TaxType1 *instance;

public:
    TaxType1(const TaxType1 &) = delete;
    TaxType1 &operator=(const TaxType1 &) = delete;

    static TaxType1 *getInstance()
    {
        // static TaxType1 instance;
        // return instance;
        if (!instance)
            instance = new TaxType1();
        return instance;
    }

    int calculateTax(Employee *emp)
    {
        return emp->getSal() * 0.3 + emp->getSal() * 0.03 + emp->getSal() * 0.02; //PT + EC + ST
    }
};

class TaxType2 : public Tax
{
    TaxType2(){};
    static TaxType2 *instance;

public:
    TaxType2(const TaxType2 &) = delete;
    TaxType2 &operator=(const TaxType2 &) = delete;

    static TaxType2 *getInstance()
    {
        // static TaxType2 instance;
        // return instance;
        if (!instance)
            instance = new TaxType2();
        return instance;
    }
    int calculateTax(Employee *emp)
    {
        return emp->getSal() * 0.2; //PT
    }
};

class TaxType3 : public Tax
{

    TaxType3(){};
    static TaxType3 *instance;

public:
    TaxType3(const TaxType3 &) = delete;
    TaxType3 &operator=(const TaxType3 &) = delete;

    static TaxType3 *getInstance()
    {
        // static TaxType3 instance;
        // return instance;
        if (!instance)
            instance = new TaxType3();
        return instance;
    }

    int calculateTax(Employee *emp)
    {
        return emp->getSal() * 0.2 + emp->getSal() * 0.05 + emp->getSal() * 0.02; //PT + GST + ST
    }
};

TaxType1 *TaxType1::instance = nullptr;
TaxType2 *TaxType2::instance = nullptr;
TaxType3 *TaxType3::instance = nullptr;

class TaxCalFactory
{
public:
    Tax *getTaxCal(Employee *e)
    {
        switch (e->getType())
        {
        case FTEMPLOYEE:
            return TaxType1::getInstance();
        case PTEMPLOYEE:
            return TaxType2::getInstance();
        case INTERN:
            return TaxType3::getInstance();
        }
        return nullptr;
    }
};

class FTEmployee : public Employee
{
public:
    FTEmployee() : Employee(FTEMPLOYEE) {}
};

class Intern : public Employee
{

public:
    Intern() : Employee(INTERN) {}
};

class PTEmployee : public Employee
{

public:
    PTEmployee() : Employee(PTEMPLOYEE) {}
};

int main()
{
    Employee *e1 = new FTEmployee();
    e1->setSal(1000);

    Employee *e2 = new PTEmployee();
    e2->setSal(230);

    Employee *e3 = new Intern();
    e3->setSal(120);

    TaxCalFactory taxCalFact;
    cout << taxCalFact.getTaxCal(e1)->calculateTax(e1) << endl;
    cout << taxCalFact.getTaxCal(e2)->calculateTax(e2) << endl;
    cout << taxCalFact.getTaxCal(e3)->calculateTax(e3) << endl;
    return 0;
}