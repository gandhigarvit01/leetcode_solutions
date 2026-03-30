class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int l=0, r=n-1;
        int ans = 0;
        int mod = 1e9+7;
        vector<int> power(n);
        power[0] = 1;
        for(int i=1; i<n; i++){
            power[i] = (power[i-1] * 2) % mod;
        }
        while(l<=r){
            if(nums[l]+nums[r]<=target){
                ans = ((ans % mod) + (power[r-l] % mod)) % mod;
                l++; 
            }
            else r--;
        }
        return ans;
    }
};