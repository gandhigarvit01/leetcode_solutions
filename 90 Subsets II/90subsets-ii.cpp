class Solution {
public:
    int n;
    vector<vector<int>> ans;
    void solve(vector<int>& nums, vector<int>& vec, int i, int n){
        ans.push_back(vec);
        if(i==n){
            return;
        }
        for(int idx=i; idx<n; idx++){
            if(idx>i && nums[idx]==nums[idx-1]) continue;
            vec.push_back(nums[idx]);
            solve(nums, vec, idx+1, n);
            vec.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> vec;
        solve(nums,vec,0,n);
        return ans;
    }
};