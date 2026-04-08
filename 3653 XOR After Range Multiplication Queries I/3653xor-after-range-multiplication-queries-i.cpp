class Solution {
public:
    int mod = 1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries){
        int n = queries.size();
        for(int i=0; i<n; i++){
            int idx = queries[i][0];
            int v = queries[i][3];
            int k = queries[i][2];
            while(idx <= queries[i][1]){
                nums[idx] = (1LL*nums[idx]*v) % mod;
                idx += k;
            }
        }
        int ans = nums[0];
        for(int i=1; i<nums.size(); i++){
            ans = ans ^ nums[i];
        }
        return ans;
    }
};