class Solution {
public:
    vector<int> bfs(int node, vector<vector<int>>& adj, int n){
        vector<int> dist(n,0);
        vector<bool> visited(n,false);
        queue<int> q;
        q.push(node);
        q.push(-1);
        visited[node] = true;
        int dis = 0;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            if(u==-1){
                if(!q.empty()){
                    dis++;
                    q.push(-1);
                }
            }
            else{
                dist[u] = dis;
                for(int v : adj[u]){
                    if(!visited[v]){
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
        }
        return dist;
    }
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        int ans = 0;
        vector<vector<int>> adj(n);
        for(auto& v : edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<int> dx = bfs(x,adj,n);
        vector<int> dy = bfs(y,adj,n);
        vector<int> dz = bfs(z,adj,n);

        for(int i=0; i<n; i++){
            int a,b,c;
            a = dx[i];
            b = dy[i];
            c = dz[i];
            if(((1LL*a*a) + (1LL*b*b) == (1LL*c*c)) || ((1LL*a*a) + (1LL*c*c) == (1LL*b*b)) || ((1LL*b*b) + (1LL*c*c) == (1LL*a*a))){
                ans++;
            }
        }
        return ans;
    }
};