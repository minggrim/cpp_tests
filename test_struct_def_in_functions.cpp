
#include <iostream>

void func1() {
    struct A {
        int a;
        explicit A() : a(100) {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
        }
    };

    A a;

    std::cout << __func__ << " : " << a.a << std::endl;
}

void func2() {
    struct A {
        int a;
        explicit A() : a(99999) {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
        }
    };

    A a;

    std::cout << __func__ << " : " << a.a << std::endl;
}

int main() {
    func1();
    func2();
}
