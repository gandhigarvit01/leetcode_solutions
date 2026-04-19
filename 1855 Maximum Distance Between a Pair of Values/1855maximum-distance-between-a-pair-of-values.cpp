class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int n = nums1.size();
        int m = nums2.size();
        int l=n-1, r=m-1;
        while(l>=0){
            while(r>l && nums2[r]<nums1[l]){
                r--;
            }
            ans = max(ans, r-l);
            l--;
        }
        return ans;
    }
};