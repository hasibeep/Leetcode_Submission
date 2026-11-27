class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        long long  sum=0;
        for(auto num:nums){
            sum+=num;
        }
        long long  left_sum=0;
        long long right_sum=0;
        for(int i=0;i<n-1;i++){
            left_sum+=nums[i];
            right_sum=sum-left_sum;
            if(left_sum>=right_sum){
                count++;
            }
        }
        return count;
    }
};