class Solution {
public:
    int m,n;
    void bfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited){
        visited[i][j] = true;
        queue<pair<int,int>> q;
        q.push({i,j});

        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            int u = p.first;
            int v = p.second;
            if(u-1>=0 && u-1<m && grid[u-1][v]=='1' && visited[u-1][v]==false){
                visited[u-1][v] = true;
                q.push({u-1,v});
            }
            if(v-1>=0 && v-1<n && grid[u][v-1]=='1' && visited[u][v-1]==false){
                visited[u][v-1] = true;
                q.push({u,v-1});
            }
            if(v+1>=0 && v+1<n && grid[u][v+1]=='1' && visited[u][v+1]==false){
                visited[u][v+1] = true;
                q.push({u,v+1});
            }
            if(u+1>=0 && u+1<m && grid[u+1][v]=='1' && visited[u+1][v]==false){
                visited[u+1][v] = true;
                q.push({u+1,v});
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int islands = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1' && visited[i][j]==false){
                    islands++;
                    bfs(grid,i,j,visited);
                }
            }
        }
        return islands;
    }
};