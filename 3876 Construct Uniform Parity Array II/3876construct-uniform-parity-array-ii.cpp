class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int mini_odd = INT_MAX;
        for(int i=0; i<n; i++){
            if(nums1[i]%2!=0 && nums1[i]<mini_odd){
                mini_odd = nums1[i];
            }
        }
        int odd_np = 0;
        for(int i=0; i<n; i++){
            if(nums1[i]%2==0 && nums1[i]-mini_odd<1){
                odd_np++;
            }
        }
        if(odd_np==0) return true;
        int even_np = 0;
        for(int i=0; i<n; i++){
            if(nums1[i]%2!=0 && nums1[i]-mini_odd<1){
                even_np++;
            }
        }
        if(even_np==0) return true;
        return false;
    }
};