class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        for(int i=0; i<n; i++){
            int val = nums[i];
            int sum = 0;
            while(val > 0){
                int rem = val % 10;
                sum += rem;
                val = val/10;
            }
            ans = min(ans, sum);
        }
        return ans;
    }
};