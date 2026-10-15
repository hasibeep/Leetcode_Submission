class Solution {
public:
    int sumCounts(vector<int>& nums) {
        unordered_set<int>st;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            st.clear();
            for(int j=i;j<nums.size();j++){
               st.insert(nums[j]);
               int x=st.size();
               ans+=x*x;
            }
        }
        return ans;
    }
};