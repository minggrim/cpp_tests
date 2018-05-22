#include <iostream>
class A {
    public:
    A() {}
    // move constructor : arg const lvalue reference
    A (const A& rhs) {
        std::cout << "copy constructor called" << std::endl;
    }
    // move constructor : arg rvalue reference
    A (A&& rhs) {
        std::cout << "move constructor called" << std::endl;
    }
};

void dummy(A a) {
}

int main() {
    A a;
    dummy(a);
    dummy(std::move(a));
}
