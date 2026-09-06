class Solution {
public:
    int  ways(vector<int>& dp,int n){
        
        if(n==1) return 1;
        if(n==2) return 2;
        if(dp[n]!=-1) return dp[n];
        dp[n]=ways(dp,n-1)+ways(dp,n-2);
        return dp[n] ;
       
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return ways(dp,n);
    }
};