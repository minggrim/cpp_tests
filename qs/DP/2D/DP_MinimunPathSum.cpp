#include <type_traits>
#include <vector>
#include <iostream>
#include <numeric>
using std::vector;

using Int2DVec_t = vector<vector<int>>;

// Save sapce version
int DP_minpathsum_internal(Int2DVec_t & arr, std::integral_constant<bool, true>) {
    int m = arr.size();
    int n = arr[0].size();

    if (!m || !n) return 0;

    vector<int> dp (n, 0);

    int left = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0) {
                if (j == 0) dp[0] = arr[0][0];
                else dp[j] = dp[j-1] + arr[0][j];
            }
            else if (j == 0) {
                dp[j] = dp[j] + arr[i][j];
            }
            else {
                dp[j] = std::min(
                    dp[j-1] + arr[i][j],
                    dp[j] + arr[i][j]
                );
            }
        }
    }

    return dp[n-1];
}

// No save sapce version
int DP_minpathsum_internal(Int2DVec_t & arr, std::integral_constant<bool, false>) {
    int m = arr.size();
    int n = arr[0].size();

    if (!m || !n) return 0;

    Int2DVec_t dp (m, vector<int>(n, 0));
    
    // init first row
    for (int i = 0; i < n; i++) {
        if (i == 0) dp[0][0] = arr[0][0];
        else dp[0][i] = dp[0][i-1] + arr[0][i];
    }

    for (int i = 0; i < m; i++) {
        if (i == 0){}
        else dp[i][0] = dp[i-1][0] + arr[i][0];
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = std::min(
                dp[i-1][j] + arr[i][j],
                dp[i][j-1] + arr[i][j]
            );
        }
    }

    return dp[m-1][n-1];
}


int main(int argc, const char *argv[]) {
    Int2DVec_t arr {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    std::cout << "Min path sum : " <<  DP_minpathsum_internal(arr, std::integral_constant<bool, true>()) << std::endl;
    std::cout << "Min path sum : " <<  DP_minpathsum_internal(arr, std::integral_constant<bool, false>()) << std::endl;
}
