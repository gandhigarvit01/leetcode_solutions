class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, vector<int>> mpp;
        vector<int> all;
        for(int i=0; i<n; i++){
            all.push_back(i);
        }
        int m = invocations.size();
        for(int i=0; i<m; i++){
            int u = invocations[i][0];
            int v = invocations[i][1];
            adj[u].push_back(v);
            mpp[v].push_back(u);
        }
        set<int> bugs;
        queue<int> q;
        vector<bool> visited(n,false);
        visited[k] = true;
        q.push(k);
        bugs.insert(k);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v : adj[u]){
                if(!visited[v]){
                    visited[v] = true;
                    bugs.insert(v);
                    q.push(v);
                }
            }
        }
        for(auto it = bugs.begin(); it!=bugs.end(); it++){
            for(int v : mpp[*it]){
                if(bugs.find(v)==bugs.end()){
                    return all;
                }
            }
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(bugs.find(i)==bugs.end()) ans.push_back(i);
        }
        return ans;
    }
};