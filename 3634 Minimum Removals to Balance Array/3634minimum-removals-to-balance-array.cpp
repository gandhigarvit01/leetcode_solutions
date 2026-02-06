class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i = 0, j = 0;
        int ans = 1;
        int curr = 1;
        while(j<n){
            if(1LL*nums[i]*k >= nums[j]){
                curr = j-i+1;
                ans = max(ans,curr);
                j++;
            }
            else{
                i++;
            }
        }
        return n-ans;
    }
};