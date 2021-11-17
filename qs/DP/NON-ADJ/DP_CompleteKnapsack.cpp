#include <vector>
#include <iostream>

using std::vector;

int DP_CompleteKnapSack_internal(const std::vector<int> &values, const std::vector<int> & weights, int N, int W) {
    /*
     * dp[i][j] : the max value of i items and total weight <= j
     *
     *           0   1   2   3   4   W
     *         +---+---+---+---+---+---+
     *      0  | 0 | 0 | 0 | 0 | 0 | 0 |
     *         +---+---+---+---+---+---+
     *      1  | 0 |   |   |   |   |   |
     *         +---+---+---+---+---+---+
     *     ... | 0 |   |   |   |   |   |
     *         +---+---+---+---+---+---+
     *      N  | 0 |   |   |   |   |   |
     *         +---+---+---+---+---+---+
     */
    vector<vector<int>> dp (N+1, vector<int>(W+1, 0));
    for (int i = 1; i < N+1; i++) {
        int item_weight = weights[i-1];
        int item_value = values[i-1];
        for (int j = 1; j < W+1; j++) {
            if (j >= item_weight) {
                dp[i][j] = std::max(
                    dp[i-1][j],                            // Not to pick:
                    dp[i][j-item_weight] + item_value      // To pick multiple times
                                                           // 
                                                           // Trivial thought : compare (no pick, pick once, pick twice, ..., all situations)
                                                           //                   dp[i][j] = max(dp[i-1][j], dp[i-1][j-w] + v, dp[i-1][j-2*w] + 2 * v, dp[i-1][j-3*w] + 3 * v, ...) 
                                                           //                                  ^^^^^^^^^^  ^^^^^^^^^^^^^^^^  ^^^^^^^^^^^^^^^^^^^^^^  ^^^^^^^^^^^^^^^^^^^^^^
                                                           //                                   0 pick,       pick once,         pick twice              pick three times
                                                           //
                                                           //                                              ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                                                           //                                                              EXPR X
                                                           // But the time complex is too big in trivial thought.
                                                           //
                                                           // Advanced thought : Does any previous dp already contains EXPR X ???
                                                           //
                                                           // dp[i][(j-w)] = max(dp[i-1][(j-w)], dp[i-1][(j-w)-w] + v, dp[i-1][(j-w)-w*2] + 2*v, ...)
                                                           //
                                                           // => dp[i][(j-w)] + v = max(dp[i-1][(j-w)] + v, dp[i-1][(j-w)-w] + 2*v, dp[i-1][(j-w)-w*2] + 3*v, ...)
                                                           //                       ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                                                           //                                                  !!! This is EXPR X !!!
                                                           //
                                                           // 
                                                           // So we can simple replace EXPR X to dp[i][(j-w)] + v which dp[i][(j-w)] is already known.
                                                           // dp[i][j] = max(dp[i-1][j], dp[i][j-w] + v), Cheers
                                                           // 
                );
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[N][W];
}

int DP_CompleteKnapSack_save_space_internal(const std::vector<int> &values, const std::vector<int> & weights, int N, int W) {
    vector<int> dp(W+1, 0);
    for (int i = 1; i < N+1; i++) {
        int item_weight = weights[i-1];
        int item_value = values[i-1];
        for (int j = 1; j < W+1; j++) {
            if (j >= item_weight) {
                dp[j] = std::max(
                    dp[j],                                 // Not to pick, dp[j] currently record the idx(i, j)
                    dp[j-item_weight] + item_value         // We scan left to right, so j-item_weight of this row is already updated.
                );
            }
        }
    }

    return dp[W];
}

int main(int argc, const char *argv[]) {
    const std::vector<int> values {5, 2, 3, 4, 7};
    const std::vector<int> weights {3, 4, 2, 1, 9};
    std::cout << "Result of " << DP_CompleteKnapSack_internal(values, weights, values.size(), 10) << std::endl;
    std::cout << "Result of " << DP_CompleteKnapSack_save_space_internal(values, weights, values.size(), 10) << std::endl;
}
