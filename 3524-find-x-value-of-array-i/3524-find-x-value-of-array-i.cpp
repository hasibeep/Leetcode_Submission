class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> res(k, 0);
        vector<long long> dp(k, 0);
        
        for (int x : nums) {
            vector<long long> next_dp(k, 0);
            int val = x % k;
            
            for (int i = 0; i < k; ++i) {
                if (dp[i] > 0) {
                    next_dp[(i * val) % k] += dp[i];
                }
            }
            next_dp[val]++;
            
            for (int i = 0; i < k; ++i) {
                dp[i] = next_dp[i];
                res[i] += dp[i];
            }
        }
        
        return res;
    }
};