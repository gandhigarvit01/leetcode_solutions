class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n,0);
        if(s[0]=='0') return 0;
        if(n==1) return 1;
        dp[0] = 1;
        if(s[1]!='0') dp[1] = 1;
        if(s[0]=='1' || (s[0]=='2' && s[1]<='6')) dp[1] += 1;
        for(int i=2; i<n; i++){
            if(s[i]=='0'){
                if(s[i-1]=='1' || s[i-1]=='2'){
                    dp[i] = dp[i-2];
                }
            }
            else{
                if(s[i-1]=='0'){
                    dp[i] = dp[i-1];
                }
                else{
                    dp[i] = dp[i-1];
                    if(s[i-1]=='1' || (s[i-1]=='2' && s[i]<='6')) dp[i] += dp[i-2];
                }
            }
        }
        return dp[n-1];
    }
};