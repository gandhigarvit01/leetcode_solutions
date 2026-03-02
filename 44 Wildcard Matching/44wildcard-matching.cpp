class Solution {
public:
    int n,m;
    vector<vector<int>> dp;
    bool solve(string& s, string& p, int i, int j){
        if(i>=n && j>=m) return true;
        if(j>=m) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        if(p[j]=='?'){
            if(i>=n) return false;
            return dp[i][j] = solve(s,p,i+1,j+1);
        }
        else if(p[j]=='*'){
            bool not_take = solve(s,p,i,j+1);
            bool take = false;
            if(i<n) take = solve(s,p,i+1,j);
            return dp[i][j] = not_take || take;
        }
        if(i>=n) return false;
        if(s[i]!=p[j]) return dp[i][j] = false;
        return dp[i][j] = solve(s,p,i+1,j+1); 
    }
    bool isMatch(string s, string p) {
        n = s.size();
        m = p.size();
        dp.assign(n+1, vector<int>(m+1,-1));
        return solve(s,p,0,0);
    }
};