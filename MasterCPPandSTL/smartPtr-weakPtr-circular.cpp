/*
Circular Referencec causing non-deletion of objects, which might result in memory leaks
*/
#include <iostream>
#include <memory>

using namespace std;

//#define SMART_PTR shared_ptr
#define SMART_PTR weak_ptr

class Employee;

class Project
{
    SMART_PTR<Employee> sptr;

public:
    void SetPtr(const SMART_PTR<Employee> &ptr)
    {
        sptr = ptr;
        cout << "Reference Count: " << sptr.use_count() << endl;
    }
    Project()
    {
        cout << "Project() Called" << endl;
    }
    ~Project()
    {
        cout << "~Project() Called" << endl;
    }
};

class Employee
{
    SMART_PTR<Project> sptr;

public:
    void SetPtr(const SMART_PTR<Project> &ptr)
    {
        sptr = ptr;
        cout << "Reference Count: " << sptr.use_count() << endl;
    }
    Employee()
    {
        cout << "Employe() Called" << endl;
    }
    ~Employee()
    {
        cout << "~Employe() Called" << endl;
    }
};
/*
#define SMART_PTR shared_ptr
//Circular References
Employe() Called
Project() Called
Reference Count: 2
Reference Count: 2
------------------------
#define SMART_PTR weak_ptr
Employe() Called
Project() Called
Reference Count: 1
Reference Count: 1
~Project() Called
~Employe() Called
*/

int main()
{
    shared_ptr<Employee> eptr(new Employee{});
    shared_ptr<Project> pptr(new Project{});
    pptr->SetPtr(eptr);
    eptr->SetPtr(pptr);
}