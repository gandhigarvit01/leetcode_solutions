class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        int i=0, j=0;
        while(i<n){
            if(nums[i]==0){
                j = i;
                while(j+1<n && nums[j+1]==0){
                    j++;
                }
                ans += (1LL*(j-i+1)*(j-i+2))/2;
                i = j+1;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};