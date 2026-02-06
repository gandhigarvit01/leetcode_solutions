class Solution {
public:
    void bfs(int node, vector<vector<int>>& adj, vector<bool> visited, vector<int>& dist){
        queue<int> q;
        q.push(node);
        visited[node] = true;
        q.push(-1);
        int level = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if(u==-1){
                if(!q.empty()){
                    q.push(-1);
                    level++;
                }
            }
            else{
                dist[u] = level;
                for(int v : adj[u]){
                    if(!visited[v]){
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
        }

    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++){
            if(edges[i]!=-1){
                adj[i].push_back(edges[i]);
            }
        }
        vector<int> dist1(n,-1);
        vector<int> dist2(n,-1);
        vector<bool> visited(n,false);
        int ans = INT_MAX;
        int idx = INT_MAX;
        bfs(node1,adj,visited,dist1);
        bfs(node2,adj,visited,dist2);
        for(int i=0; i<n; i++){
            if(dist1[i]!=-1 && dist2[i]!=-1){
                ans = min(ans,max(dist1[i],dist2[i]));
            }
        }
        for(int i=0; i<n; i++){
            if(dist1[i]!=-1 && dist2[i]!=-1){
                if(max(dist1[i],dist2[i])==ans){
                    idx = min(idx,i);
                }
            }
        }
        return idx==INT_MAX?-1:idx;
    }
};