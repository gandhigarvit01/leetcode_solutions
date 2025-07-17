class Solution {
public:
    int n;
    double dp[102][102];
    double solve(vector<int>& nums, int k, int idx){
        double sum = 0.0;
        if(k==1){
            for(int i=idx; i<n; i++){
                sum += nums[i];
            }
            return dp[k][idx] = sum/(n-idx);
        }
        if(idx==n){
            return 0.0;
        }
        if(dp[k][idx]!=-1){
            return dp[k][idx];
        }
        double result = INT_MIN;
        for(int i=idx; i<n; i++){
            sum += nums[i];
            result = max(result,(sum/(i-idx+1))+solve(nums,k-1,i+1));
        }
        return dp[k][idx] = result;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        n = nums.size();
        for(int i=0; i<102; i++){
            for(int j=0; j<102; j++){
                dp[i][j] = -1;
            }
        }
        return solve(nums,k,0);
    }
};