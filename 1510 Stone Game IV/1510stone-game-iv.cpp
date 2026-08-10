class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<vector<int>> dp(2, vector<int>(n+1));
        dp[1][0] = true;
        dp[0][0] = false;
        
        for(int stones=1; stones<=n; stones++){
            for(int pl=0; pl<=1; pl++){
                if(pl==0){
                    bool ans = false;
                    for(int i=1; i*i<=stones; i++){
                        if(dp[1][stones-(i*i)]){
                            ans = true;
                            break;
                        }
                    }
                    dp[pl][stones] = ans;
                }
                else{
                    bool ans = true;
                    for(int i=1; i*i<=stones; i++){
                        if(!dp[0][stones-(i*i)]){
                            ans = false;
                            break;
                        }
                    }
                    dp[pl][stones] = ans;
                }
            }
        }
        return dp[0][n];
    }
};