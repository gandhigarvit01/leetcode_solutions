class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int i = 0, j = 1;  
        vector<int> result;
        result.push_back(mat[0][0]);
        if(m==1 && n==1){
            return result;
        }
        else if(m==1){
            for(int i=1; i<n; i++){
                result.push_back(mat[0][i]);
            }
            return result;
        }
        else if(n==1){
            for(int i=1; i<m; i++){
                result.push_back(mat[i][0]);
            }
            return result;
        }

        while(result.size() < m * n){
            if(i==0 || j==n-1){
                while(i<m && j>=0){
                    result.push_back(mat[i][j]);
                    i++;
                    j--;
                }
                i--; j++;
                if(i==m-1) j++;
                else i++;
            }
            else if(j==0 || i==m-1){
                while(i>=0 && j<n){
                    result.push_back(mat[i][j]);
                    i--;
                    j++;
                }
                i++; j--;
                if(j==n-1) i++;
                else j++;
            }
        }
        return result;
    }
};
