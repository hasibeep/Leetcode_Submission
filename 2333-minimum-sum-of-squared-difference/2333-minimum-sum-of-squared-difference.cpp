class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;
        vector<int> diff(n);

        long long total = 0;
        int mx = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
            mx = max(mx, diff[i]);
        }

        if (total <= k) return 0;

        int left = 0, right = mx;

        while (left < right) {
            int mid = left + (right - left) / 2;
            long long ops = 0;

            for (int d : diff) {
                ops += max(d - mid, 0);
            }

            if (ops <= k)
                right = mid;
            else
                left = mid + 1;
        }

        int level = left;
        vector<int> reduced(n);
        long long used = 0;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            reduced[i] = min(diff[i], level);
            used += diff[i] - reduced[i];
            ans += 1LL * reduced[i] * reduced[i];
        }

        long long rem = k - used;

        for (int i = 0; i < n && rem > 0; i++) {
            if (reduced[i] == level && reduced[i] > 0) {
                ans -= 1LL * reduced[i] * reduced[i];
                reduced[i]--;
                ans += 1LL * reduced[i] * reduced[i];
                rem--;
            }
        }

        return ans;
    }
};
