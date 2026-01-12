class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2){
                    visited[i][j] = true;
                    q.push({i,j});
                }
            }
        }
        int time = 0;
        q.push({-1,-1});
        while(!q.empty()){
            pair<int,int> p = q.front();
            int u = p.first;
            int v = p.second;
            q.pop();
            if(u==-1){
                if(!q.empty()){
                    time++;
                    q.push({-1,-1});
                }
            }
            else{
                if(u-1>=0 && grid[u-1][v]==1 && visited[u-1][v]==false){
                    grid[u-1][v] = 2;
                    visited[u-1][v] = true;
                    q.push({u-1,v});
                }
                if(v-1>=0 && grid[u][v-1]==1 && visited[u][v-1]==false){
                    grid[u][v-1] = 2;
                    visited[u][v-1] = true;
                    q.push({u,v-1});
                }
                if(v+1<n && grid[u][v+1]==1 && visited[u][v+1]==false){
                    grid[u][v+1] = 2;
                    visited[u][v+1] = true;
                    q.push({u,v+1});
                }
                if(u+1<m && grid[u+1][v]==1 && visited[u+1][v]==false){
                    grid[u+1][v] = 2;
                    visited[u+1][v] = true;
                    q.push({u+1,v});
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return time;
    }
};