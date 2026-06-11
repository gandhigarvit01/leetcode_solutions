class Solution {
public:
    int mod = 1e9+7;
    void dfs(int u, int p, unordered_map<int,vector<int>>& adj, int d, vector<int>& depth){
        depth[u] = d;
        for(int v : adj[u]){
            if(v!=p) dfs(v, u, adj, d+1, depth);
        }
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        unordered_map<int,vector<int>> adj;
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> depth(n+1,0);
        dfs(1, -1, adj, 0, depth);
        int mx_d = INT_MIN;
        for(int i=1; i<=n; i++){
            mx_d = max(mx_d, depth[i]);
        }
        if(mx_d==0) return 0;
        int ans = 1;
        for(int i=1; i<mx_d; i++){
            ans = (ans * 2) % mod;
        }
        return ans;
    }
};