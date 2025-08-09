class Solution {
public:
    int m;
    int n;
    int dp[205][205];
    int solve(int i, int j, vector<vector<int>>& matrix){
        int p1=0,p2=0,p3=0,p4=0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i-1>=0 && matrix[i-1][j]<matrix[i][j]){
            p1 = solve(i-1,j,matrix);
        }
        if(j-1>=0 && matrix[i][j-1]<matrix[i][j]){
            p2 = solve(i,j-1,matrix);
        }
        if(i+1<m && matrix[i+1][j]<matrix[i][j]){
            p3 = solve(i+1,j,matrix);
        }
        if(j+1<n && matrix[i][j+1]<matrix[i][j]){
            p4 = solve(i,j+1,matrix);
        }        
        return dp[i][j] = 1 + max(max(p1,p2),max(p3,p4));
    } 
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        int ans = 0;
        memset(dp,-1,sizeof(dp));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int a = solve(i,j,matrix);
                ans = max(ans,a);
                int b = solve(i,j,matrix);
                ans = max(ans,b);
            }
        }
        return ans;
    }
};