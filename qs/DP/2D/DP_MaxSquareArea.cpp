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

int DP_maxsquare_internal(Int2DVec_t & arr) {
    int m = arr.size();
    int n = arr[0].size();

    if (!m || !n) return {};

    int max_len = 0;
    Int2DVec_t dp (m, vector<int>(n, 0));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (i == 0 || j == 0) {
                dp[i][j] = arr[i][j] ? 1 : 0 ;
            }
            else {
                if (arr[i][j]) {
                    dp[i][j] = std::min(dp[i-1][j-1], std::min(dp[i][j-1], dp[i-1][j])) + 1;
                }
                else {
                    dp[i][j] = 0;
                }
            }

            if (dp[i][j] > max_len) max_len = dp[i][j];
        }
    }

    std::cout << dp << std::endl;
    return max_len * max_len;
}


int main(int argc, const char *argv[]) {
    Int2DVec_t arr {
        {1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0}
    };
    std::cout << "Maximal Square : \n" << arr << "\nResult:\n" <<  DP_maxsquare_internal(arr) << std::endl;
}
