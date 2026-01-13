class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited){
        visited[u] = true;

        for(int v : adj[u]){
            if(!visited[v]){
                dfs(v,adj,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i!=j && isConnected[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        vector<bool> visited(n,false);
        int ans = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                ans++;
                dfs(i,adj,visited);
            }
        }
        return ans;
    }
};