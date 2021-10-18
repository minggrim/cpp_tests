#include <type_traits>
#include <vector>
#include <iostream>
#include <numeric>

// Save sapce version
int DP_arithmeticslice_internal(std::vector<int> & arr, std::integral_constant<bool, true>) {
    if (arr.size() < 3) return 0;

    std::vector<int> a(arr.size());
    int previous = 0;
    int total = 0;
    for (int i = 2; i < arr.size(); i++) {
        if (arr[i] - arr[i-1] == arr[i-1] - arr[i-2]) {
            previous = previous + 1;
        }
        total += previous;
    }

    return total;
}

// No save sapce version
int DP_arithmeticslice_internal(std::vector<int> & arr, std::integral_constant<bool, false>) {
    if (arr.size() < 3) return 0;

    std::vector<int> a(arr.size());
    a[0] = 0;
    a[1] = 0;
    for (int i = 2; i < arr.size(); i++) {
        // i, i - 1, i -2 create a new arithmetic sequence
        if (arr[i] - arr[i-1] == arr[i-1] - arr[i-2]) {
            a[i] = a[i-1] + 1;
        }
    }

    return std::accumulate(a.begin(), a.end(), 0);
}


int main(int argc, const char *argv[]) {
    std::vector<int> arr;
    for (int i = -100; i < 1000; i++) {
        arr.push_back(i);
    }

    std::cout << "Max robber : " <<  DP_arithmeticslice_internal(arr, std::integral_constant<bool, true>()) << std::endl;
    std::cout << "Max robber : " <<  DP_arithmeticslice_internal(arr, std::integral_constant<bool, false>()) << std::endl;
}
