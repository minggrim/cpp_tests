#include <string>
class A {
    // we already define a constructor, compile don't generate default constructor for us
    // in c++ 11, we can A() = default; to tell compile we want default constructor
public:
    A(std::string a) {}
};

class B : A {
public:
    B(const std::string &b) {}
};

// this program is not compilable
// A have no default constructor
int main() {
    B b(std::string("hello world"));
}
