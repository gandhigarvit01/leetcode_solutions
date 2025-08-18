class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int up = INT_MAX, upleft = INT_MAX, upright = INT_MAX;
                if(i>0){
                    up = matrix[i-1][j];
                }
                if(i>0 && j>0){
                    upleft = matrix[i-1][j-1];
                }
                if(i>0 && j<n-1){
                    upright = matrix[i-1][j+1];
                }
                matrix[i][j] = min(up,min(upleft,upright)) + matrix[i][j];
            }
        }
        int ans = INT_MAX;
        for(int j=0; j<n; j++){
            ans = min(ans,matrix[n-1][j]);
        }
        return ans;
    }
};