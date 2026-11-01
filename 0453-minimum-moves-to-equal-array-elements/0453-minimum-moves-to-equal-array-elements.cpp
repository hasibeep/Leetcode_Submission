class Solution {
public:
    int minMoves(vector<int>& nums) {
        int count=0;
        int min_ele=INT_MAX;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]<min_ele){
                min_ele=nums[i];
            }
        }
        for(int i=0;i<nums.size();i++){
            count+=nums[i]-min_ele;
        }
        return count;
    }
};