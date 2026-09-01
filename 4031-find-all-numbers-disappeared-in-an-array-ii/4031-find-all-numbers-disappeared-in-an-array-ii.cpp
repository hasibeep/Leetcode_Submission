class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        
        vector<vector<int>>ans;
        int w=lower-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<lower){
                continue;
            }
            if(nums[i]>upper){
                break;
            }
            if(nums[i]>w+1){
                ans.push_back({w+1,nums[i]-1});
            }
            w=nums[i];
        }
        if(w<upper){
            ans.push_back({w+1,upper});
        }
        return ans;
        
    }
};