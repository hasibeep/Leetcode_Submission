class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> first(26, -1);
        vector<int> last(26, -1);
        
        for (int i = 0; i < n; ++i) {
            if (first[s[i] - 'a'] == -1) {
                first[s[i] - 'a'] = i;
            }
            last[s[i] - 'a'] = i;
        }
        
        auto check = [&](int i) -> int {
            int right = last[s[i] - 'a'];
            for (int j = i; j <= right; ++j) {
                if (first[s[j] - 'a'] < i) {
                    return -1;
                }
                right = max(right, last[s[j] - 'a']);
            }
            return right;
        };
        
        vector<string> ans;
        int right = -1;
        
        for (int i = 0; i < n; ++i) {
            if (i == first[s[i] - 'a']) {
                int new_right = check(i);
                
                if (new_right != -1) {
                    if (i > right) {
                        ans.push_back(s.substr(i, new_right - i + 1));
                    } else {
                        ans.back() = s.substr(i, new_right - i + 1);
                    }
                    right = new_right;
                }
            }
        }
        
        return ans;
    }
};