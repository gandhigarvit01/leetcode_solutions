class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int num = nums[0], i = 0;
        while (i < n) {
            if (num == nums[i]) {
                // num present
                num++;
                i++;
            } else {
                // num absent
                ans.push_back(num);
                num++;
            }
        }
        return ans;
    }
};