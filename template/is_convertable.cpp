namespace types_trait_p {
    template <class T, class U>
    class is_convertable {
        using Small = char;
        class Big {char dummy[2];};
        static Small Test(U);                   // if T is convertable to U, Test(U) will be used.
        static Big Test(...);                   // otherwise Test(...) sink hole is choosen.
        static T MakeT();
        public:
        enum { exist = sizeof(Test(MakeT())) == sizeof(Small) };
    };
};


/*
#include <iostream>
#include <vector>
class A {};
class B : public A {};
int main(int argc, const char **argv) {
    std::cout << "int is covertable to double : " << types_trait_p::is_convertable<int, double>::exist << std::endl;
    std::cout << "double is covertable to int : " << types_trait_p::is_convertable<double, int>::exist << std::endl;
    std::cout << "std::vector<int> is covertable to int : " << types_trait_p::is_convertable<std::vector<int>, int>::exist << std::endl;
    std::cout << "char* is covertable to char : " << types_trait_p::is_convertable<char, char*>::exist << std::endl;
    std::cout << "class A covertable to class B : " << types_trait_p::is_convertable<A, B>::exist << std::endl;
    std::cout << "class B covertable to class A : " << types_trait_p::is_convertable<B, A>::exist << std::endl;
    std::cout << "class A& covertable to class B& : " << types_trait_p::is_convertable<A&, B&>::exist << std::endl;
    std::cout << "class B& covertable to class A& : " << types_trait_p::is_convertable<B&, A&>::exist << std::endl;
}
*/
