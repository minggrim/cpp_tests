#include<iostream>
using std::cout;
using std::endl;

class A {
public:
    A(const std::string &n) : name(n) {
        cout << name << " --- CON" << endl;
    }
    ~A() {
        cout << name << " --- DES" << endl;
    }
    void my_name() {
        cout << name << " --- MYNAME" << endl;
    }
private:
    std::string name;
};

class B {
    public :
        static int func () {
            static A a {"static in member func"};
        }

        static A m;
};

A iamglobal {"global var"};

A B::m {"class static"};

int main() {
    static A x {"static in main"};
    cout << __func__ << endl;
    B::func();
}


/* Result :
global var --- CON
class static --- CON
static in main --- CON
main
static in member func --- CON
static in member func --- DES
static in main --- DES
class static --- DES
global var --- DES
 */
