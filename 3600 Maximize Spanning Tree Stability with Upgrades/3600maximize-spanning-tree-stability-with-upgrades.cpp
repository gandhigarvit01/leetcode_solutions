class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    void unite(int x,int y)
    {
        int px = find(x);
        int py = find(y);

        if(px==py)
        return;

        if(rank[px]<rank[py])
        parent[px]=py;

        else if(rank[py]<rank[px])
        parent[py]=px;

        else
        {
            parent[py]=px;
            rank[px]++;
        }
    }
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x]);
    }
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int ans = INT_MAX;
        parent.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
        rank.resize(n,0);
        priority_queue< pair<int, pair<int,int>>,
        vector<pair<int, pair<int,int>>>> pq;
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            int must = edges[i][3];
            if(must==0){
                pq.push({wt,{u,v}});
            }
            else{
                int par_u = find(u);
                int par_v = find(v);
                if(par_u==par_v) return -1;
                unite(u,v);
                ans = min(ans,wt);
            }
        }
        vector<int> upgrades;
        while(!pq.empty()){
            int wt = pq.top().first;
            int u = pq.top().second.first;
            int v = pq.top().second.second;
            pq.pop();
            int par_u = find(u);
            int par_v = find(v);
            if(par_u!=par_v){
                unite(u,v);
                upgrades.push_back(wt);
            }
        }
        int m = upgrades.size();
        for(int i=m-1; i>=0; i--){
            if(k>0){
                ans = min(ans,2*upgrades[i]);
                k--;
            }
            else ans = min(ans,upgrades[i]);
        }
        int main_parent = find(0);
        for(int i=0; i<n; i++){
            if(find(i)!=main_parent) return -1;
        }
        return ans;
    }
};