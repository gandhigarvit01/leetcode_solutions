class Solution {
public:
    int n;
    int dp[10002];

    int solve(int i, vector<int>& nums){
        if(i == n-1) return 0;
        if(dp[i]!=-1){
            return dp[i];
        }
    
        int k = INT_MAX;
        for(int j = i+1; j <= i + nums[i] && j < n; j++){
            k = min(k,solve(j, nums));
        }

        return dp[i] = (k == INT_MAX ? INT_MAX : k + 1);
    }

    int jump(vector<int>& nums) {
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(0, nums);
    }
};
