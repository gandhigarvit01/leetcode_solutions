class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_num = ranges::min(nums);
        int count = 0;
        for(int num : nums) {
            count += num-min_num;
        }
        return count;
    }
};