class Solution {
public:
    long long dp[17][2][2];
    long long solve(string& s, int idx, bool tight, bool lz){
        if(idx==s.size()) return 1;
        if(dp[idx][tight][lz]!=-1) return dp[idx][tight][lz];
        int lb = 0;
        int ub = (tight==true) ? s[idx]-'0' : 9;
        long long ans = 0;
        for(int i=lb; i<=ub; i++){
            if(i==0 && !lz) continue;
            ans += solve(s,idx+1,(tight && i==ub), (lz && i==0));
        }
        return dp[idx][tight][lz] = ans;
    }
    long long countDistinct(long long n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, 1, 1)-1;
    }
};