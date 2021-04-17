#include <iostream>
using std::cout;
using std::endl;

class Base {
public:
    void method1() {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    void method1(int a) {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    virtual void method2() {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    virtual void method2(int a) {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

class Derived : public Base {
public:
    void method1() {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    void method2() override {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

int main() {
    Derived d {};
    d.method1();
    d.method2();

    // name hided in Derived scope, won't lookup into Base class, won't lookup into Base class
//  d.method1(1);
//  d.method2(2);
/*  Compile time error
	test_name_hiding.cpp: In function ‘int main()’:
	test_name_hiding.cpp:35:16: error: no matching function for call to ‘Derived::method1(int)’
	d.method1(1);
			^
	test_name_hiding.cpp:23:10: note: candidate: void Derived::method1()
	void method1() {
	  ^~~~~~~
	test_name_hiding.cpp:23:10: note:   candidate expects 0 arguments, 1 provided
	test_name_hiding.cpp:36:16: error: no matching function for call to ‘Derived::method2(int)’
	d.method2(2);
			^
	test_name_hiding.cpp:26:10: note: candidate: virtual void Derived::method2()
	void method2() override {
	  ^~~~~~~
	test_name_hiding.cpp:26:10: note:   candidate expects 0 arguments, 1 provided
*/


    Base *base_ptr = & d;
    base_ptr->method1();
    base_ptr->method2();
    base_ptr->method1();
    base_ptr->method2();
}
