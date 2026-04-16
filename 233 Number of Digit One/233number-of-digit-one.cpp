class Solution {
public:
    int dp[11][2][11];
    int solve(string& s, int idx, bool tight, int ones){
        if(idx==s.size()){
            return ones;
        }
        if(dp[idx][tight][ones]!=-1) return dp[idx][tight][ones];
        int ans = 0;
        int ub = (tight==true)? s[idx]-'0' : 9;
        for(int i=0; i<=ub; i++){
            int new_ones = ones;
            if(i==1) new_ones++;
            ans += solve(s, idx+1, (tight && i==ub), new_ones);
        }
        return dp[idx][tight][ones] = ans;
    }
    int countDigitOne(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(s,0,1,0);
    }
};