class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>> adj;
        for(auto &v : dislikes){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<int> visited(n+1,-1);
        queue<pair<int,int>> q;
        for(int i=1; i<=n; i++){
            if(visited[i]==-1){
                visited[i] = 0;
                q.push({i,0});
                while(!q.empty()){
                    pair<int,int> p = q.front();
                    q.pop();
                    int node = p.first;
                    int color = p.second;
                    for(auto &v : adj[node]){
                        if(visited[v]==color){
                            return false;
                        }
                        else if(visited[v]==-1){
                            q.push({v,1-color});
                            visited[v] = 1-color;
                        }
                    }
                }
            }
        }
        return true;
    }
};