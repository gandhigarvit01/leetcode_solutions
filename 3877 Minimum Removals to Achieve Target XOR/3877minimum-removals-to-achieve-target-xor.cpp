class Solution {
public:
    int n;
    int ans = INT_MIN;
    unordered_map<long long, int> dp;
    void solve(int i, vector<int>& nums, int target, int currxor, int num){
        if(i==n){
            if(currxor==target){
                ans = max(num,ans);
            }
            return;
        }
        long long key = ((long long)i << 32) | currxor;
        if(dp.count(key) && dp[key] >= num) return;
        dp[key] = num;
        
        solve(i+1,nums,target,currxor,num);
        solve(i+1,nums,target,currxor^nums[i],num+1);
    }
    int minRemovals(vector<int>& nums, int target) {
        n = nums.size();
        solve(0,nums,target,0,0);
        if(ans==INT_MIN) return -1;
        return n-ans;
    }
};