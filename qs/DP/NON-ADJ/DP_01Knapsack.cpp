#define LN 1143
#include <vector>
#include <iostream>

using std::vector;

int DP_01KnapSack(const std::vector<int> &values, const std::vector<int> & weights, int N, int W) {
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
                    dp[i-1][j-item_weight] + item_value    // To pick:
                );
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[N][W];
}

int main(int argc, const char *argv[]) {
    const std::vector<int> values {5, 2, 3, 4, 7};
    const std::vector<int> weights {3, 4, 2, 1, 9};
    std::cout << "Result of " << DP_01KnapSack(values, weights, values.size(), 10) << std::endl;
}
