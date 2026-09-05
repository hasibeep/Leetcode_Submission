class Solution {
public:
    
    int firstStableIndex(vector<int>& nums, int k) {
         int n=nums.size();
         vector<int>v(n);
         int min_ele=nums[n-1];
         v[n-1]=min_ele;
         for(int i=n-2;i>=0;i--){
            min_ele=min(nums[i],min_ele);
            v[i]=min_ele;
         }
         int max_ele=nums[0];
         for(int i=0;i<n;i++){
            max_ele=max(nums[i],max_ele);
            if(max_ele-v[i]<=k){
               return i;
            }
         }
         return -1;
    }
};