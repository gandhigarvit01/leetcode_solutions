class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;
    int solve(vector<int>& prices, int i, int buy, int k){
        if(i==n || k==0) return 0;
        if(dp[i][buy][k]!=-1) return dp[i][buy][k];
        int take,not_take;
        if(buy==1){
            take = -prices[i] + solve(prices,i+1,0,k);
            not_take = solve(prices,i+1,1,k);
        }
        else{
            take = prices[i] + solve(prices,i+1,1,k-1);
            not_take = solve(prices,i+1,0,k);
        }
        return dp[i][buy][k] = max(take,not_take);
    }
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        dp.assign(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return solve(prices,0,1,k);
    }
};