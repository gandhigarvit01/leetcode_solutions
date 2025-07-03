class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
        vector<int> prev(n,-1);
        int lastidx = 0;
        int maxl = 1;

        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0){
                    if(dp[i]<dp[j]+1){
                        dp[i] = dp[j]+1;
                        prev[i] = j;
                    }
                    if(dp[i]>maxl){
                        maxl = dp[i];
                        lastidx = i;
                    }
                }
            }
        }
        vector<int> result;
        while(lastidx != -1){
            result.push_back(nums[lastidx]);
            lastidx = prev[lastidx];
        }
        return result;
    }
};