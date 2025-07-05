class Solution {
public:
    int m;
    int dp[10001];
    int solve(int n){
        if(n<0){
            return 100000;
        }
        if(n==0){
            return dp[n] = 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int k = 100000;
        for(int i=1; i<=m; i++){
            int l = solve(n-(i*i));
            k = min(k,l);
        }
        return dp[n] = 1+k;
    }
    int numSquares(int n) {
        m = sqrt(n);
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};