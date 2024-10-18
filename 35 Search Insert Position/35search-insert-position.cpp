class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        int mid=l+(r-l)/2;

        while(l<r){
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                r=mid-1;
                mid=l+(r-l)/2;
            }
            else{
                l=mid+1;
                mid=l+(r-l)/2;
            }
        }
       if(nums[l]>=target){
        return l;
       }
       else{
        return l+1;
       }

       return -1;
    }
};