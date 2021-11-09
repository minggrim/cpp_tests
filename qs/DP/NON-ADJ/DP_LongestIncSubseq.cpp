#include <type_traits>
#include <vector>
#include <iostream>
#include <set>

int DP_LIS_internal_n2(const std::vector<int> & seq) {
    size_t n = seq.size();
    if (n == 0) return 0;

    int max_len = 0;
    // dp[i] : 以i "為尾" 的最大子序列長度.
    std::vector<int> dp (n, 1);

    /*
     *     n1     n2     n3    n4    n5
     *                               dp[n5] = Max( 1,
     *                                             LIS(n1) + 1, if n5 >= n1 i.e. [...,n1] + n5 create a longer LIS then LIS(n1)
     *                                             LIS(n2) + 1, if n5 >= n2 i.e. [...,n2] + n5 create a longer LIS then LIS(n2)
     *                                             LIS(n3) + 1, if n5 >= n3 i.e. [...,n3] + n5 create a longer LIS then LIS(n3)
     *                                             LIS(n4) + 1, if n5 >= n4 i.e. [...,n4] + n5 create a longer LIS then LIS(n4)
     *                                           )
     */
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (seq[i] >= seq[j]) {
                dp[i] = std::max(dp[j] + 1, dp[i]);
            }
        }
        max_len = std::max(max_len, dp[i]);
    }

    return max_len;
}

int DP_LIS_internal_nlogn_good(const std::vector<int> & seq) {
    size_t n = seq.size();
    if (n == 0) return 0;

    std::vector<int> dp(1);

    dp[0] = seq[0];
    for (int i = 1; i < n; i++) {
        if (dp.back() < seq[i]) {
            dp.push_back(seq[i]);
        }
        else {
            // only worked on sorted vector, binary search
            auto iter = std::lower_bound(dp.begin(), dp.end(), seq[i]);

            // NOTE : dp is not the real LIS, only the count is right
            // dp[0], dp[1], ..., dp[last -1], dp[last]
            // purpose : to change dp[last] with seq[i] if dp[last -1] < seq[i] < dp[last]
            // change dp[0]...dp[last -1] is just a no used step, but not changing the LIS count
            *iter = seq[i];
        }
    }

    // NOTE : dp is not the real LIS, only the count is right
    return dp.size();
}

int DP_LIS_internal_nlogn_bad(const std::vector<int> & seq) {
    size_t n = seq.size();
    if (n == 0) return 0;

    std::set<int> dp;

    dp.insert(seq[0]);
    for (int i = 1; i < n; i++) {
        if (*dp.rbegin() < seq[i]) {
            // insert logn
            dp.insert(seq[i]);
        }
        else {
            //double the logn : BAD
            // lowerbound logn
            dp.erase(dp.lower_bound(seq[i]));
            // insert logn
            dp.insert(seq[i]);
        }
    }

    return dp.size();
}

int main(int argc, const char *argv[]) {
    std::vector<int> seq { 10, 9, 2, 5, 3, 7, 101, 18 };
    std::cout << "Result :" << DP_LIS_internal_n2(seq) << std::endl;;
    std::cout << "Result :" << DP_LIS_internal_nlogn_good(seq) << std::endl;;
    std::cout << "Result :" << DP_LIS_internal_nlogn_bad(seq) << std::endl;;
}
