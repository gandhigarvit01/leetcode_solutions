class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int count = 0;
        for(int j=0; j<n; j++){
            if(matrix[0][j]==1){
                count++;
            }
        }
        for(int i=1; i<m; i++){
            if(matrix[i][0]==1){
                count++;
            }
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][j]==1){
                int left = matrix[i][j-1];
                int up = matrix[i-1][j];
                int upleft = matrix[i-1][j-1];
                int mini = min(up,min(left,upleft));
                matrix[i][j] = mini+1;
                count += mini+1;
                }
            }
        }
        return count;
    }
};