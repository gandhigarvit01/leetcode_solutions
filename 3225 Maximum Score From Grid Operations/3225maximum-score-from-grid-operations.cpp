class Solution {
public:
    int n;
    long long dp[101][2][101];
    long long solve(int col, vector<vector<int>>& grid, int choice, int row){
        if(col==n) return 0;
        if(dp[col][choice][row]!=-1) return dp[col][choice][row];
        long long white = 0, black = 0;
        long long ans = 0;
        if(choice==0){
            // white
            long long sum = 0;
            for(int i=0; i<row; i++){
                sum += grid[i][col];
            }
            white = sum + solve(col+1, grid, 0, 0);
            if(col+1<n){
                for(int i=row; i<n; i++){
                    sum += grid[i][col];
                    white = max(white, sum + solve(col+1, grid, 1, i+1)); 
                }
            }
            // black
            sum = 0;
            for(int i=0; i<row; i++){
                sum += grid[i][col];
            }
            for(int i=0; i<row; i++){
                sum -= grid[i][col];
                black = max(black, sum + solve(col+1, grid, 0, i+1));
            }
            for(int i=row; i<n; i++){
                black = max(black, solve(col+1, grid, 0, i+1));
            }
        }
        else
        {
            long long sum = 0;
            black = solve(col+1, grid, 0, row);
            if(col+1<n){
                for(int i=row; i<n; i++){
                    sum += grid[i][col];
                    black = max(black, sum + solve(col+1, grid, 1, i+1));
                }
            }
            for(int i=row; i<n; i++){
                black = max(black, solve(col+1, grid, 0, i+1));
            }
        }
        return dp[col][choice][row] = max(white, black);
    }
    long long maximumScore(vector<vector<int>>& grid) {
        n = grid.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, grid, 0, 0);
    }
};