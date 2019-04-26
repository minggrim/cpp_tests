#include <iostream>
class nonpod {
    public:
    nonpod(int a) : data(a) {
        std::cout << __func__ << std::endl;
    }
    int data;
};

class pod {
    public:
    int data;
};

const int rodata = 10;
const nonpod rodata2 {20};
const pod rodata3 {30};
const static pod rodata4 {40};

int main() {
    const static pod rodata5 {50};

    std::cout << __func__ << std::endl;
    std::cout << &rodata << std::endl;
    int &b = const_cast<int&>(rodata);
    std::cout << &b << std::endl;
    // b = 5; // segmentation fault

    std::cout << &rodata2 << std::endl;
    nonpod &c = const_cast<nonpod&>(rodata2);
    std::cout << &rodata2 << std::endl;
    c.data = 3;

    std::cout << &rodata3 << std::endl;
    pod &d = const_cast<pod&>(rodata3);
    std::cout << &rodata3 << std::endl;
    // d.data = 3; // segmentation fault

    std::cout << &rodata4 << std::endl;
    pod &e = const_cast<pod&>(rodata3);
    std::cout << &rodata4 << std::endl;
    // e.data = 3; // segmentation fault

    std::cout << &rodata5 << std::endl;
    pod &f = const_cast<pod&>(rodata3);
    std::cout << &rodata5 << std::endl;
    // f.data = 3; // segmentation fault
}

/*
0000000000000b98 r rodata
0000000000201138 b rodata2
0000000000000b9c r rodata3
0000000000000ba0 r rodata4
0000000000000ba4 r main::rodata5
 */
