class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;

        for(int x : nums) sum += x;

        int to_sub = sum - target;
        if(to_sub%2!=0 || to_sub<0 || (to_sub/2)>sum) return 0;
        int need = to_sub/2;

        vector<vector<int>> dp(n+1, vector<int>(need+1, 0));

        dp[n][need] = 1;
        for(int i=n-1; i>=0; i--){
            for(int total=0; total<=need; total++){
                int skip = dp[i+1][total];
                int take = 0;
                if(total + nums[i] <= need) take = dp[i+1][total+nums[i]];
                dp[i][total] = skip + take;
            }
        }
        return dp[0][0];
    }
};