class Solution {
public:
    bool sd(vector<int>& nums, int n, int h, int m){
        int c=0;
        for(int i=0; i<n; i++){
            if(nums[i]%m==0){
                c += nums[i]/m;
            }
            else{
                c += nums[i]/m + 1;
            }
        }
        if(c>h) return false;
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int maxi = 0;
        for(int i=0; i<n; i++){
            if(nums[i]>maxi){
                maxi = nums[i];
            }
        }
        int l=1, r=maxi, mid=0, ans=0;
        while(l<=r){
            mid = l + (r-l)/2;
            if(sd(nums,n,threshold,mid)){
                r=mid-1;
                ans = mid;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};