class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int curr = 0;
        for(int i=0; i<n; i++){
            curr += i*nums[i];
            sum += nums[i];
        }
        int ans = curr;
        int k = n-1;
        for(int i=n-1; i>=0; i--){
            int rem = sum - nums[i];
            curr += rem;
            curr -= nums[i]*k;
            ans = max(ans, curr);
        }
        return ans;
    }
};