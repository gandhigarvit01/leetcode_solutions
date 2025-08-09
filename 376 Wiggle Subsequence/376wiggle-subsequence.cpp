class Solution {
public:
    int n;
    int dp[1005][1005][2];
    int solve(int curr, int prev, int order, vector<int>& nums){
        if(curr>=n){
            return 0;
        }
        if(prev!=-1 && dp[curr][prev][order]!=-1){
            return dp[curr][prev][order];
        }
        int take=0,leave=0;
        if(prev==-1){
            take = 1 + solve(curr+1,curr,order,nums);
            leave = solve(curr+1,prev,order,nums);
        }
        else if((order==0 && nums[curr]<nums[prev]) || (order==1 && nums[curr]>nums[prev])){
            take = 1 + solve(curr+1,curr,1-order,nums);
            leave = solve(curr+1,prev,order,nums);
        }
        if(prev==-1) return max(take,leave);
        return dp[curr][prev][order] = max(take,leave);
    }
    int wiggleMaxLength(vector<int>& nums) {
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        int a = solve(0,-1,0,nums);
        int b = solve(0,-1,1,nums);
        return max(a,b);
    }
};