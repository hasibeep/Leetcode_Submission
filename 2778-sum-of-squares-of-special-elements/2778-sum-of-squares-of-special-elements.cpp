class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(n%(i+1)==0){
                cnt+=nums[i]*nums[i];
            }
        }
        return cnt;
    }
};