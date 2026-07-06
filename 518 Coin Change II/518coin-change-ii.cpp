class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned long long>> dp(n+1, vector<unsigned long long>(amount+1, 0));
        for(int i=0; i<=n; i++){
            dp[i][amount] = 1;
        }
        for(int i=n-1; i>=0; i--){
            for(int total=amount; total>=0; total--){
                unsigned long long skip = dp[i+1][total];
                unsigned long long take = 0;
                if(total + coins[i] <= amount) take = dp[i][total+coins[i]];
                dp[i][total] = skip + take;
            }
        }
        return dp[0][0];
    }
};