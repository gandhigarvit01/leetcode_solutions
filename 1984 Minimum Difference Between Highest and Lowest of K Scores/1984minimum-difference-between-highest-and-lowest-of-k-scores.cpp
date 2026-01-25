class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = k-1;
        int a,b;
        int ans = INT_MAX;
        while(j<n){
            a = nums[i];
            b = nums[j];
            ans = min(ans,b-a);
            i++;
            j++;
        }
        return ans;
    }
};