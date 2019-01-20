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

    int read_p2(int x) const {
        mdata = x;
        // data is declared without mutable keyword, not modifiable in const function
        // data = x;
        return data;
    }

    // --------------------------------------------------------------

    // const version f
    const int& f() const {
        //...
        //...
        return data;
    }

    // non-const version f
    // reuse code of const version
    // const_cast is to remove const of return value
    // static_cast is to add const to *this for invoking const version f()
    int& f() {
        return const_cast<int&>(
            static_cast<const A&>(*this).f()
        );
    }

    // --------------------------------------------------------------

private:
    int data;
    // mutable keyword is to get rid of const keyword
    mutable int mdata;};

int main() {
}
