class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        int fr = 0, lr = m-1, fc = 0, lc = n-1;
        while(fr<=lr && fc<=lc){
            for(int j=fc; j<=lc; j++){
                ans.push_back(matrix[fr][j]);
            }
            for(int i=fr+1; i<=lr; i++){
                ans.push_back(matrix[i][lc]);
            }
            for(int j=lc-1; j>=fc; j--){
                if(fr!=lr) ans.push_back(matrix[lr][j]);
            }
            for(int i=lr-1; i>fr; i--){
                if(fc!=lc) ans.push_back(matrix[i][fc]);
            }
            fr++, fc++, lr--, lc--;
        }
        return ans;
    }
};