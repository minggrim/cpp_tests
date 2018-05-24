class A {
    int p;
    // 
public:
    int dummy1 () const {}
    int dummy2 () {}
    void set_p(const int m) { p = m;}
    // compiler can not identify which one caller should call,
    // can not overload
    // void set_p(int m) { p = m;}

    // when parameter is const , this one is called
    void plus_p(const int &m) { p += m; }
    // when parameter is not const , this one is called
    void plus_p(int &m) { p += m; }

    // data member won't be changed
    // all callee should be declared as const
    int read_p() const {
        dummy1();
        // dummy2();     // error, not declared as const
    }
};

int main() {
}
