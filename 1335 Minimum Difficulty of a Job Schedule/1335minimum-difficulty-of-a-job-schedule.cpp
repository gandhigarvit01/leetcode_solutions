class Solution {
public:
    int n;
    int dp[301][11];
    int solve(vector<int>& jobDifficulty, int i, int d){
        int maxi = INT_MIN;
        int k = INT_MAX;
        if(d==1){
            for(int j=i; j<=n-1; j++){
                maxi = max(maxi,jobDifficulty[j]);
            }
            k = min(k, maxi);
            return dp[i][d] = k;
        }
        if(dp[i][d]!=-1){
            return dp[i][d];
        }
        for(int j=i; j<=n-d; j++){
            maxi = max(maxi,jobDifficulty[j]);
            k = min(k,solve(jobDifficulty,j+1,d-1)+maxi);
        }
        return dp[i][d] = k;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        n = jobDifficulty.size();
        if(d>n){
            return -1;
        }
        memset(dp, -1, sizeof(dp));
        return solve(jobDifficulty,0,d);
    }
};