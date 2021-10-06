namespace types_trait_p {
    template <class T, class U>
    class is_same {
        public:
        enum { same = 0 };
    };

    template<class T>
    class is_same <T, T> {
        public:
        enum { same = 1 };
    };
};


/*
#include <iostream>
#include <vector>
class A {};
class B : public A {};
int main(int argc, const char **argv) {
    std::cout << "int is same with double : " << types_trait_p::is_same<int, double>::same << std::endl;
    std::cout << "int is same with int : " << types_trait_p::is_same<int, int>::same << std::endl;
    std::cout << "const char * is same with char * const : " << types_trait_p::is_same<const char *, char const *>::same << std::endl;
    std::cout << "class A is same with class B : " << types_trait_p::is_same<A, A>::same << std::endl;
    std::cout << "const class A is same with class A : " << types_trait_p::is_same<const A, A>::same << std::endl;
}
*/
