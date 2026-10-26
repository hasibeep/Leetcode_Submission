class Solution {
public:
    int count=0;
    int m,n;
    vector<vector<int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
    long long dfs(vector<vector<int>>& grid,int r,int c){
        long long sum=grid[r][c];
        grid[r][c]=0;

        for(vector<int>&dir:directions){
            int i_=r+dir[0];
            int j_=c+dir[1];

            if(i_>=0 && i_<m && j_>=0 && j_<n && grid[i_][j_]>0){
                sum+=dfs(grid,i_,j_);
            }
        }
        return sum;

    }

    int countIslands(vector<vector<int>>& grid, int k) {
         m=grid.size();
         n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0){
                    long long sum=dfs(grid,i,j);
                    if(sum%k==0) count++;
                }
            }
        }
        return count;
    }
};