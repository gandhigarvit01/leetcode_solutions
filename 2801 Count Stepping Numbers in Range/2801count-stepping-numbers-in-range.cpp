class Solution {
public:
    int mod = 1e9+7;
    int dp[102][2][2][12];
    int solve(string& s, int idx, bool tight, bool lz, int prev){
        if(idx==s.size()) return lz==0;
        if(dp[idx][tight][lz][prev]!=-1) return dp[idx][tight][lz][prev];
        int ans = 0;
        int ub = tight==true ? s[idx]-'0' : 9;
        if(prev==10){
            for(int i=0; i<=ub; i++){
                ans = (ans + solve(s, idx+1, (tight) && (i==ub), (lz) && (i==0), i==0 && lz?10:i))%mod;
            }
        }
        else{
            int less = prev-1;
            int more = prev+1;
            if(less>=0 && less<=ub) ans = (ans + solve(s, idx+1, (tight) && (less==ub), (lz && less==0), less==0 && lz?10:less))%mod;
            if(more<=ub) ans = (ans + solve(s, idx+1, (tight) && (more==ub), 0, more))%mod;
        }
        return dp[idx][tight][lz][prev] = ans;
    }
    int countSteppingNumbers(string low, string high) {
        memset(dp, -1, sizeof(dp));
        int l = solve(low, 0, 1, 1, 10);
        memset(dp, -1, sizeof(dp));
        int r = solve(high, 0, 1, 1, 10);
        bool is_low_stepping = true;
        int m = low.size();
        for(int i=1; i<m; i++){
            if(abs(low[i]-low[i-1])!=1) is_low_stepping = false;
        }
        if(is_low_stepping) l--;
        return (r-l+mod) % mod;
    }
};