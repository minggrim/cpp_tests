#include <iostream>

// empty class, a char is inserted into object.
class ebase {
};

class ederived : private ebase {
};

// non-independent object. EBO(Empty Base Optimization) happened
class nderived : private ebase {
    int a;
};

int main() {
    ebase eb {};
    ederived ed {};
    nderived nd {};
    std::cout << "eb size : " << sizeof(eb) << std::endl;
    std::cout << "ed size : " << sizeof(ed) << std::endl;
    std::cout << "nd size : " << sizeof(nd) << std::endl;   // a char no longer exists
}
