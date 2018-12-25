#include <iostream>
using std::cout;
using std::endl;
class rvo {
public:
    rvo() {
        cout << __func__ << " default constructor" << endl;
    }
    rvo(int i) {
        cout << __func__ << " constructor " << i << endl;
    }
    ~rvo() {
        cout << __func__ << endl;
    }
    rvo(const rvo&) {
        cout << __func__ << " copy constructor" << endl;
    }
    int i;
};

rvo gen_rvo(int i) {
    rvo r1(1), r2(2);
    if (i == 0) {
        return r1;
    }
    else {
        return r2;
    }
}

int main() {
    rvo main_r = gen_rvo(1);
}

// https://www.ibm.com/developerworks/community/blogs/5894415f-be62-4bc0-81c5-3956e82276f3/entry/RVO_V_S_std_move?lang=en
// Return value optimization, simply RVO, is a compiler optimization technique that allows the compiler to construct the return value of a function at the call site
/* 
 * # g++ -std=c++11 test_rvo.cpp -o test_rvo
 * # ./test_rvo
 *
 *  rvo constructor 1
 *  rvo constructor 2
 *  rvo copy constructor           // if-else elimate part of rvo optimization, compiler can not which object to construct on parent stack frame
 *  ~rvo
 *  ~rvo
 *  ~rvo
 */
