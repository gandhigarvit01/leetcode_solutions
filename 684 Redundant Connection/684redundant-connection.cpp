class Solution {
public:
    int find(int x, vector<int>& parent){
        if(parent[x]!=x){
            parent[x] = find(parent[x],parent);
        }
        return parent[x];   
    }
    void unite(int x, int y, vector<int>& parent){
        int px = find(x,parent);
        int py = find(y,parent);

        if(px!=py){
            parent[py] = px;
        }
    }    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        for(int i=0; i<=n; i++){
        parent[i] = i;
        }

        for(int i=0; i<n; i++){
        if(find(edges[i][0],parent)==find(edges[i][1],parent)){
            return edges[i];
        }
        else{
            unite(edges[i][0],edges[i][1],parent);
        }
        }
        return {-1,-1};
    }
};