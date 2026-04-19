class Solution {
public:
    set<int> st;
    long long dp[17][2][2][10];
    long long solve(string& s, int idx, bool tight, bool lz, int prev, int offset){
        if(idx==s.size()) return 1;
        if(dp[idx][tight][lz][prev]!=-1) return dp[idx][tight][lz][prev];
        int ub = tight==true ? s[idx]-'0' : 9;
        long long ans = 0;
        for(int i=0; i<=ub; i++){
            bool ntight = tight && i==ub;
            bool nlz = lz && i==0;
            if(st.find(idx+offset)!=st.end()){
                if(i>=prev) ans += solve(s, idx+1, ntight, nlz, i, offset);
            }
            else{
                ans += solve(s, idx+1, ntight, nlz, prev, offset);
            }
        }
        return dp[idx][tight][lz][prev] = ans;
    }
    long long countGoodIntegersOnPath(long long l, long long r, string directions) {
        string s1 = to_string(l-1);
        string s2 = to_string(r);
        int k = 0;
        st.insert(k);
        for(int i=0; i<=5; i++){
            if(directions[i]=='D') k = k+4;
            else k = k+1;
            st.insert(k);
        }
        int offset = 16-s1.size();
        memset(dp, -1, sizeof(dp));
        long long left = solve(s1, 0, 1, 1, 0, offset);
        offset = 16-s2.size();
        memset(dp, -1, sizeof(dp));
        long long right = solve(s2, 0, 1, 1, 0, offset);
        return right-left;
    }
};