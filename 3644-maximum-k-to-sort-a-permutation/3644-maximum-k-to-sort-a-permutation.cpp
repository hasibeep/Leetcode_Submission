class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        vector<int>v;
        v=nums;
        sort(begin(v),end(v));
        int n=nums.size();
        int k=-1;
        if(is_sorted(nums.begin(),nums.end())) return 0;
        for(int i=0;i<n;i++){

            if(nums[i]!=v[i]){
               k=k&nums[i];
            }
              
        }
        return k;
    }
};