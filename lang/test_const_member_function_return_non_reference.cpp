#include <iostream>
class R{
public:
    R(int _a, int _b) : a(_a), b(_b) {}
    // return non-const reference imply caller can modify object through this funcion.
    // it violates the semantic of const member function.
    int &get_a() const {return a;}
    const int &get_b() const {return b;}  // ok
private:
    int a;
    int b;
};

int main() {
    R r {1, 3};
    std::cout << r.get_a() << std::endl;
    std::cout << r.get_b() << std::endl;
}
