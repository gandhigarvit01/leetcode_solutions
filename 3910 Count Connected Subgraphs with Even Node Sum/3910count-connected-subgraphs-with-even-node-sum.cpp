class Solution {
public:
    int n;
    int dp[13][8192];
    int solve(vector<int>& nums, int idx, unordered_map<int,vector<int>>& adj, int mask){
        if(idx==n){
            int sum = 0;
            if(mask==0) return 0;               // if no node selected
            for(int i=0; i<13; i++){
                if((mask & (1<<i))!=0){
                    sum += nums[i];
                }
            }
            if(sum%2!=0) return 0;             // if sum is odd
            vector<bool> visited(13,false);
            int start = -1;
            for(int i=0; i<13; i++){
                if((mask & (1<<i)) != 0){
                    start = i;
                    break;
                }
            }
            queue<int> q;
            q.push(start);
            visited[start] = true;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(auto v : adj[u]){
                    if(!visited[v] && ((mask & (1<<v)) != 0)){
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
            for(int i=0; i<13; i++){
                if((mask & (1<<i))!=0 && (!visited[i])) return 0; 
                // nodes not connected
            }
            return 1;
        }
        if(dp[idx][mask]!=-1) return dp[idx][mask];
        int skip, take;
        skip = solve(nums, idx+1, adj, mask);
        int n_mask = mask | (1<<idx);
        take = solve(nums, idx+1, adj, n_mask);
        return dp[idx][mask] = skip + take;
    }
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        n = nums.size();
        unordered_map<int,vector<int>> adj;
        for(auto vec : edges){
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        memset(dp, -1, sizeof(dp));
        int ans = solve(nums, 0, adj, 0);
        return ans;
    }
};