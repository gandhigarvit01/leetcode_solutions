class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int ans = 0;
        for(int row=0; row<m; row++){
            int count = 0;
            int col = -1;
            for(int j=0; j<n; j++){
                if(mat[row][j]==1){
                    count++;
                    col = j;
                }
            }
            if(count>1 || count==0) continue;
            else{
                count = 0;
                for(int i=0; i<m; i++){
                    if(mat[i][col]==1) count++;
                }
                if(count==1) ans++;
            }
        }
        return ans;
    }
};