#include <type_traits>
#include <vector>
#include <iostream>
#include <algorithm>
using std::vector;
using std::cout;
using std::endl;

int DP_DelandEarn(const vector<int> & arr) {
    // core idea : if we pick a number, the number-1 and number+1 will be deleted //
    // if we loop in all numbers one by one, we only need to consider number - 1
    int max_n = *std::max_element(arr.begin(), arr.end());

    vector<int> freq (max_n + 1, 0);

    for (auto & p : arr) freq[p] ++;

    if (max_n == 1) return freq[max_n]*1;

    vector<int> dp(max_n + 1, 0);
    dp[1] = freq[1] * 1;
    dp[2] = std::max(dp[1], 2*freq[2]);

    for (int i = 3; i <= max_n; i++) {
        dp[i] = std::max(dp[i-1], dp[i-2] + i*freq[i]);
    }

    return dp[max_n];
}

int main(int argc, const char *argv[]) {
    vector<int> arr {8, 3, 4, 7, 6, 6, 9, 2, 5, 8, 2, 4, 9, 5, 9, 1, 5, 7, 1, 4};
    cout << "Max del and earn : " << DP_DelandEarn(arr) << endl;
}
