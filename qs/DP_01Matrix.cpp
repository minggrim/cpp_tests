#include <type_traits>
#include <vector>
#include <iostream>
#include <numeric>
#include <climits>
using std::vector;

using Int2DVec_t = vector<vector<int>>;

static std::ostream & operator<< (std::ostream &os, const Int2DVec_t &arr) {
    for (auto & x : arr) {
        for (auto & y : x) {
            std::cout << y << " ";
        }
        os << std::endl;
    }

    return os;
}

Int2DVec_t DP_01matrix_internal(Int2DVec_t & arr) {
    int m = arr.size();
    int n = arr[0].size();

    if (!m || !n) return {};

    Int2DVec_t dp (m, vector<int>(n, INT_MAX));
    
    // first scan left-top to right-bottom
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j]) {
                // compare left
                if (j > 0) {
                    dp[i][j] = std::min(dp[i][j], dp[i][j-1] + 1);
                }
                // compare up
                if (i > 0) {
                    dp[i][j] = std::min(dp[i][j], dp[i-1][j] + 1);
                }
            }
            else {
                dp[i][j] = 0;
            }
        }
    }


    // second scan right-bottom to left-top
    for (int i = m - 1; i >=0; i--) {
        for (int j = n - 1; j >=0; j--) {
            if (arr[i][j]) {
                // compare right
                if (j < n -1) {
                    dp[i][j] = std::min(dp[i][j], dp[i][j+1] + 1);
                }
                // compare down
                if (i < m - 1) {
                    dp[i][j] = std::min(dp[i][j], dp[i+1][j] + 1);
                }
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
    return dp;
}


int main(int argc, const char *argv[]) {
    Int2DVec_t arr {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };
    std::cout << "Min path sum : \n" << arr << "\nResult:\n" <<  DP_01matrix_internal(arr) << std::endl;
}
