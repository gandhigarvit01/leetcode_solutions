class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxi(n);
        vector<int> mini(n);
        for(int i=0; i<n; i++){
            maxi[i] = nums[i];
            if(i>0) maxi[i] = max(maxi[i],maxi[i-1]);
        }
        for(int i=n-1; i>=0; i--){
            mini[i] = nums[i];
            if(i<n-1) mini[i] = min(mini[i],mini[i+1]);
        }
        int ans = INT_MAX;
        for(int i=n-1; i>=0; i--){
            if(maxi[i]-mini[i] <= k) ans = i;
        }
        return ans==INT_MAX?-1:ans;
    }
};