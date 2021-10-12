#include <type_traits>
#include <vector>
#include <iostream>

// Save sapce version
int DP_climbing_internal(int n, std::integral_constant<bool, true>) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (n == 1) return 1;

    std::vector<int> a(2);
    a[0] = 1;
    a[1] = 1;
    for (int i = 2; i < n; i++) {
        std::swap(a[1], a[0]);
        a[1] = a[0] + a[1];
    }

    return a[1];
}

// No save sapce version
int DP_climbing_internal(int n, std::integral_constant<bool, false>) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (n == 1) return 1;

    std::vector<int> a(n);
    a[0] = 1;
    a[1] = 1;
    for (int i = 2; i < n; i++) {
        a[i] = a[i-1] + a[i-2];
    }

    return a[n-1];
}


int main(int argc, const char *argv[]) {
    int result = DP_climbing_internal(1000, std::integral_constant<bool, true>());
    std::cout << "Result : " << result << std::endl;

    result = DP_climbing_internal(1000, std::integral_constant<bool, false>());
    std::cout << "Result : " << result << std::endl;
}
