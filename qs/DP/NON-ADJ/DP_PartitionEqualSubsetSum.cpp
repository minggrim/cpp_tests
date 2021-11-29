#define LN 1143
#include <vector>
#include <iostream>

using std::vector;

bool DP_PESS_internal(const std::vector<int> &nums) {
    /*
     * dp[i][j] : !!!whether we can sum to j using the first i numbers!!!
     * dp[i][0] is boundary condition used by i+1 raw.
     *
     *           0   1   2   3  ...  W(11)
     *         +---+---+---+---+---+---+
     *      0  | 1 | 0 | 0 | 0 | 0 | 0 |
     *         +---+---+---+---+---+---+
     *      1  | 1 | D | D | D | D | D |
     *         +---+---+---+---+---+---+
     *      5  | 1 | 0 | 0 | 0 | D | D |
     *         +---+---+---+---+---+---+
     *      11 | 1 | 0 | 0 | 0 | 0 | D |
     *         +---+---+---+---+---+---+
     *      5  | 1 | 0 | 0 | 0 | D | D |
     *         +---+---+---+---+---+---+
     */
    int sum = 0;
    for (auto & e : nums) sum += e;
    if (sum % 2 == 1) return false;

    int target = sum / 2;

    vector<vector<bool>> dp (nums.size() + 1, vector<bool>(target+1, false));
    for (int i = 0; i < nums.size() + 1; i++) dp[i][0] = true;

    // goes through every number
    for (int i = 1; i < nums.size() + 1; i++) {
        // j goes through from num to target.
        for (int j = 1; j < target + 1; j++) {
            if (j < nums[i-1]) {
                // j is smaller nums[i-1], we can not pick. inherit up element.
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }
    }
    
    return dp[nums.size()][target];
}

int DP_PESS_SaveSpace_internal(const std::vector<int> &nums) {
    int sum = 0;
    for (auto & e : nums) sum += e;
    if (sum % 2 == 1) return false;

    int target = sum / 2;

    vector<bool> dp (target+1, false);
    dp[0] = true;

    // goes through every number
    for (int i = 1; i < nums.size() + 1; i++) {
        // j goes through from num to target.
        for (int j = target; j >= nums[i-1]; j--) {
            dp[j] = dp[j] || dp[j-nums[i-1]];
        }
    }

    return dp[target];
}

int main(int argc, const char *argv[]) {
    const std::vector<int> nums {1, 5, 10, 6};
    std::cout << "Result of " << DP_PESS_internal(nums) << std::endl;
    std::cout << "Result of " << DP_PESS_SaveSpace_internal(nums) << std::endl;
}
