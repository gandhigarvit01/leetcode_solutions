class Solution {
public:
    long long solve(int u, vector<int>& values, unordered_map<int,vector<int>>& adj, vector<bool>& visited){
        visited[u] = true;
        long long sum = 0;
        for(int v : adj[u]){
            if(!visited[v]){
                sum += solve(v, values, adj, visited);
            }
        }
        if(sum!=0){
            if(sum < values[u]) return sum;
        }
        return values[u];
    }
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        vector<bool> visited(n,false);
        unordered_map<int, vector<int>> adj;
        for(auto vec : edges){
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        long long remove = solve(0,values,adj,visited);
        long long total = 0;
        for(int i=0; i<n; i++){
            total += values[i];
        }
        return total - remove;
    }
};