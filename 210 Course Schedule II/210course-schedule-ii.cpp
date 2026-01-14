class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n);
        for(vector<int> vec : prerequisites){
            int u = vec[1];
            int v = vec[0];
            adj[u].push_back(v);
        }
        for(int i=0; i<n; i++){
            for(int k : adj[i]){
                indegree[k]++;
            }
        }
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v : adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
            ans.push_back(u);
        }
        return ans.size()==n?ans:vector<int>{};
    }
};