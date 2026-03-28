class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int ans = INT_MAX;
        int n = nums.size();
        int i = 0;
        while(i<n){
            if(nums[i]!=1) i++;
            else{
                int j = 0;
                while(j<n){
                    if(nums[j]!=2) j++;
                    else{
                        ans = min(ans,abs(i-j));
                        j++;
                    }
                }
                i++;
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};