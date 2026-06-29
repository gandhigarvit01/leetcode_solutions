class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        for(int mask=0; mask<(1<<n); mask++){
            vector<int> vec;
            for(int i=n-1; i>=0; i--){
                if((mask>>i)&1){
                    vec.push_back(nums[i]);
                }
            }
            ans.push_back(vec);
        }
        return ans;
    }
};