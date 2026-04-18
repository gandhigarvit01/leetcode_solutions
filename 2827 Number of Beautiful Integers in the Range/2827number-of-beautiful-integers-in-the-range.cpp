class Solution {
public:
    int dp[11][2][2][21][21];
    int solve(string& s, int idx, bool tight, bool lz, int var, int num, int k){
        if(idx==s.size()){
            return (var==10 && num % k==0); 
        }
        if(dp[idx][tight][lz][var][num]!=-1) return dp[idx][tight][lz][var][num];
        int ub = tight==true ? s[idx]-'0' : 9;
        int ans = 0;
        for(int i=0; i<=ub; i++){
            bool ntight = tight && i==ub;
            bool nlz = lz && i==0;
            int nvar = nlz ? 10 : i%2==0 ? var+1 : var-1;
            int nnum = (num*10 + i) % k;
            ans += solve(s, idx+1, ntight, nlz, nvar, nnum, k);
        }
        return dp[idx][tight][lz][var][num] = ans;
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        string s1 = to_string(low-1);
        string s2 = to_string(high);
        memset(dp, -1, sizeof(dp));
        int l = solve(s1,0,1,1,10,0,k);
        memset(dp, -1, sizeof(dp));
        int r = solve(s2,0,1,1,10,0,k);
        return r-l;
    }
};