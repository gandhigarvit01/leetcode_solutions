class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int mini = INT_MAX;
        int mini2 = INT_MAX;
        for(int i=1; i<n; i++){
            if(nums[i]<mini){
                mini2 = mini;
                mini = nums[i];
            }
            else if(nums[i]<mini2){
                mini2 = nums[i];
            }
        }
        ans += mini + mini2;
        return ans;
    }
};