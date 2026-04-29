class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> vec;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                vec.push_back(grid[i][j]);
            }
        }
        sort(vec.begin(),vec.end());
        int op = 0;
        int mid = vec[(m*n)/2];
        for(int i=0; i<m*n; i++){
            int diff = abs(vec[i]-mid);
            if(diff % x == 0) op += diff/x;
            else return -1;
        }
        return op;
    }
};