class Solution {
public:
    int bs(vector<int>& nums, int l, int r, int target){
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target){
                r = mid-1;
            }
            else l = mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        int peak;
        if(nums[n-1] > nums[0]){
            return bs(nums, 0, n-1, target);
        }
        // finding peak
        while(l<=r){
            int mid = l + (r-l)/2;
            if(mid<n-1 && nums[mid]>nums[mid+1]){
                peak = mid;
                break;
            }
            else if(nums[mid] < nums[0]){
                r = mid-1;
            }
            else l = mid+1;
        }
        if(target >= nums[0]) return bs(nums, 0, peak, target);
        return bs(nums, peak+1, n-1, target);
    }
};