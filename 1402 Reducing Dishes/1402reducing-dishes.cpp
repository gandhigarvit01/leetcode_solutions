class Solution {
public:
    int n;
    int solve(vector<int>& satisfaction, int idx, int time, vector<vector<int>>& dp){
        if(idx>=n){
            return 0;
        }
        if(dp[idx][time]!=-600000){
            return dp[idx][time];
        }
        int taken = satisfaction[idx]*time + solve(satisfaction,idx+1,time+1,dp);
        int reject = solve(satisfaction, idx+1, time,dp);

        return dp[idx][time] = max(taken,reject);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        n = satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<int>> dp(501, vector<int>(501, -600000));
        return solve(satisfaction,0,1,dp);
    }
};