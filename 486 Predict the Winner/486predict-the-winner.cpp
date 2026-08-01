class Solution {
public:
    int n;
    int dp[21][21];
    int solve(int i, int j, vector<int>& nums){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int first = nums[i] + min(solve(i+2,j,nums),solve(i+1,j-1,nums));
        int last = nums[j] + min(solve(i,j-2,nums),solve(i+1,j-1,nums));
        return dp[i][j] = max(first, last);
    }
    bool predictTheWinner(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        int player_1 = solve(0,n-1,nums);
        int sum = 0;
        for(int x : nums) sum += x;
        return player_1 >= (sum - player_1);
    }
};