#include "../includes.h"

int main()
{
    try
    {
        try
        {
            int a= 2/0;
        }
        catch (...)
        {
            cout << "exception occured"<<endl;
            throw runtime_error("again");
        }
        cout<<"After 1st catch"<<endl;
    }
    catch (...)
    {
        cout << "Outside exception caught"<<endl;
    }
}