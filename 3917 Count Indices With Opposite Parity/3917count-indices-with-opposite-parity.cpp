class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if((abs(nums[i]-nums[j])%2!=0)) ans[i]++;
            }
        }
        return ans;
    }
};