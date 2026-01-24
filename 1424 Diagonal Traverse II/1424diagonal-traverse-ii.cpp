class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int m = nums.size();
        vector<pair<int,int>> vec;
        for(int i=0; i<m; i++){
            int n = nums[i].size();
            for(int j=0; j<n; j++){
                vec.push_back({i+j,j});
            }
        }
        //sort acc. to sum , if sum same then acc. to j;
        sort(vec.begin(),vec.end());
        int N = vec.size();
        vector<int> ans;
        for(int i=0; i<N; i++){
            ans.push_back(nums[vec[i].first-vec[i].second][vec[i].second]);
        }
        return ans;
    }
};