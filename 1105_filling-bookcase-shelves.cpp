#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

class Solution {
public:
    int minHeightShelves(std::vector<std::vector<int>>& books, int shelfWidth) {
        int n = books.size();
        std::vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            int width = 0, height = 0;
            for (int j = i; j > 0; --j) {
                width += books[j-1][0];
                if (width > shelfWidth) break;
                height = std::max(height, books[j-1][1]);
                dp[i] = std::min(dp[i], dp[j-1] + height);
            }
        }

        return dp[n];
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> books = {{1, 1}, {2, 3}, {2, 3}, {1, 4}};
    int shelfWidth = 6;

    int result = solution.minHeightShelves(books, shelfWidth);
    std::cout << "Minimum height of shelves: " << result << std::endl;

    return 0;
}
