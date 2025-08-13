class Solution {
public:
    int temp;
    int dp[10005];
    int solve(int idx, vector<int>& vec){
        if(idx>temp){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        if(vec[idx]==0){
            return dp[idx] = solve(idx+1,vec);
        }
        else{
        int skip = 0, take = 0;
        skip = solve(idx+1,vec);
        take = idx*vec[idx] + solve(idx+2,vec);
        return dp[idx] = max(skip,take);
        }
        return 0;
    }
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        temp = nums[n-1];
        vector<int> vec(temp+1,0);
        for(int i=0; i<n; i++){
            vec[nums[i]]++;
        }
        memset(dp,-1,sizeof(dp));
        return solve(0,vec);
    }
};