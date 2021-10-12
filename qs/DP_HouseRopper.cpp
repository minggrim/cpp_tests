#include <type_traits>
#include <vector>
#include <iostream>

// Save sapce version
int DP_houserobber_internal(std::vector<int> & house_list, std::integral_constant<bool, true>) {
    if (house_list.size() == 0) return 0;
    if (house_list.size() == 1) return house_list[0];

    std::vector<int> a(2);
    a[0] = 0;
    a[1] = house_list[0];
    for (int i = 2; i < house_list.size() + 1; i++) {
        std::swap(a[1], a[0]);
        a[1] = std::max(a[0], a[1] + house_list[i-1]);
    }

    return a[1];
}

// No save sapce version
int DP_houserobber_internal(std::vector<int> & house_list, std::integral_constant<bool, false>) {
    if (house_list.size() == 0) return 0;
    if (house_list.size() == 1) return house_list[0];

    std::vector<int> a(house_list.size() + 1);
    a[0] = 0;
    a[1] = house_list[0];
    for (int i = 2; i < house_list.size() + 1; i++) {
        a[i] = std::max(a[i-1], a[i-2] + house_list[i-1]);
    }

    return a[house_list.size()];
}


int main(int argc, const char *argv[]) {
    std::vector<int> house_list;
    for (int i = -100; i < 1000; i++) {
        house_list.push_back(i);
    }

    std::cout << "Max robber : " <<  DP_houserobber_internal(house_list, std::integral_constant<bool, true>()) << std::endl;
    std::cout << "Max robber : " <<  DP_houserobber_internal(house_list, std::integral_constant<bool, false>()) << std::endl;
}
