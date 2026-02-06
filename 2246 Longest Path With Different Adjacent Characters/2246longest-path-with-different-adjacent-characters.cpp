class Solution {
public:
    int ans = 0;
    int solve(int u, vector<vector<int>>& adj, vector<int>& parent, string& s){
        int path1 = 0, path2 = 0;
        for(int v : adj[u]){
            if(v!=parent[u]){
                int child = solve(v,adj,parent,s);
                if(s[u]!=s[v]){
                    if(child>path1){
                        path2 = path1;
                        path1 = child;
                    }
                    else if(child>path2){
                        path2 = child;
                    }
                }
            }
        }
        ans = max(ans,path1+path2+1);
        return max(path1,path2)+1;
    }
    int longestPath(vector<int>& parent, string s) {
        int n = s.size();
        vector<vector<int>> adj(n);
        for(int i=1; i<n; i++){
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
        int res = solve(0,adj,parent,s);
        return ans;
    }
};