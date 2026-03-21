class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int l = x, r = x+k-1;
        while(l<r){
            for(int j=y; j<y+k; j++){
                int temp = grid[l][j];
                grid[l][j] = grid[r][j];
                grid[r][j] = temp;
            }
            l++,r--;
        }
        return grid;
    }
};