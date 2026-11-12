class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int x=1;
        int y=1;
        int ans=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                x++;
                y=1;
            }
            else if(nums[i]<nums[i-1]){
                y++;
                x=1;
            }
            else{
                x=1;
                y=1;
            }
            ans=max(ans,max(x,y));
        }
        return ans;
    }
};