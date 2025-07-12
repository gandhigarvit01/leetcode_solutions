class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int result = nums[k];
        int mini = nums[k];
        int l=k,r=k;
        while(l>0 && r<n-1){
            if(nums[l-1]>nums[r+1]){
                l--;
                mini = min(mini,nums[l]);
                result = max(result,mini*(r-l+1));
            }
            else{
                r++;
                mini = min(mini,nums[r]);
                result = max(result,mini*(r-l+1));
            }
        }
        if(l==0){
            while(r<n-1){
                r++;
                mini = min(mini,nums[r]);
                result = max(result,mini*(r-l+1));
            }
        }
        else if(r==n-1){
            while(l>0){
                l--;
                mini = min(mini,nums[l]);
                result = max(result,mini*(r-l+1));
            }
        }
        return result;
    }
};