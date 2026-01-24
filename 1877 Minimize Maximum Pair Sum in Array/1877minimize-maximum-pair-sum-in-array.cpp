class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int l=0, r=n-1;
        int sum = 0;
        while(l<r){
            sum = max(sum,nums[l]+nums[r]);
            l++;
            r--;
        }
        return sum;
    }
};