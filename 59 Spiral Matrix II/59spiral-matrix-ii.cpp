class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int>(n, 0));
        int a=0, c=0, b=n-1, d=n-1;
        int k=1;
         while(a<=b && c<=d){
                for(int j=c; j<=d; j++){
                    v[a][j] = k;
                    k++;
                }
                 a++;
                for(int i=a; i<=b; i++){
                    v[i][d] = k;
                    k++;
                }
                d--;
                for(int j=d; j>=c; j--){
                    v[b][j] = k;
                    k++;
                }
                 b--;
                for(int i=b; i>=a; i--){
                    v[i][c] = k;
                    k++;
                }
                 c++;
        }
        return v;
    }
};