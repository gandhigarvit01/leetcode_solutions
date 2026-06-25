class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int ans = INT_MAX;
        unordered_map<int, vector<pair<int,int>>> mpp;
        for(auto& vec : flights){
            int u = vec[0];
            int v = vec[1];
            int wt = vec[2];
            mpp[u].push_back({v,wt});
        }
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        queue<pair<int, pair<int,int>>> q;
        q.push({src,{0,-1}});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int u = p.first;
            int wt = p.second.first;
            int stops = p.second.second;
            if(u==dst){
                dist[dst] = min(dist[dst], wt);
            }
            else{
                if(stops >= k) continue;
                for(auto& vec : mpp[u]){
                    int v = vec.first;
                    int cost = vec.second;
                    if(cost + wt < dist[v]){
                        dist[v] = cost + wt;
                        q.push({v,{cost+wt,stops+1}});
                    }
                }
            }
        }
        return dist[dst]==INT_MAX ? -1 : dist[dst];
    }
};