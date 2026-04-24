class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int m = allowedSwaps.size();
        int n = source.size();
        unordered_map<int,vector<int>> adj;  // graph representation
        for(int i=0; i<m; i++){
            int u = allowedSwaps[i][0];
            int v = allowedSwaps[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n,false);
        int ans = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                queue<int> q;
                unordered_map<int,int> mpp;
                q.push(i);
                visited[i] = true;
                while(!q.empty()){
                    int idx = q.front();
                    mpp[source[idx]]++;
                    mpp[target[idx]]--;
                    q.pop();
                    for(int v : adj[idx]){
                        if(!visited[v]){
                            visited[v] = true;
                            q.push(v);
                        }
                    }
                }
                int curr = 0;
                for(auto it : mpp){
                    curr += abs(it.second);
                }
                ans += curr/2;
            }
        }
        return ans;
    }
};