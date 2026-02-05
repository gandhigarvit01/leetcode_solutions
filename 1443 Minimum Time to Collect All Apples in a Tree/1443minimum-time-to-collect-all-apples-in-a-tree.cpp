class Solution {
public:
    int time(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& hasApple){
        visited[u] = true;
        int ans = 0;
        for(int v : adj[u]){
            if(!visited[v]){
                ans += time(v,adj,visited,hasApple);
            }
        }
        if(hasApple[u] || ans>0){
            ans += 2;
        }
        return ans;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n,false);
        for(auto& vec : edges){
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }
        int result = time(0,adj,visited,hasApple);
        return result>0?result-2:0;
    }
};