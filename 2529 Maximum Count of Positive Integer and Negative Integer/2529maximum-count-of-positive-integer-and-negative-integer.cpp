class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int a=0, b=0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]>0) a++;
            else if(nums[i]<0) b++;
        }
        return max(a,b);
    }
};