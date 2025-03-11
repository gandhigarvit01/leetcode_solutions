class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), l=0, r=0;
        int m = 0, maxi = 0, curr = 0;
        while(r<n){
            if(nums[r]==1){
                maxi = max(maxi,r-l+1);
            }
            else if(nums[r]==0){
                m++;
                if(m<=k){
                    maxi = max(maxi,r-l+1);
                }
                else if(m>k){
                    while(m>k){
                        if(nums[l]==0){
                            m--;
                        }
                        l++;
                    }
                }
            }
            r++;
        }
        return maxi;
    }
};