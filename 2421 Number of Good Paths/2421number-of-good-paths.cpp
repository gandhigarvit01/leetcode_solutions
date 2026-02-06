class Solution {
public:
    vector<int> rank;
    vector<int> parent;

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
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        int ans = n;
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
        vector<vector<int>> adj(n);
        for(auto& vec : edges){
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }
        map<int, vector<int>> mpp; // val -> nodes
        for(int i=0; i<n; i++){
            mpp[vals[i]].push_back(i);
        }
        vector<bool> isactive(n,false);

        for(auto& it : mpp){
            vector<int> nodes = it.second;
            for(int& u : nodes){
                isactive[u] = true;
                for(int& v : adj[u]){
                    if(isactive[v]){
                        unite(u,v);
                    }
                }
            }
            int m = nodes.size();
            for(int i=0; i<m; i++){
                nodes[i] = find(nodes[i]);
            }
            sort(nodes.begin(),nodes.end());
            for(int j=0; j<m; j++){
                long long count = 0;
                int curr_par = nodes[j];
                while(j<m && nodes[j]==curr_par){
                    count++;
                    j++;
                }
                j--;
                int pairs = (count*(count-1))/2;
                ans += pairs;
            }
        }
        return ans;
    }
};