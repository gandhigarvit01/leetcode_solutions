class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> vec(n, vector<int>(m,0));
        vector<vector<bool>> visited(n, vector<bool>(m,false));
        queue<pair<int,pair<int,int>>> q;
        for(auto &ve : sources){
            int u = ve[0];
            int v = ve[1];
            int col = ve[2];
            vec[u][v] = col;
            visited[u][v] = true;
            q.push({col,{u,v}});
        }
        while(!q.empty()){
            int sz = q.size();
            map<pair<int,int>, int> mp;
            for(int k=0; k<sz; k++){
                auto p = q.front();
                q.pop();
                int col = p.first;
                int i = p.second.first;
                int j = p.second.second;
                vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
                for(auto &d : dir){
                    int ni = i + d.first;
                    int nj = j + d.second;
                    if(ni>=0 && nj>=0 && ni<n && nj<m && !visited[ni][nj]){
                        mp[{ni,nj}] = max(mp[{ni,nj}], col);
                    }
                }
            }
            for(auto &it : mp){
                int i = it.first.first;
                int j = it.first.second;
                int col = it.second;
                vec[i][j] = col;
                visited[i][j] = true;
                q.push({col,{i,j}});
            }
        }
        return vec;
    }
};