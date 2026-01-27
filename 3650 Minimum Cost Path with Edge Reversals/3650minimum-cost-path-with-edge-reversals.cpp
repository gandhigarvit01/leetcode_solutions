class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& vec : edges){
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,2*w});
        }
        vector<int> dist(n,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0,0});

        while(!pq.empty()){
            pair<int,int> p = pq.top();
            pq.pop();
            int node = p.second;
            int weight = p.first;

            if(weight>dist[node]){
                continue;
            }

            for(auto& v : adj[node]){
                int destination = v.first;
                int cost = v.second;
                if(dist[destination] > weight + cost){
                    dist[destination] = weight + cost;
                    pq.push({dist[destination],destination});
                }
            }
        }
        if(dist[n-1]==INT_MAX){
            return -1;
        }
        return dist[n-1];
    }
};