class Solution {
public:
    int dir_x[4] = {1,0,-1,0};
    int dir_y[4] = {0,-1,0,1};
    int m,n;
    bool iscycle(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j, int x, int y){
        visited[i][j] = true;
        for(int k=0; k<4; k++){
            int n_i = i + dir_x[k];
            int n_j = j + dir_y[k];
            if(n_i>=0 && n_i<m && n_j>=0 && n_j<n && grid[n_i][n_j]==grid[i][j]){
                if(visited[n_i][n_j]){
                    if(n_i!=x || n_j!=y) return true;
                }
                else{
                    if(iscycle(grid, visited, n_i, n_j, i, j)) return true;
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j]){
                    if(iscycle(grid, visited, i, j, -1, -1)) return true;
                }
            }
        }
        return false;
    }
};