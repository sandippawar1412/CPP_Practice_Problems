#include <bits/stdc++.h>
using namespace std;

class Pizza
{
    int cost;

public:
    virtual int getCost() = 0;
    virtual string getComposition() = 0;
};

class PizzaBase : public Pizza
{
public:
    PizzaBase(){};
    int getCost()
    {
        return 50;
    }
    string getComposition()
    {
        return "Pizza_Base";
    }
};

class CheeseTopping : public Pizza
{
    Pizza *pizza;

public:
    CheeseTopping(Pizza *pizza) : pizza(pizza) {}
    int getCost()
    {
        return pizza->getCost() + 25;
    }
    string getComposition()
    {
        return pizza->getComposition() + " Cheese";
    }
};

class PaneerTopping : public Pizza
{
    Pizza *pizza;

public:
    PaneerTopping(Pizza *pizza) : pizza(pizza) {}
    int getCost()
    {
        return pizza->getCost() + 25;
    }
    string getComposition()
    {
        return pizza->getComposition() + " Paneer";
    }
};

class SauceTopping : public Pizza
{
    Pizza *pizza;

public:
    SauceTopping(Pizza *pizza) : pizza(pizza) {}
    int getCost()
    {
        return pizza->getCost() + 25;
    }
    string getComposition()
    {
        return pizza->getComposition() + " Sauce";
    }
};

int main()
{
    Pizza *pz = new SauceTopping(new CheeseTopping(new PaneerTopping(new PizzaBase())));
    cout << pz->getCost() << endl;
    cout << pz->getComposition() << endl;
}