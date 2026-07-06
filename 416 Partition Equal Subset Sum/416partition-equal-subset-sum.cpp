class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        if(sum%2!=0) return false;
        int target = sum/2;
        vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));
        dp[n][target] = true;
        for(int i=n-1; i>=0; i--){
            for(int total=0; total<=target; total++){
                bool skip = dp[i+1][total];
                bool take = false;
                if(total + nums[i] <= target) take = dp[i+1][total+nums[i]];
                dp[i][total] = skip || take;
            }
        }
        return dp[0][0];
    }
};