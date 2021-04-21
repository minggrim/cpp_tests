#include <iostream>
#include <memory>

// need at least one virtual function
// otherwise we will 'get source type is not polymorphic' compile error
class A {
public:
    A () {}
    // ~A () {}
    virtual ~A () {}
};

class B : public A {
public:
    B() {}
    ~B() {}
};

class C {
};

int main() {
    std::shared_ptr<A> my_ptr {new B {}};

    auto p = std::dynamic_pointer_cast<B>(my_ptr);
    auto p2 = std::dynamic_pointer_cast<B>(my_ptr);

    std::cout << (void *) p.get() << std::endl;
    return 0;
}
