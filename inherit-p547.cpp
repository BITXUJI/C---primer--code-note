#include <iostream>
#include <string>

class Base
{
public:
    void pub_mem(); // public member
protected:
    int prot_mem; // protected member
private:
    char priv_mem; // private member
};

struct Pub_Derv : public Base
{
    void memfcn(Base &b) { b = *this; }
};
struct Priv_Derv : private Base
{
    void memfcn(Base &b) { b = *this; }
};
struct Prot_Derv : protected Base
{
    void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Public : public Pub_Derv
{
    void memfcn(Base &b) { b = *this; }
};
struct Derived_from_Private : public Priv_Derv
{
    //error: cannot cast 'const Derived_from_Private' to its private base class 'const Base'
    // void memfcn(Base &b) { b = *this; }
};
struct Derived_from_Protected : public Prot_Derv
{
    void memfcn(Base &b) { b = *this; }
};

int main()
{
    Pub_Derv d1;
    Base *p = &d1;

    Priv_Derv d2;
    //error: cannot cast 'Priv_Derv' to its private base class 'Base'
    // p = &d2;

    Prot_Derv d3;
    // error: cannot cast 'Prot_Derv' to its protected base class 'Base'
    // p = &d3;

    Derived_from_Public dd1;
    p = &dd1;

    Derived_from_Private dd2;
    // error: cannot cast 'Derived_from_Private' to its private base class 'Base'
    // p = &dd2;

    Derived_from_Protected dd3;
    // error: cannot cast 'Derived_from_Protected' to its protected base class 'Base'
    // p = &dd3;

    return 0;
}