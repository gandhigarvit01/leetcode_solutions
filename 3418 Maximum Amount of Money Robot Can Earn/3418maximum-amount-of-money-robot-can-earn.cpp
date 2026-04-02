class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        int dp[m][n][3];
        //  filling dp[i][j][0] ------------------------------------------
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0) dp[0][0][0] = coins[0][0];
                else{
                    int up = INT_MIN, left = INT_MIN;
                    if(i>0) up = dp[i-1][j][0];
                    if(j>0) left = dp[i][j-1][0];
                    dp[i][j][0] = max(up,left) + coins[i][j];
                }
            }
        }
        // filling dp[i][j][1] --------------------------------------------
        for(int k=1; k<=2; k++){
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    if(i==0 && j==0){
                        if(coins[i][j]>=0) dp[i][j][k] = coins[i][j];
                        else dp[i][j][k] = 0;
                    }
                    else if(coins[i][j]>=0){
                        int up = INT_MIN, left = INT_MIN;
                        if(i>0) up = dp[i-1][j][k];
                        if(j>0) left = dp[i][j-1][k];
                        dp[i][j][k] = max(up,left) + coins[i][j];
                    }
                    else{
                        int up1 = INT_MIN, left1 = INT_MIN;
                        int up2 = INT_MIN, left2 = INT_MIN;
                        if(i>0){
                            up1 = dp[i-1][j][k];
                            up2 = dp[i-1][j][k-1];
                        }
                        if(j>0){
                            left1 = dp[i][j-1][k];
                            left2 = dp[i][j-1][k-1];
                        }
                        int ans1 = max(up1,left1);
                        int ans2 = max(up2,left2);
                        dp[i][j][k] = max(ans1 + coins[i][j], ans2);
                    }
                }
            }
        }
        return dp[m-1][n-1][2];
    }
};