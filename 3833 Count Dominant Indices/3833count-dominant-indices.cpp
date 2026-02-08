class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n);
        int total = 0;
        for(int i=n-1; i>=0; i--){
            sum[i] = total;
            total += nums[i];
        }
        int ans = 0;
        for(int i=0; i<n-1; i++){
            if(nums[i]*(n-i-1) > sum[i]){
                ans++;
            }
        }
        return ans;
    }
};