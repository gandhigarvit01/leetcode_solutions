class Solution {
public:
    int n;
    vector<int> dp;
    bool solve(string& s, int i, unordered_set<string>& st){
        if(i==n) return true;
        if(dp[i]!=-1) return dp[i];
        for(int idx=1; idx<n-i+1; idx++){
            string t = s.substr(i,idx);
            if(st.find(t)!=st.end() && solve(s,i+idx,st)) return dp[i] = true;
        }
        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        dp.assign(n+1, -1);
        return solve(s,0,st);
    }
};