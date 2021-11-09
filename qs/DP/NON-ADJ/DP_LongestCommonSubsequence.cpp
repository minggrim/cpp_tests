#define LN 1143
#include <vector>
#include <iostream>

int DP_LCS(const std::string & str1, const std::string & str2) {
    /*
     *     {}   a   c   d   e
     *    +---+---+---+---+---+
     * {} | 0 | 0 | 0 | 0 | 0 |         lcs[i][j] : lcs of str1.substr(0, i) , str2.substr(0, j)
     *    +---+---+---+---+---+
     * a  | 0 |   |   |   |   |         if str1.at(i-1) == str2.at(j-1) : lcs[i][j] has +1 longer lcs then lcs[i-1][j-1]
     *    +---+---+---+---+---+         else : did not increase lcs, inherit the max of lcs[i-1][j], lcs[i][j-1]
     * c  | 0 |   |   |   |   |
     *    +---+---+---+---+---+
     * e  | 0 |   |   |   |   |
     *    +---+---+---+---+---+
     */
    size_t m = str1.size();
    size_t n = str2.size();
    std::vector<std::vector<int>> lcs (m + 1, std::vector<int>(n + 1, 0));
    for (int i = 1; i < m + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (str1[i-1] == str2[j-1]) {
                lcs[i][j] = lcs[i-1][j-1] + 1;
            }
            else {
                lcs[i][j] = std::max(lcs[i-1][j], lcs[i][j-1]);
            }
        }
    }
    return lcs[m][n];
}

int main(int argc, const char *argv[]) {
    const std::string str1 {"abcde"};
    const std::string str2 {"ace"};
    std::cout << "LCS of " << str1 << " and " << str2 << ":" << DP_LCS(str1, str2) << std::endl;
}
