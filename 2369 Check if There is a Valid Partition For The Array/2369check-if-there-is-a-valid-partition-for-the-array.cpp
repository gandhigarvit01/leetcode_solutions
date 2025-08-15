class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return false;
        vector<bool> dp(n,false);
        if(nums[1]==nums[0]){
            dp[1] = true;
        }
        if(n==2) return dp[1];
        if((nums[0]==nums[1] && nums[1]==nums[2]) || (nums[0]==nums[1]-1 && nums[1]==nums[2]-1)){
            dp[2] = true;
        }
        for(int i=3; i<n; i++){
            bool p1=false,p2=false,p3=false;
            if(nums[i]==nums[i-1]){
                p1 = dp[i-2];
            }
            if(nums[i]==nums[i-1] && nums[i]==nums[i-2]){
                p2 = dp[i-3];
            }
            if(nums[i]==nums[i-1]+1 && nums[i]==nums[i-2]+2){
                p3 = dp[i-3]; 
            }
            dp[i] = (p1 || p2 || p3);
        }
        return dp[n-1];
    }
};