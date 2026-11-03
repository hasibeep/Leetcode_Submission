class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max_ele=INT_MIN;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max_ele){
                max_ele=nums[i];
            }
        }
        for(int i=0;i<nums.size();i++){
            ans+=max_ele-nums[i];
        }
        return ans;
    }
};