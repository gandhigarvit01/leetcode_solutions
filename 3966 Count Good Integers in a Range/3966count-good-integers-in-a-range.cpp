class Solution {
public:
    long long dp[17][2][11];
    long long solve(string& s, int idx, bool tight, int last, int k){
        if(idx==s.size()) return 1;
        if(dp[idx][tight][last+1]!=-1) return dp[idx][tight][last+1];
        int ul = tight ? s[idx]-'0' : 9;
        long long ans = 0;
        for(int i=0; i<=ul; i++){
            if(last==-1 || abs(i-last)<=k){
                int n_last = i;
                if(last==-1 && i==0) n_last = -1;
                ans += solve(s,idx+1,(tight && i==ul),n_last,k);
            }
        }
        return dp[idx][tight][last+1] = ans;
    }
    long long goodIntegers(long long l, long long r, int k) {
        string s1 = to_string(l-1);
        string s2 = to_string(r);
        memset(dp,-1,sizeof(dp));
        long long ans1 = solve(s1, 0, 1, -1, k);
        memset(dp,-1,sizeof(dp));
        long long ans2 = solve(s2, 0, 1, -1, k);
        return ans2 - ans1;
    }
};