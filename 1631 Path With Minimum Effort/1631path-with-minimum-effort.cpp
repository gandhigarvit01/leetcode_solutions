class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> effort(m, vector<int>(n, INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        int dx[4] = {0,-1,0,1};
        int dy[4] = {-1,0,1,0};
        pq.push({0,{0,0}});
        effort[0][0] = 0;
        while(!pq.empty()){
            int cost = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            if(effort[x][y]<cost){
                continue;
            }
            for(int i=0; i<4; i++){
                int u = x+dx[i];
                int v = y+dy[i];
                if(u>=0 && u<m && v>=0 && v<n){
                    int w = max(cost,abs(heights[u][v]-heights[x][y]));
                    if(w<effort[u][v]){
                        effort[u][v] = w;
                        pq.push({w,{u,v}});
                    }
                }
            }
        }
        return effort[m-1][n-1];
    }
};