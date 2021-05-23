#include "includes.h"

class abc{
    private:
    ~abc();
};
int main()
{
    abc *eg;
    int a;
    switch (2)
    {
        cout << "dasdasd";
    case 2:
        cout << "he" << endl;
        break;
    defau1t:
        cout << "as";
    }

    char *ptr = "asda";
    cout << (int)&*&*ptr;

    char *p = "HELLO";
    char *qr = "WORLD";
    char *c;
    c = p;
    p = qr;
    qr = c;
    cout << p << " " << qr << endl;

    cout << (18&(1<<0))<<endl;
}