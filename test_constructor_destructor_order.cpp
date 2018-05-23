#include <iostream>
class base {
public:
    base() { std::cout << __func__ << std::endl;}
    ~base() { std::cout << __func__ << std::endl;}
};

class membera {
public:
    membera() { std::cout << __func__ << std::endl;}
    ~membera() { std::cout << __func__ << std::endl;}
};

class memberb {
public:
    memberb() { std::cout << __func__ << std::endl;}
    ~memberb() { std::cout << __func__ << std::endl;}
};

class memberc {
public:
    memberc() { std::cout << __func__ << std::endl;}
    ~memberc() { std::cout << __func__ << std::endl;}
};

class derived : base{
public:
    memberc c;
public:
    derived() { std::cout << __func__ << std::endl;}
    ~derived() { std::cout << __func__ << std::endl;}
private:
    membera a;
    memberb b;
};

int main() {
    derived a;
}
