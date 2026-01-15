class Solution {
public:
    int ans,n;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size();
        ans = -1;
        if(grid[0][0]==1){
            return -1;
        }
        if(n==1 && grid[0][0]==0){
            return 1;
        }
        vector<vector<int>> dist(n, vector<int>(n,-1));

        queue<pair<int,int>> q;
        dist[0][0] = 1;
        q.push({0,0});

        int dx[8] = {-1,-1,-1,0,1,1,1,0};
        int dy[8] = {-1,0,1,1,1,0,-1,-1};

        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();

            int u = p.first;
            int v = p.second;

            for(int k=0; k<8; k++){
                if(u+dx[k]>=0 && u+dx[k]<n && v+dy[k]>=0 && v+dy[k]<n){
                    if(dist[u+dx[k]][v+dy[k]]==-1 && grid[u+dx[k]][v+dy[k]]==0){
                        if(u+dx[k]==n-1 && v+dy[k]==n-1){
                            ans = dist[u][v] + 1;
                            return ans;
                        }
                        else{
                            dist[u+dx[k]][v+dy[k]] = dist[u][v] + 1;
                            q.push({u+dx[k],v+dy[k]});
                        }
                    }
                }
            }
        }
        return ans;
    }
};