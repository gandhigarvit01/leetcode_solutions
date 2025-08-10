class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> vec(m, vector<int>(n,0));
        int ones = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]=='1'){
                    ones++;
                    vec[i][j] = 1;
                }
            }
        }
        int ans = ones>0?1:0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i>0 && j>0 && vec[i][j]==1){
                    int temp = min(vec[i-1][j-1],min(vec[i][j-1],vec[i-1][j]));
                    int add = sqrt(temp);
                    vec[i][j] = temp + 2*add + 1;
                    ans = max(ans,vec[i][j]);
                }
            }
        }
        return ans;
    }
};