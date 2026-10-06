class Solution {
public:
    long long maxValue(vector<int>& nums) {
        int n=nums.size();
        vector<long long> pre(n+1);
        for(int i=1;i<=nums.size();i++){
            pre[i]=pre[i-1]+(i%2==1?nums[i-1]:-nums[i-1]);
        }
        long long ans=pre[n];
        for(int j=2;j<=nums.size();j++){
             ans=max(ans,pre[n]-2*pre[j]+2*pre[j-2]);
             pre[j]=max(pre[j],pre[j-2]);
        }
        return ans;
    }
};