class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        
        
        long long  sum=0;
        for(int i=0;i<n;i++){
           long long a=nums[i];
           if(i<n/2){
            sum-=a*a;
           }
           else {
            sum+=a*a;
           }
        }
        return sum;
    }
};