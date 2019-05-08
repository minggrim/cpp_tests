#include<iostream>
#include<thread>
#include<list>
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

    static int func () {
        /* After c++11, this is MT-safe*/
        static A a {"static in member func"};
        return 0;
    }

    int func2() {
        static A a {"static in member func2"};
    }

    static A m;
private:
    std::string name;
};

A iamglobal {"global var"};

A A::m {"class static"};

static void exiter() {
    cout << __func__ << endl;
}

int main() {
    std::atexit(exiter);
    static A x {"static in main"};
    cout << __func__ << endl;
    std::list<std::thread*> thread_list;
    for(int idx=0; idx<200; idx++){
        auto *t = new std::thread([](void){
            A::func();
        });
        thread_list.push_back(t);
    }
    for(auto *t: thread_list){
        t->join();
        delete t;
    }
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
