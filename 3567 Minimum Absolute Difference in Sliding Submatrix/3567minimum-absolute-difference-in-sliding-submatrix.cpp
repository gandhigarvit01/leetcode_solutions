class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> vec;
        vector<vector<int>> ans(m-k+1, vector<int>(n-k+1));
        for(int i=0; i<m-k+1; i++){
            for(int j=0; j<n-k+1; j++){
                for(int a=i; a<i+k; a++){
                    for(int b=j; b<j+k; b++){
                        vec.push_back(grid[a][b]);
                    }
                }
                sort(vec.begin(),vec.end());
                int mini = INT_MAX;
                for(int l=1; l<vec.size(); l++){
                    if(vec[l]!=vec[l-1]){
                        mini = min(mini, abs(vec[l]-vec[l-1]));
                    }
                }
                if(mini==INT_MAX) mini = 0;
                ans[i][j] = mini;
                vec.clear();
            }
        }
        return ans;
    }
};