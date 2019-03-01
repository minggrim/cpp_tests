#include <iostream>
class A {
    public:
    A() {}
    // move constructor : arg const lvalue reference
    A (const A& rhs) {
        std::cout << "A copy constructor called" << std::endl;
    }
    // move constructor : arg rvalue reference
    A (A&& rhs) {
        std::cout << "A move constructor called" << std::endl;
    }
};

class B : public A {
};

class C {
    public:
    C() {}
    // move constructor : arg const lvalue reference
    C (const C& rhs) {
        std::cout << "C copy constructor called" << std::endl;
    }
};

class D : public C {
};

void dummy(A a) {
}

void dummy(B b) {
}

void dummy(C c) {
}

int main() {
    A a;
    B b;
    C c;
    D d;
    std::cout << "===Test Copy===" << std::endl;
    dummy(a);
    std::cout << "===Test Move===" << std::endl;
    dummy(std::move(a));
    std::cout << "===Test Derived Copy===" << std::endl;
    dummy(b);
    std::cout << "===Test Derived Move===" << std::endl;
    dummy(std::move(b));

    std::cout << "===Test No User-Defined Move Ctor===" << std::endl;
    dummy(std::move(c));

    std::cout << "===Test Derived No User-Defined Move Ctor===" << std::endl;
    dummy(std::move(d));
}
