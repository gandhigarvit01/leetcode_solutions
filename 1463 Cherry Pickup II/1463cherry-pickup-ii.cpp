class Solution {
public:
    int m,n;
    int dp[71][71][71];
    int solve(vector<vector<int>>& grid, int i, int j1, int j2){
        if(i>=m || i<0 || j1>=n || j2>=n || j1<0 || j2<0) return 0;
        if(i==m-1){
            if(j1==j2) return grid[i][j1];
            return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int ans = 0;
        ans = max(ans, solve(grid, i+1, j1-1, j2-1));
        ans = max(ans, solve(grid, i+1, j1-1, j2));
        ans = max(ans, solve(grid, i+1, j1-1, j2+1));
        ans = max(ans, solve(grid, i+1, j1, j2-1));
        ans = max(ans, solve(grid, i+1, j1, j2));
        ans = max(ans, solve(grid, i+1, j1, j2+1));
        ans = max(ans, solve(grid, i+1, j1+1, j2-1));
        ans = max(ans, solve(grid, i+1, j1+1, j2));
        ans = max(ans, solve(grid, i+1, j1+1, j2+1));
        if(j1==j2) ans += grid[i][j1];
        else ans += grid[i][j1] + grid[i][j2];
        return dp[i][j1][j2] = ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(grid, 0, 0, n-1);
    }
};