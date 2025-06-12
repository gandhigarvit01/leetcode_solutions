class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int a = abs(nums[0]-nums[n-1]);
        int k = INT_MIN;
        for(int i=0; i<n-1; i++){
            if(abs(nums[i]-nums[i+1])>k){
                k = abs(nums[i]-nums[i+1]);
            }
        }
        return max(a,k);
    }
};