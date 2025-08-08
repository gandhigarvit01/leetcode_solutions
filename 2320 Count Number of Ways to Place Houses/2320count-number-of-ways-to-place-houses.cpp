class Solution {
public:
    int mod = 1e9+7;
    int dp[10005][2];
    int solve(int idx, int prev, int n){
        if(idx==n+1){
            return 1;
        }
        if(dp[idx][prev]!=-1){
            return dp[idx][prev];
        }
        int take=0,leave=0;
        if(prev==0){
            take = solve(idx+1,1,n);
        }
        leave = solve(idx+1,0,n);
        return dp[idx][prev] = (take+leave)%mod;
    }
    int countHousePlacements(int n) {
        memset(dp,-1,sizeof(dp));
        int k = solve(1,0,n)%mod;
        return (int)((1ll*k*k)%mod);
    }
};