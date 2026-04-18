class Solution {
public:
    set<int> st;
    int dp[11][2][2];
    int solve(string& s, int idx, bool tight, bool lz){
        if(idx==s.size()){
            return 1;
        }
        if(dp[idx][tight][lz]!=-1) return dp[idx][tight][lz];
        int ans = 0;
        int lb = 0;
        int ub = (tight==true)? s[idx]-'0' : 9;
        for(int i=lb; i<=ub; i++){
            if(lz && i==0){
                ans += solve(s, idx+1, (tight && i==ub), 1);
            }
            else if(st.find(i)!=st.end()){
                ans += solve(s, idx+1, (tight && i==ub), 0);
            }
        }
        return dp[idx][tight][lz] = ans;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int m = digits.size();
        for(int i=0; i<m; i++){
            st.insert(stoi(digits[i]));
        }
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, 1, 1)-1;
    }
};