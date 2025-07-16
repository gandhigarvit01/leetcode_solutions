class Solution {
public:
    int M,N;
    int mod = 1e9+7;
    int dp[51][51][51];

    int solve(int row, int col, int steps){
        if(steps==0){
            return 0;
        }
        else if(steps==1){
            int k = 0;
            if(row==0) k++;
            if(row==M-1) k++;
            if(col==0) k++;
            if(col==N-1) k++;
            return dp[row][col][steps] = k;
        }

        if(dp[row][col][steps] != -1){
            return dp[row][col][steps];
        }

        int up = 0, down = 0, left = 0, right = 0;

        if(row > 0)        up = solve(row-1, col, steps-1);
        if(row < M-1)      down = solve(row+1, col, steps-1);
        if(col > 0)        left = solve(row, col-1, steps-1);
        if(col < N-1)      right = solve(row, col+1, steps-1);

        return dp[row][col][steps] = (((1LL * up + down) % mod + left) % mod + right) % mod;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        M = m;
        N = n;
        int result = 0;  
        memset(dp, -1, sizeof(dp));

        for(int i = 1; i <= maxMove; i++){  
            result = (result + 1LL * solve(startRow, startColumn, i)) % mod;
        }

        return result;
    }
};
