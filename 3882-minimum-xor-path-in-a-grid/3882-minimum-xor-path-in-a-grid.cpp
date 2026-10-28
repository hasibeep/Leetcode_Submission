
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<bitset<1024>> dp(n);

        dp[0].set(grid[0][0]);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    continue;

                bitset<1024> curr;

                // From above
                if (i > 0) {
                    curr |= dp[j];
                }

                // From left
                if (j > 0) {
                    curr |= dp[j - 1];
                }

                bitset<1024> next;

                for (int x = 0; x < 1024; x++) {
                    if (curr[x]) {
                        next.set(x ^ grid[i][j]);
                    }
                }

                dp[j] = next;
            }
        }

        for (int x = 0; x < 1024; x++) {
            if (dp[n - 1][x]) {
                return x;
            }
        }

        return -1;
    }
};
