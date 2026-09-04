class Solution {
public:
    int get_min(vector<int>& nums,int i){
         int min_ele=INT_MAX;
         for(int j=i;j<nums.size();j++){
            min_ele=min(min_ele,nums[j]);
         }
         return min_ele;
    }
    int firstStableIndex(vector<int>& nums, int k) {
        int max_ele=INT_MIN;
        for(int i=0;i<nums.size();i++){
           max_ele=max(max_ele,nums[i]);
           if(max_ele-get_min(nums,i)<=k){
            return i;
           }
        }
        return -1;
    }
};