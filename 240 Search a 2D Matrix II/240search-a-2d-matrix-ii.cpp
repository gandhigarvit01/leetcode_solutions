class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int a=0, b=m-1;
        while(a<n && b>=0){
            if(matrix[a][b]==target){
                return true;
            }
            else if(matrix[a][b]<target){
                a++;
            }
            else{
                b--;
            }
        }
        return false;
    }
};