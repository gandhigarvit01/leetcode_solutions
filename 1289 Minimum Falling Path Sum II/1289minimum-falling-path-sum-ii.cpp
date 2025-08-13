class Solution {
public:
    int n;
    int solve(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(row==n-1){
            return grid[row][col];
        }
        if(dp[row][col]!=-100){
            return dp[row][col];
        }
        int temp = INT_MAX;
        for(int i=0; i<n; i++){
            if(i!=col){
                temp = min(temp,solve(row+1,i,grid,dp));
            }
        }
        return dp[row][col] = grid[row][col] + temp;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, -100));
        for(int i=0; i<n; i++){
            ans = min(ans,solve(0,i,grid,dp));
        }
        return ans;
    }
};