class Solution {
public:
    int xtra;
    void dfs(int u, int parent, unordered_map<int,vector<int>>& mpp, vector<bool>& visited){
        visited[u] = true;
        for(int v : mpp[u]){
            if(visited[v] && v!=parent) xtra++;
            else if(!visited[v]){
                dfs(v,u,mpp,visited);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        xtra = 0;
        vector<bool> visited(n,false);
        unordered_map<int,vector<int>> mpp;
        for(auto& vec : connections){
            mpp[vec[0]].push_back(vec[1]);
            mpp[vec[1]].push_back(vec[0]);
        }
        int components = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                components++;
                dfs(i,-1,mpp,visited);
            }
        }
        int need = components-1;
        if(xtra/2 >= need) return need;
        return -1;
    }
};