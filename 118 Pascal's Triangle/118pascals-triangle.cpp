class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>> result(n);
        for(int i=0; i<n; i++){
            result[i].resize(i+1);
        }
        result[0][0] = 1;
        for(int i=1; i<n; i++){
            for(int j=0; j<=i; j++){
                if(j==0 || j==i){
                    result[i][j] = 1;
                }
                else{
                    result[i][j] = result[i-1][j-1] + result[i-1][j];
                }
            }
        }
        return result;
    }
};