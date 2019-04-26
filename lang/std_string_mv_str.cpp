#include <iostream>
int main() {
    std::string a("123");
    std::string b;
    std::cout << "Before string move " << std::endl;
    std::cout << "a:" << a.size() << ":" << a << std::endl;
    std::cout << "b:" << b.size() << ":" << b << std::endl;
    b = std::move(a);
    std::cout << "a:" << a.size() << ":" << a << std::endl;
    std::cout << "b:" << b.size() << ":" << b << std::endl;
}
