class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
        int ans = 0;
        int len = 1;
        while(len<=n){
            for(int i=0; i<n-len+1; i++){
                int j = i+len-1;
                if(i==j){
                    dp[i][j] = 1;
                    ans++;
                }
                else{
                    int l = i+1;
                    int r = j-1;
                    if(l<r){
                        if(dp[l][r]==1 && s[i]==s[j]){
                            dp[i][j] = 1;
                            ans++;
                        }
                    }
                    else{
                        if(s[i]==s[j]){
                            dp[i][j] = 1;
                            ans++;
                        }
                    }
                }
            }
            len++;
        }
        return ans;
    }
};