class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<long long, 4>> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }

        sort(a.begin(), a.end(), [](auto &x, auto &y) {
            if (x[1] != y[1]) return x[1] < y[1];
            return x[3] < y[3];
        });

        vector<long long> end(n);
        for (int i = 0; i < n; i++) end[i] = a[i][1];

        vector<int> prv(n);
        for (int i = 0; i < n; i++) {
            prv[i] = lower_bound(end.begin(), end.begin() + i, a[i][0]) - end.begin();
        }

        vector<vector<long long>> dp(n + 1, vector<long long>(5, 0));
        vector<vector<vector<int>>> take(n + 1, vector<vector<int>>(5));

        for (int i = 1; i <= n; i++) {
            int j = i - 1;

            for (int k = 1; k <= 4; k++) {
                dp[i][k] = dp[i - 1][k];
                take[i][k] = take[i - 1][k];

                long long val = dp[prv[j]][k - 1] + a[j][2];
                vector<int> cur = take[prv[j]][k - 1];
                cur.push_back(a[j][3]);

                sort(cur.begin(), cur.end());

                if (val > dp[i][k] || (val == dp[i][k] && cur < take[i][k])) {
                    dp[i][k] = val;
                    take[i][k] = cur;
                }
            }
        }

        return take[n][4];
    }
};
