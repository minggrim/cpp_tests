#include <iostream>
#include <string>
template <class T> 
class A {
public:
    T minus(T &a, T&b) {
        return a - b;
    }
    T plus(T &a, T&b) {
        return a + b;
    }
};

int main() {
    A<std::string> a;
    std::string a_str = "a_str";
    std::string b_str = "b_str";
    std::cout << a.plus(a_str, b_str) << std::endl;
    // enable below code will cause complie error because std::string not define - operator
    // c++ class template instantiation only instantiate the member which is called
    // i.e. not whole class instantiate 
    // std::cout << a.minus(a_str, b_str) << std::endl;
}
