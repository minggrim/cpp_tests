#include <iostream>
template <class T> 
class A {
public:
    static T a;
};

template <class T> 
T A<T>::a = 100;

int main() {
    A<int> a;
    A<int> b;
    std::cout << a.a << " " << &a.a << std::endl;
    std::cout << b.a << " " << &b.a << std::endl;
    std::cout << A<int>::a << " " << &A<int>::a << std::endl;

    A<float> c;
    A<float> d;
    std::cout << c.a << " " << &c.a << std::endl;
    std::cout << d.a << " " << &d.a << std::endl;
    std::cout << A<float>::a << " " << &A<float>::a << std::endl;
}
