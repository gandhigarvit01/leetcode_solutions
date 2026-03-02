class Solution {
public:
    int n,m;
    vector<vector<int>> dp;
    int solve(string& s, string& t, int i, int j){
        if(j==m) return 1;
        if(i==n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take = 0, leave = 0;
        leave = solve(s,t,i+1,j);
        if(s[i]==t[j]) take = solve(s,t,i+1,j+1);
        return dp[i][j] = take + leave;
    }
    int numDistinct(string s, string t) {
        n = s.size();
        m = t.size();
        dp.assign(n+1, vector<int>(m+1, -1));
        return solve(s,t,0,0);
    }
};