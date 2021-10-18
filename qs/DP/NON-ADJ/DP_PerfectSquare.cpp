#include <type_traits>
#include <vector>
#include <iostream>
#include <climits>

int DP_perfectsquare_internal(int n) {
    if (n < 0) return 0;

    /*
     *  dp[i] means perfect square of i
     *  i could be (1^2 + i-1), (2^2 + i-4), (3^2 + i - 9)
     *  so dp[i] = 1 + min(dp[i-1], dp[i-2], dp[i-3], ...)
     *
     *   i  i-1         i-4                 i-9
     *   .   .   .   .   .   .   .   .   .   .   .   .   .
     *   |   |           |                   |
     *   +---+           |                   |
     *   | 1=1^2         |                   |
     *   +---------------+                   |
     *   |       4=2^2                       |
     *   +-----------------------------------+
     *                     9=3^2
     */

    std::vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    // directly use index as number
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j * j <= i; j++) {
            dp[i] = std::min(dp[i], dp[i - j * j] + 1);
        }
    }

    return dp[n];
}


int main(int argc, const char *argv[]) {
    for (int i = 1; i<100; i++) {
        std::cout << "Perfect Square of " << i << " : " <<  DP_perfectsquare_internal(i) << std::endl;
    }
}
