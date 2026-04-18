class Solution {
public:
    int dp[11][2][2][1025][2];
    int solve(string& s, int idx, bool tight, bool lz, int bitmask, bool repeat){
        if(idx==s.size()){
            return repeat==true;
        }
        if(dp[idx][tight][lz][bitmask][repeat]!=-1) return dp[idx][tight][lz][bitmask][repeat];
        int ub = tight==true ? s[idx]-'0' : 9;
        int ans = 0;
        for(int i=0; i<=ub; i++){
            if(i==0 && lz){
                ans += solve(s, idx+1, (tight && i==ub), 1, bitmask, repeat);
            }
            else{
                bool new_tight = tight && (i==ub);
                int mask = bitmask | (1<<i);
                bool rep = repeat || (bitmask & (1<<i));
                ans += solve(s, idx+1, new_tight, 0, mask, rep);
            }
        }
        
        return dp[idx][tight][lz][bitmask][repeat] = ans;
    }
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, 1, 1, 0, 0);
    }
};