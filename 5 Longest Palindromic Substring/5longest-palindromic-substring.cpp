class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
        int ans = INT_MIN;
        int idx;
        int len = 1;
        while(len<=n){
            for(int i=0; i<n-len+1; i++){
                int j = i+len-1;
                if(i==j){
                    dp[i][j] = 1;
                    if(j-i+1 > ans){
                        ans = j-i+1;
                        idx = i;
                    }
                }
                else{
                    int l = i+1;
                    int r = j-1;
                    if(l<r){
                        if(dp[l][r]==1 && s[i]==s[j]){
                            dp[i][j] = 1;
                            if(j-i+1 > ans){
                                ans = j-i+1;
                                idx = i;
                            }
                        }
                    }
                    else{
                        if(s[i]==s[j]){
                            dp[i][j] = 1;
                            if(j-i+1 > ans){
                                ans = j-i+1;
                                idx = i;
                            }
                        }
                    }
                }
            }
            len++;
        }
        return s.substr(idx,ans);
    }
};