class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    
    int find(int i) {
        if(parent[i] != i)
            parent[i] = find(parent[i]);
        
        return parent[i];
    }
    
    void Union(int x, int y) {
        int p_x = find(x);
        int p_y = find(y);
        
        if(p_x != p_y) {
            if(rank[p_x] > rank[p_y]) {
                parent[p_y] = p_x;
            } else if(rank[p_y] > rank[p_x]) {
                parent[p_x] = p_y;
            } else {
                parent[p_x] = p_y;
                rank[p_y]++;
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
        for(vector<int> vec : edges){
            Union(vec[0],vec[1]);
        }
        for(int i=0; i<n; i++){
            find(i);
        }
        unordered_map<int,int> mpp;
        for(int i=0; i<n; i++){
            mpp[parent[i]]++;
        }
        unsigned long long l=0,m=0;
        for(auto it : mpp){
            l += it.second;
            m += 1ULL*(it.second)*(it.second);
        }
        return ((l*l)-m)/2; 
    }
};