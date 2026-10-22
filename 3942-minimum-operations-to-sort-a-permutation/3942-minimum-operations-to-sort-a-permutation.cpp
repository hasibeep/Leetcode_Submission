class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int count1=0;
        int count2=0;
        for(int i=1;i<n;i++){
            if(nums[i]==(nums[i-1]+1)%n){
                count1++;
            };
            if(nums[i-1]==(nums[i]+1)%n) count2++;
        }
        
        if(count1==n-1 && nums[0]==0) return 0;
        if(count1==n-1){
            int left=n-nums[0];
            int right=nums.back()+3;
            return min(left,right);
        }

        if(count2==n-1){
            int left=n-nums.back()+1;
            int right=(nums[0]+1)%n+1;
            return min(left,right);
        }

        return -1;
    }
};