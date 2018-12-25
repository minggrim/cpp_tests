#include <iostream>
using std::cout;
using std::endl;
class rvo {
public:
    rvo() {
        cout << __func__ << " constructor" << endl;
    }
    ~rvo() {
        cout << __func__ << endl;
    }
    rvo(const rvo&) {
        cout << __func__ << " copy constructor" << endl;
    }
};

rvo gen_rvo() {
    rvo r;
    return r;
}

int main() {
    rvo main_r = gen_rvo();
}

/* 
 * # g++ -std=c++11 test_rvo.cpp -o test_rvo
 * # ./test_rvo
 * rvo constructor               // 
 * ~rvo
 *
 * # g++ -std=c++11 test_rvo.cpp -fno-elide-constructors -o test_rvo
 * # ./test_rvo
 * rvo constructor               // rvo r in gen_rvo()
 * rvo copy constructor          // return_value = r
 * ~rvo                          // r desctruction
 * rvo copy constructor          // main_r = return_value
 * ~rvo                          // return_value destruction
 * ~rvo                          // main_r destruction
 *
 */
