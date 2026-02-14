class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        vector<long long> dp(n,0);
        dp[0] = nums[0];
        for(int i=1; i<n; i++){
            if(colors[i-1]==colors[i]){
                long long prev = 0;
                if(i-2>=0) prev = dp[i-2];
                dp[i] = max(prev+nums[i],dp[i-1]);
            }
            else{
                long long prev_1 = dp[i-1];
                long long prev_2 = 0;
                if(i-2 >= 0) prev_2 = dp[i-2];
                dp[i] = max(prev_1,prev_2) + nums[i];
            }
        }
        return dp[n-1];
    }
};