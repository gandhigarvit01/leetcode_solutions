class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int k = -1;
        int n = nums.size();
        if(n==1) return -1;
        int i=0, j=1;
        while(j<n){
            if(nums[i]>=nums[j]){
                i=j;
                j++;
            }
            else{
                k = max(k,nums[j]-nums[i]);
                j++;
            }
        }
        return k;
    }
};