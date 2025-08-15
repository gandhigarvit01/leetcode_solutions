class Solution {
public:
    long long dp[502][502];
    int mod = 1e9+7;
    int solve(int idx, int n, int steps){
        if(steps==0 && idx==0){
            return 1;
        }
        if(steps<0){
            return 0;
        }
        if(dp[idx][steps]!=-1){
            return dp[idx][steps];
        }
        int p1=0,p2=0,p3=0;
        p1 = solve(idx,n,steps-1);
        if(idx>0){
            p2 = solve(idx-1,n,steps-1);
        }
        if(idx<n-1){
            p3 = solve(idx+1,n,steps-1);
        }
        return dp[idx][steps] = ((p1+p2)%mod+p3)%mod;
    }
    int numWays(int steps, int arrLen) {
        int n = arrLen;
        memset(dp,-1,sizeof(dp));
        return solve(0,n,steps)%mod;
    }
};