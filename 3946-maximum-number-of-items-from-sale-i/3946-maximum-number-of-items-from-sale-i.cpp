class Solution {
public:
    int memo[1001][1501];
    int solve(int n ,vector<int>&copies,vector<vector<int>>& items,int budget,int min_price){
        if(n==0){
            return budget/min_price;
        }
        if(memo[n][budget]!=-1) return memo[n][budget];
        int take=0;
        int skip=0;
        int price=items[n-1][1];

        if(price<=budget){
            take=1+copies[n-1]+solve(n-1,copies,items,budget-price,min_price);
        }

        skip=solve(n-1,copies,items,budget,min_price);

        return memo[n][budget]=max(skip,take);
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        vector<int>copies(n,0);
        int min_price=INT_MAX;

        for(int i=0;i<n;i++){
            min_price=min(min_price,items[i][1]);
            int count=0;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(items[j][0]%items[i][0]==0 ){
                    count++;
                }
                
            }
            copies[i]=count;
        }

        memset(memo,-1,sizeof(memo));
        return solve(n,copies,items,budget,min_price);

    }
};