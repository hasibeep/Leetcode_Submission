
class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        if ((m + n - 1) % 2 != 0) return false;
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;
        
        vector<vector<vector<bool>>> vis(m, vector<vector<bool>>(n, vector<bool>(205, false)));
        
        return dfs(0, 0, 0, grid, vis);
    }
    
private:
    bool dfs(int r, int c, int bal, const vector<vector<char>>& grid, vector<vector<vector<bool>>>& vis) {
        bal += (grid[r][c] == '(' ? 1 : -1);
        
        int m = grid.size();
        int n = grid[0].size();
        
        if (bal < 0 || bal > (m - 1 - r) + (n - 1 - c)) return false;
        
        if (r == m - 1 && c == n - 1) {
            return bal == 0;
        }
        
        if (vis[r][c][bal]) return false;
        vis[r][c][bal] = true;
        
        if (r + 1 < m && dfs(r + 1, c, bal, grid, vis)) return true;
        if (c + 1 < n && dfs(r, c + 1, bal, grid, vis)) return true;
        
        return false;
    }
};