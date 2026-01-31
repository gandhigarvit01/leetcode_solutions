class Solution {
public:
    int solve(vector<int>& nums, int mid){
        int operations = 0;
        for(int i=0; i<nums.size(); i++){
            operations += (nums[i]/mid);
            if(nums[i]%mid!=0){
                operations++;
            }
        }
        return operations;
    }
    int minimumK(vector<int>& nums) {
        int n = nums.size();
        int l = 1;
        int r = 0;
        for(int i=0; i<n; i++){
            r = max(r,nums[i]);
        }
        r = max(r,n);
        while(l<=r){
            int mid = l + (r-l)/2;
            int ans = solve(nums,mid);
            if(ans <= 1LL*mid*mid){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};