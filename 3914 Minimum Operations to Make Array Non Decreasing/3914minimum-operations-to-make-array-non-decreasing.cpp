class Solution {
public:
    long long minOperations(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        vector<int> vec(n,0);
        int maxi = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i] >= maxi){
                maxi = nums[i];
            }
            else{
                int diff = maxi - nums[i];
                vec[i] = diff;
            }
        }
        for(int i=1; i<n; i++){
            int diff = vec[i]-vec[i-1];
            if(diff > 0){
                ans += diff;
            }
        }
        return ans;
    }
};