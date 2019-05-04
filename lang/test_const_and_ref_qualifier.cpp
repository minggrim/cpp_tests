#include <iostream>
class A {
public:
    void tell_me() & {
        std::cout << " I am member function of a lvalue " << std::endl;
    } // (1)

    void tell_me() && {
        std::cout << " I am member function of a rvalue " << std::endl;
    } // (2)

    void tell_me() const & {
        std::cout << " I am member function of a lvalue , and I am const object" << std::endl;
    } // (3)
};

int main() {
    // lvalue
    A a {};
    a.tell_me();

    // rvalue.
    A().tell_me();

    // rvalue reference is a lvalue itself. 
    A && b = A();
    b.tell_me();

    /*
     * Think about a scenario :
     * There is a rvalue-ref-qualified member function that moves the member data.
     * __IF__ rvalue reference is a rvalue itself, this definitely not safe.
     * rvalue reference give a rvalue alias name (identifier)
     * caller may manipulate this object through rvalue refernce after calling this member function
     * , and not aware the member data has been moved.
     */

    const A & c = A();
    // Without (3) can't compile : passing ‘const A’ as ‘this’ argument discards qualifiers [-fpermissive]
    // Because c is const A & type.
    c.tell_me();
}
