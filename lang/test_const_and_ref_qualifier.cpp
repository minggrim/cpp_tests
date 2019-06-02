#include <iostream>
class A {
public:
    void tell_me() & {
        std::cout << "Addr : " << (void *) this << " I am member function of a Lvalue " << std::endl;
    } // (1)

    void tell_me() && {
        std::cout << "Addr : " << (void *) this << " I am member function of a Rvalue " << std::endl;
    } // (2)

    void tell_me() const & {
        std::cout << "Addr : " << (void *) this << " I am member function of a Lvalue , and I am const object" << std::endl;
    } // (3)
};

int main() {
    // lvalue
    A a {};
    a.tell_me();
    std::move(a).tell_me();
    std::forward<A>(a).tell_me();
    a.tell_me();
    std::cout << std::endl;
    
    // prvalue.
    A().tell_me();
    std::move(A()).tell_me();
    std::forward<A>(A()).tell_me();
    std::cout << std::endl;

    // rvalue reference is a lvalue itself. 
    A && b = A();
    b.tell_me();
    std::move(b).tell_me();
    std::forward<A>(b).tell_me();
    std::cout << std::endl;

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
