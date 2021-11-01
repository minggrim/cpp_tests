#include <type_traits>
#include <vector>
#include <iostream>

bool DP_wordbreak_internal(const std::string &testing, std::vector<std::string> &word_set) {
    size_t n = testing.size();
    if (n == 0) return false;

    std::vector<bool> dp (n + 1, false);

    /*
     * [0][1][2][3][4][5][6][7][8][9][10][11][12][13]
     *     a  p  p  l  e  p  e  n  a  p   p   l   e
     *                          *
     *                    [  -  ]
     *     [  -  -  -  ]
     *
     */

    dp[0] = true;
    for (int i = 1; i < n + 1; i++) {
        for (auto & word : word_set) {
            size_t w = word.size();
            if (i >= w && testing.substr(i - w, w) == word) {
                dp[i] = dp[i] || dp[i-w];  // try in word set, one of them suceed, will be true.
            }
        }
    }

    return dp[n];
}

int main(int argc, const char *argv[]) {
    std::string testing {"applepenapple"};
    std::vector<std::string> word_set {"apple", "pen"};
    std::cout << "Result :" << DP_wordbreak_internal(
        testing,
        word_set
    ) << std::endl;;
}
