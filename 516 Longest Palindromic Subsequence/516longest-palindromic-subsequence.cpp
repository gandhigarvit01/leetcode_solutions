class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> t(n, vector<int>(n));
        for(int l=1; l<=n; l++){
            for(int i=0; i+l-1<n; i++){
                int j = i+l-1;
                if(i==j){
                    t[i][j] = 1;
                }
                else if(i+1 == j){
                    if(s[i]==s[j]){
                        t[i][j] = 2;
                    }
                    else t[i][j] = 1;
                }
                else if(s[i]==s[j]){
                    t[i][j] = 2 + t[i+1][j-1];
                }
                else{
                    t[i][j] = max(t[i][j-1],t[i+1][j]);
                }
            }
        }
        return t[0][n-1];
    }
};