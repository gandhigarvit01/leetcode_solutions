class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int l=0, r=0;
        int ans = 0;
        while(r<n){
            if(nums[r]-nums[l]<=k){
                r++;
            }
            else{
                ans++;
                l = r;
            }
        }
        return ans+1;
    }
};