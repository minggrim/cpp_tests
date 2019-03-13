#include <iostream>

using namespace std;

static void print_str(const std::string &msg, const std::string &str) {
    cout << msg  
         << " cstr addr : " << (void *) str.c_str()
         << " size : " << str.length()
         << " contenct : " << str
         << " capacity : " << str.capacity()
         << endl;
}

int main() {
    cout << "Testing with c++ standard " << __cplusplus << endl;
    std::string a;
    print_str("After str define : ", a);
    a.reserve(8012);
    print_str("After str reserve : ", a);
    a.append("/abc");
    print_str("After str append : ", a);
    a.erase(0);
    print_str("After str erase : ", a);
    a = a + "/def";
    print_str("After str assignment : ", a);
}
