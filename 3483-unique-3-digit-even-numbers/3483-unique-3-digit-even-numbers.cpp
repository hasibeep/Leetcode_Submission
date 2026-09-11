class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int ans = 0;

        for (int num = 100; num <= 998; num += 2) {
            int x = num;

            int d1 = x / 100;
            int d2 = (x / 10) % 10;
            int d3 = x % 10;

            vector<int> cnt(10, 0);
            for (int d : digits)
                cnt[d]++;

            if (cnt[d1] > 0) {
                cnt[d1]--;

                if (cnt[d2] > 0) {
                    cnt[d2]--;

                    if (cnt[d3] > 0)
                        ans++;
                }
            }
        }

        return ans;
    }
};
