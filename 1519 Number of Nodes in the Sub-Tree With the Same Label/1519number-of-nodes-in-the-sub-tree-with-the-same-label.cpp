class Solution {
public:
    void solve(int u,vector<vector<int>>& adj,int parent,string& labels,vector<int>& result,vector<int>& count){
        int prev = count[labels[u]-'a'];
        for(int v : adj[u]){
            if(v!=parent){
                solve(v,adj,u,labels,result,count);
            }
        }
        count[labels[u]-'a']++;
        result[u] = count[labels[u]-'a']-prev;
        return;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for(auto& vec : edges){
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }
        vector<int> result(n,0);
        vector<int> count(26,0);
        solve(0,adj,-1,labels,result,count);
        return result;
    }
};