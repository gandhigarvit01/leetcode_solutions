class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        if(n==2){
            if(nums[1]>nums[0]) return 1;
            return 0;
        }
        int l= 0;
        int r= n-1;
        int mid=0;
        while(l<=r){
            mid=l+(r-l)/2;
            if(mid==0){
                if(nums[mid]>nums[mid+1]) return mid;
            }
            if(mid==n-1){
                if(nums[mid]>nums[mid-1]) return n-1;
            }
            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){
                return mid;
            }
            else if(nums[mid]>nums[mid+1]){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return mid;
    }
};