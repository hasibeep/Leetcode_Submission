class Solution {
public:
    int M=1e9+7;
    int dp[1001][1001];

    int numberOfSets(int n, int k) {
        for(int i=0;i<n;i++){
            dp[0][i]=1;
        }

        for(int K=1;K<=k;K++){
            vector<int>prevRowsum(n+1,0);
            for(int x=n-1;x>=0;x--){
                prevRowsum[x]=(prevRowsum[x+1]+dp[K-1][x])%M;
            }
            for(int i=n-1;i>=0;i--){
               int take=prevRowsum[i+1];
               
               int skip=dp[K][i+1]%M;

               dp[K][i]=(skip+take)%M;
            }
        }
        return dp[k][0];
    }
};