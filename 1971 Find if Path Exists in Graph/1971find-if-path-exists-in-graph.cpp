class Solution {
public:
    bool dfs(int source, int destination, vector<vector<int>>& adj, vector<bool>& visited){
        if(source==destination){
            return true;
        }
        visited[source] = true;
        for(int v : adj[source]){
            if(!visited[v]){
                if(dfs(v,destination,adj,visited)){
                    return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(vector<int>& vec : edges){
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n,false);

        bool ans = dfs(source,destination,adj,visited);
        return ans;
    }
};