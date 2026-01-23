class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();
        // prefix sum for rows
        for(int i=0; i<m; i++){
            for(int j=1; j<n; j++){
                mat[i][j] += mat[i][j-1]; 
            }
        }
        // prefix sum for cols now
        for(int j=0; j<n; j++){
            for(int i=1; i<m; i++){
                mat[i][j] += mat[i-1][j];
            }
        }
        int max_side = min(m,n);
        int l = 1;
        int r = max_side;
        int ans = 0;
        while(l<=r){
            int k = l+(r-l)/2;
            int squares = 0;
            for(int i=k-1; i<m; i++){
                for(int j=k-1; j<n; j++){
                    int a = i-k;
                    int b = j-k;

                    if(a>=-1 && b>=-1){
                    int sub1 = a==-1?0:mat[a][j];
                    int sub2 = b==-1?0:mat[i][b];
                    int add1 = 0;
                    if(a>=0 && b>=0){
                        add1 = mat[a][b];
                    }
                    int sum = mat[i][j] - sub1 - sub2 + add1;
                    if(sum<=threshold){
                        squares++;   
                    }
                    }
                }
            }
            if(squares>0){
                ans = k;
                l = k+1;
            }
            else{
                r = k-1;
            } 
        }
        return ans;
    }
};