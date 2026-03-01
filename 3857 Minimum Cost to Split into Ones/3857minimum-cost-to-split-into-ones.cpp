class Solution {
public:
    int minCost(int n) {
        if(n==1) return 0;
        vector<int> dp(n+1, INT_MAX);
        dp[1] = 0;
        for(int i=2; i<n+1; i++){
            int l = 1;
            int r = i-1;
            dp[i] = (l * r) + dp[l] + dp[r];
        }
        return dp[n];
    }
};