class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        deque<pair<int,int>> dq;
        vector<vector<int>> dist(m, vector<int>(n, 10000));
        dist[0][0] = 0;
        dq.push_front({0,0});

        while(!dq.empty()){
            pair<int,int> p = dq.front();
            dq.pop_front();

            int u = p.first;
            int v = p.second;

            int dx[4] = {0,0,1,-1};
            int dy[4] = {1,-1,0,0};

            for(int k=0; k<4; k++){
                int nu = u + dx[k];
                int nv = v + dy[k];
                if(nu>=0 && nu<m && nv>=0 && nv<n){
                    int cost = 0;
                    if(grid[u][v]!=k+1){
                        cost = 1;
                    }
                    if(dist[nu][nv] > dist[u][v] + cost){
                        dist[nu][nv] = dist[u][v] + cost;
                        if(cost==0){
                            dq.push_front({nu,nv});
                        }
                        else{
                            dq.push_back({nu,nv});
                        }
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};