#include <iostream>
#include <string>
template <class T> 
class A {
public:
    T plus(T &a, T&b) {
        return a + b;
    }
    A minus(T &a, T&b);
};

//out-of-template scope definition must be A<T>
template <class T> 
A<T> A<T>::minus(T &a, T&b) {
    return a - b;
}

int main() {
    A<int> a;
}
