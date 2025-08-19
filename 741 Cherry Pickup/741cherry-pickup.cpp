class Solution {
public:
    int isreached = 0;
    int solve(int i1, int j1, int i2, int j2, vector<vector<int>>& grid, int n, vector<vector<vector<int>>>& dp){
        if(i1>=n || i2>=n || j1>=n || j2>=n){
            return -1000;
        }
        if(grid[i1][j1]==-1 || grid[i2][j2]==-1){
            return -1000;
        }
        if(i1==n-1 && j1==n-1){
            isreached = 1;
            return grid[n-1][n-1];
        }
        if(dp[i1][j1][i2]!=-10000){
            return dp[i1][j1][i2];
        }
        int maxi = -1000;
        maxi = max(maxi,max(solve(i1+1,j1,i2,j2+1,grid,n,dp),solve(i1+1,j1,i2+1,j2,grid,n,dp)));
        maxi = max(maxi,max(solve(i1,j1+1,i2,j2+1,grid,n,dp),solve(i1,j1+1,i2+1,j2,grid,n,dp)));
        if(i1==i2 && j1==j2){
            maxi += grid[i1][j1];
        }
        else{
            maxi += grid[i1][j1] + grid[i2][j2];
        }
        return dp[i1][j1][i2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(n+1, -10000)));
        int ans = solve(0,0,0,0,grid,n,dp);
        return isreached==0?0:ans;
    }
};