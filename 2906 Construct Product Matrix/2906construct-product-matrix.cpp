class Solution {
public:
    int mod = 12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> pre(n, vector<int>(m));
        vector<vector<int>> suf(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 && j==0) pre[i][j] = 1;
                else if(j==0){
                    pre[i][j] = ((1LL*pre[i-1][m-1]%mod)*grid[i-1][m-1])%mod;
                }
                else{
                    pre[i][j] = ((1LL*pre[i][j-1]%mod)*grid[i][j-1])%mod;
                }
            }
        }
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(i==n-1 && j==m-1) suf[i][j] = 1;
                else if(j==m-1){
                    suf[i][j] = ((1LL*suf[i+1][0]%mod)*grid[i+1][0])%mod;
                }
                else{
                    suf[i][j] = ((1LL*suf[i][j+1]%mod)*grid[i][j+1])%mod;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                grid[i][j] = ((1LL*pre[i][j]%mod)*suf[i][j])%mod;
            }
        }
        return grid;
    }
};