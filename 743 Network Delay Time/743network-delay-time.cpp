class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1, INT_MAX);
        vector<vector<pair<int,int>>> adj(n+1);
        for(vector<int> vec : times){
            adj[vec[0]].push_back({vec[1],vec[2]});
        }
        int src = k;
        dist[src] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,src});
        while(!pq.empty()){
            pair<int,int> p = pq.top();
            pq.pop();
            int d = p.first;
            int u = p.second;

            if(d>dist[u]){
                continue;
            }

            for(pair<int,int> p1 : adj[u]){
                int v = p1.first;
                int cost = p1.second;
                if(dist[v]>dist[u]+cost){
                    dist[v] = dist[u] + cost;
                    pq.push({dist[v],v});
                } 
            }
        }
        int ans = -1;
        for(int i=1; i<n+1; i++){
            if(dist[i]>ans){
                ans = dist[i];
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};