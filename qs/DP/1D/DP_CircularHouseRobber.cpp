#include <type_traits>
#include <vector>
#include <iostream>

// Save sapce version
int DP_basic_houserobber(const std::vector<int> & house_list) {
    int dp[2] {0, 0};
    for (auto &p : house_list) {
        dp[0] = std::max(dp[0] + p, dp[1]);
        std::swap(dp[0], dp[1]);
    }
    return dp[1];
}

int DP_circular_houserobber(const std::vector<int> & house_list) {
    if (house_list.size() == 0) return 0;
    if (house_list.size() == 1) return house_list[0];

    return std::max(
        DP_basic_houserobber(std::vector<int>(house_list.begin() + 1, house_list.end())),
        DP_basic_houserobber(std::vector<int>(house_list.begin(), house_list.end() - 1))
    );
}

int main(int argc, const char *argv[]) {
    std::vector<int> house_list;
    for (int i = -100; i < 1000; i++) {
        house_list.push_back(i);
    }

    std::cout << "Max circular robber : " << DP_circular_houserobber(house_list) << std::endl;
}
