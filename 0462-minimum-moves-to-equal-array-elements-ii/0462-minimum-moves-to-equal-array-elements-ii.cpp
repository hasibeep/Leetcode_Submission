class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        nth_element(begin(nums),begin(nums)+n/2,end(nums));
        int mid=nums[n/2];
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=abs(nums[i]-mid);
        }
        return ans;
    }
};