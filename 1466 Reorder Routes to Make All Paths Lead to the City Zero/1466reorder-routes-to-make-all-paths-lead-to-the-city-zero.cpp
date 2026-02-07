class Solution {
public:
    int ans;
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited, set<vector<int>>& st){
        visited[u] = true;
        for(int v : adj[u]){
            if(!visited[v]){
                if(st.find({u,v})!=st.end()){
                    ans++;
                }
                dfs(v,adj,visited,st);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto& vec : connections){
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }
        set<vector<int>> st(connections.begin(),connections.end());
        ans = 0;
        vector<bool> visited(n,false);
        dfs(0,adj,visited,st);
        return ans;
    }
};