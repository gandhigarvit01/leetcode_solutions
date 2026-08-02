class Solution {
public:
    int n;
    int dp[501][501];
    int solve(int i, int j, vector<int>& piles){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int first = piles[i] + min(solve(i+2,j,piles),solve(i+1,j-1,piles)); 
        int last = piles[j] + min(solve(i,j-2,piles),solve(i+1,j-1,piles));
        return dp[i][j] = max(first, last);
    }
    bool stoneGame(vector<int>& piles) {
        n = piles.size();
        memset(dp, -1, sizeof(dp));
        int alice = solve(0, n-1, piles);
        int total = 0;
        for(int x : piles) total += x;
        return alice > (total - alice);
    }
};