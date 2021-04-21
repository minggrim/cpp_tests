#include <iostream>
#include <typeinfo>
using namespace std;

class A
{
public:
     void Print() { cout<<"This is class A."<<endl; }
};

class B : public A
{
public:
     void Print() { cout<<"This is class B."<<endl; }
};

class C
{
public:
     virtual void Print() { cout<<"This is class A."<<endl; }
};

class D : public C
{
public:
     void Print() { cout<<"This is class B."<<endl; }
};

int main()
{
     A *pA = new B();
     cout<<typeid(pA).name()<<endl; // class A *
     cout<<typeid(*pA).name()<<endl; // class A

     C *pC = new D();
     cout<<typeid(pC).name()<<endl; // class C *
     cout<<typeid(*pC).name()<<endl; // class C
     return 0;
}
