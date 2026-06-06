class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int rightsum = 0;
        int leftsum = 0;
        for(int i=0; i<n; i++){
            rightsum += nums[i];
        }
        for(int i=0; i<n; i++){
            rightsum -= nums[i];
            int num = nums[i];
            nums[i] = abs(rightsum-leftsum);
            leftsum += num;
        }
        return nums;
    }
};