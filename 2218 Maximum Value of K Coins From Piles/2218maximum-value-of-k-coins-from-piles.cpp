class Solution {
public:
    int n;
    int dp[1005][2005];
    int solve(int idx, int k, vector<vector<int>>& piles){
        if(k==0){
            return 0;
        }
        if(idx==n){
            return -1;
        }
        if(dp[idx][k]!=-1){
            return dp[idx][k];
        }
        int skip = solve(idx+1,k,piles);
        int take = 0;
        int sum = 0;
        for(int i=0; i<(min((int)piles[idx].size(),k)); i++){
            sum += piles[idx][i];
            int temp = sum + solve(idx+1,k-i-1,piles);
            take = max(take,temp);
        }
        return dp[idx][k] = max(skip,take);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n = piles.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,k,piles);
    }
};