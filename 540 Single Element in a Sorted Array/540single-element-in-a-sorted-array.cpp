class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        int mid;
        if(n==1) return nums[0];
        if(n==2) return -1;
        while(l<=r){
            mid=l+(r-l)/2;
            if(mid==0){
                if(nums[mid]!=nums[mid+1]) return nums[0];
            }
            if(mid==n-1){
                if(nums[mid]!=nums[mid-1]) return nums[n-1];
            }
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            else if(mid%2==0){
                if(nums[mid]==nums[mid-1]){
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
            else{
                if(nums[mid]==nums[mid-1]){
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }
        }
        return -1;
    }
};