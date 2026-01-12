class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int value = 1;
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        q.push({-1,-1});
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            int u = p.first;
            int v = p.second;
            if(u==-1){
                if(!q.empty()){
                    value++;
                    q.push({-1,-1});
                }
            }
            else{
                if(u-1>=0 && mat[u-1][v]==1){
                    mat[u-1][v] = -value;
                    q.push({u-1,v});
                }
                if(v-1>=0 && mat[u][v-1]==1){
                    mat[u][v-1] = -value;
                    q.push({u,v-1});
                }
                if(v+1<n && mat[u][v+1]==1){
                    mat[u][v+1] = -value;
                    q.push({u,v+1});
                }
                if(u+1<m && mat[u+1][v]==1){
                    mat[u+1][v] = -value;
                    q.push({u+1,v});
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                mat[i][j] = -mat[i][j];
            }
        }
        return mat;
    }    
};