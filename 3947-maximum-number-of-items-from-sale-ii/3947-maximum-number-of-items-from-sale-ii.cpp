class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> freq(n + 1, 0);
        long long min_price = LLONG_MAX;

        for (const auto& it : items) {
            freq[it[0]]++;
            min_price = min(min_price, (long long)it[1]);
        }

        vector<int> mult(n + 1, 0);
        for (int f = 1; f <= n; f++) {
            if (freq[f] == 0) continue;
            for (int m = f; m <= n; m += f) {
                mult[f] += freq[m];
            }
        }

        sort(items.begin(), items.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        long long ans = 0;
        long long rem = budget;

        for (const auto& it : items) {
            int f = it[0];
            long long p = it[1];
            if (p >= 2 * min_price) break;

            long long copies = mult[f] - 1;
            long long buy = min(copies, rem / p);
            ans += 2 * buy;
            rem -= buy * p;
        }

        ans += rem / min_price;
        return (int)ans;
    }
};