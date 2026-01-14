class Solution {
public:
    bool iscycle(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& inpath){
        visited[u] = true;
        inpath[u] = true;

        for(int v : adj[u]){
            if(inpath[v]==true){
                return true;
            }
            if(!visited[v]){
                if(iscycle(v,adj,visited,inpath)){
                    return true;
                }
            }
        }
        inpath[u] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        for(vector<int>& vec : prerequisites){
            int u = vec[1];
            int v = vec[0];
            adj[u].push_back(v);
        }
        vector<bool> visited(n,false);
        vector<bool> inpath(n,false);
        for(int i=0; i<n; i++){
            if(!visited[i] && iscycle(i,adj,visited,inpath)){
                return false;
            }
        }
        return true;
    }
};