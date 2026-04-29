class Solution {
public:
    vector<pair<pair<int,int>,pair<int,int>>> vec{7};
    vector<vector<bool>> visited;
    int m,n;
    bool solve(int i, int j, vector<vector<int>>& grid){
        if(i==m-1 && j==n-1) return true;
        visited[i][j] = true;
        int idx = grid[i][j];
        int i1 = i + vec[idx].first.first;
        int j1 = j + vec[idx].first.second;
        bool case1 = false, case2 = false;
        if(i1>=0 && i1<m && j1>=0 && j1<n && !visited[i1][j1]){
            int idx2 = grid[i1][j1];
            int i2 = i1 + vec[idx2].first.first;
            int j2 = j1 + vec[idx2].first.second;
            if(i==i2 && j==j2){
                case1 = solve(i1,j1,grid);
            }
            i2 = i1 + vec[idx2].second.first;
            j2 = j1 + vec[idx2].second.second;
            if(i2==i && j2==j){
                case1 = solve(i1,j1,grid);
            }
        }
        i1 = i + vec[idx].second.first;
        j1 = j + vec[idx].second.second;
        if(i1>=0 && i1<m && j1>=0 && j1<n && !visited[i1][j1]){
            int idx2 = grid[i1][j1];
            int i2 = i1 + vec[idx2].first.first;
            int j2 = j1 + vec[idx2].first.second;
            if(i==i2 && j==j2){
                case2 = solve(i1,j1,grid);
            }
            i2 = i1 + vec[idx2].second.first;
            j2 = j1 + vec[idx2].second.second;
            if(i2==i && j2==j){
                case2 = solve(i1,j1,grid);
            }
        }
        return case1 | case2;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        visited.assign(m, vector<bool>(n, false));
        vec[1] = {{0,-1},{0,1}};
        vec[2] = {{-1,0},{1,0}};
        vec[3] = {{0,-1},{1,0}};
        vec[4] = {{1,0},{0,1}};
        vec[5] = {{0,-1},{-1,0}};
        vec[6] = {{-1,0},{0,1}};
        return solve(0,0,grid);
    }
};