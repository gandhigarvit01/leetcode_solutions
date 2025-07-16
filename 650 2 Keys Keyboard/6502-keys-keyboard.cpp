class Solution {
public:
    int N;
    int dp[1001][1001];
    int solve(int i, int copy){
        if(i==N){
            return 0;
        }
        if(dp[i][copy]!=-1){
            return dp[i][copy];
        }
        int pasteit = 1 + solve(i+copy,copy);
        int copyit = INT_MAX;
        if(N%(i+copy)==0){
            copyit = 2 + solve(i+copy,i+copy);
        }
        return dp[i][copy] = min(copyit,pasteit);
    }
    int minSteps(int n) {
        N = n;
        if(n==1){
            return 0;
        }
        memset(dp,-1,sizeof(dp));
        return 1 + solve(1,1);
    }
};