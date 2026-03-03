class Solution {
public:
    int ans = 0;
    int n;
    vector<vector<vector<int>>> dp;
    int solve(vector<int>& prices, int i, int transaction, int buy){
        if(i>=n || transaction==2) return 0;
        if(dp[i][transaction][buy]!=-1) return dp[i][transaction][buy];
        if(buy==1){
            int take = solve(prices,i+1,transaction,0) - prices[i];
            int not_take = solve(prices,i+1,transaction,1);
            return dp[i][transaction][buy] = max(take,not_take);
        }
        else{
            int take = prices[i] + solve(prices,i+1,transaction+1,1);
            int not_take = solve(prices,i+1,transaction,0);
            return dp[i][transaction][buy] = max(take,not_take);
        }
        return 0;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.assign(n+1, vector<vector<int>>(3, vector<int>(2, -1)));
        return solve(prices,0,0,1);
    }
};