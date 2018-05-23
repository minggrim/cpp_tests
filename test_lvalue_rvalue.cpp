#include <string>
// referenced from https://wwww.youtube.com/watch?v=UTUdhjzws5g&feature=youtu.be
// lvalue : An object that occupies some "identifiable" location in "memory"
// rvalue : Any object that is not a lvalue
int global = 20;
int return_rvalue() {
    return global;
}
int &return_lvalue() {
    return global;
}
int main() {
    int a = 1;
    // (a++) = 3;     // error, a++ return a rvalue
    // (a + 1) = 3;   // error, a + 1 expression return a rvalue
    (++a) = 4;

    // int &b = 3;    // error, lvalue reference can not be assigned with a rvalue
    const int &b = 3;

    std::string c = "12345";
    const std::string d = "12345";
    // lvalue is nothing about modifiable
    &c;
    &d;
    // &std::string("12345");   // error, can not take address of ralue
    
    // 
    std::string &&e = std::string("12345");

    // return_rvalue() = 3;    // error, this function return rvalue (temporary value)
    return_lvalue() = 3;
}
