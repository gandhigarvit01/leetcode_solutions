class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x){
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y){
        int par_x = find(x);
        int par_y = find(y);

        if(par_x==par_y) return;
        if(rank[par_x]>rank[par_y]){
            parent[par_y] = par_x;
        }
        else if(rank[par_y]>rank[par_x]){
            parent[par_x] = par_y;
        }
        else{
            parent[par_y] = par_x;
            rank[par_x]++;
        }
        return;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        parent.resize(n+1);
        rank.resize(n+1,1);
        for(int i=1; i<=n; i++){
            parent[i] = i;
        }
        int m = roads.size();
        for(int i=0; i<m; i++){
            unite(roads[i][0],roads[i][1]);
        }
        int ans = INT_MAX;
        int par_1 = find(1);
        for(int i=0; i<m; i++){
            if(find(roads[i][0])==par_1){
                ans = min(ans,roads[i][2]);
            }
        }
        return ans;
    }
};