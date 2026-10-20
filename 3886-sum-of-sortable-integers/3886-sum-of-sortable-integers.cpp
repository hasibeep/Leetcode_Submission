class Solution {
public:
bool KMPsearch(vector<int>& pattern, vector<int>& text) {
    int n = pattern.size();
    int m = text.size();

    vector<int> lps(n, 0);

    for (int i = 1, len = 0; i < n;) {
        if (pattern[i] == pattern[len]) {
            lps[i++] = ++len;
        } else if (len > 0) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }

    int i = 0, j = 0;

    while (i < m) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == n) {
            return true;
        } else if (i < m && pattern[j] != text[i]) {
            if (j > 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return false;
}
    bool possible(vector<int>&v1,vector<int>&v2){
         vector<int>x=v2;
         x.insert(end(x),v2.begin(),v2.end());
         return KMPsearch(v1,x);
    }
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        vector<int>v=nums;
        sort(v.begin(),v.end());

        int result=0;
        for(int k=1;k<=n;k++){
            if(n%k!=0) continue;
            bool valid=true;
            for(int i=0;i<n;i=i+k){
                vector<int>v1(nums.begin()+i,nums.begin()+i+k);
                vector<int>v2(v.begin()+i,v.begin()+i+k);
                if(!possible(v1,v2)){
                    valid=false;
                    break;
                }
                
            }
            if(valid){
                result+=k;
            }
        }
        return result;
    }
};