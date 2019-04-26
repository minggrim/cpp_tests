#include <iostream>
#include <vector>

void print_vec_el(std::vector<std::string> &vec) {
    for ( auto x : vec) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<std::string> v1 = {"a", "b", "c"};
    std::vector<std::string> v2 = {"a", "d", "f"};
    std::cout << "v1 vector elements before move, sz : " << v1.size() << std::endl;
    print_vec_el(v1);
    std::cout << "v2 vector elements before move sz : " << v2.size() << std::endl;
    print_vec_el(v2);
//
    v1.insert(v1.end(), std::make_move_iterator(v2.begin()), 
                                    std::make_move_iterator(v2.end()));
//
    std::cout << "v1 vector elements after move, sz : " << v1.size() << std::endl;
    print_vec_el(v1);
    // v2 has stale elements
    std::cout << "v2 vector elements after move, sz : " << v2.size() << std::endl;
    print_vec_el(v2);

    v2.clear();
    std::cout << "v2 vector elements after clear, sz : " << v2.size() << std::endl;
    print_vec_el(v2);
}
