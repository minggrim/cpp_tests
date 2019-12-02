#include <functional>
#include <iostream>
int sum(int a, int b) {
    return a + b;
}

int sum2(int &a, int b) {
    return a + b;
}

int sum3(int *a, int b) {
    return *a + b;
}

int main() {
    int x = 10;
    auto bind_copy1 = std::bind(sum, x, std::placeholders::_1);
    auto bind_ref1 = std::bind(sum2, x, std::placeholders::_1);
    auto bind_ptr1 = std::bind(sum3, &x, std::placeholders::_1);
    
    x = 20;
    auto bind_copy2 = std::bind(sum, x, std::placeholders::_1);
    auto bind_ref2 = std::bind(sum2, x, std::placeholders::_1);
    auto bind_ptr2 = std::bind(sum3, &x, std::placeholders::_1);

    x = 30;

    std::cout << "bind_copy1 result : " << bind_copy1(1) << std::endl;
    std::cout << "bind_copy2 result : " << bind_copy2(1) << std::endl;

    // https://stackoverflow.com/questions/26187192/how-to-bind-function-to-an-object-by-reference
    // https://en.cppreference.com/w/cpp/utility/functional/bind
    // The arguments to bind are copied or moved, and are never passed by reference unless wrapped in std::ref or std::cref.
    std::cout << "bind_ref1 result : " << bind_ref1(1) << std::endl;
    std::cout << "bind_ref2 result : " << bind_ref2(1) << std::endl;

    std::cout << "bind_ptr1 result : " << bind_ptr1(1) << std::endl;
    std::cout << "bind_ptr2 result : " << bind_ptr2(1) << std::endl;
}
