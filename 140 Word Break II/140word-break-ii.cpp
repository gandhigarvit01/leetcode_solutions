class Solution {
public:
    int n;
    unordered_map<int,vector<string>> dp;
    vector<string> solve(string& s, int i, unordered_set<string>& st){
        if(i==n) return {""};
        if(dp.count(i)) return dp[i];
        vector<string> ans;
        for(int idx=1; idx<n-i+1; idx++){
            string t = s.substr(i,idx);
            if(st.find(t)!=st.end()){
                vector<string> res = solve(s,i+idx,st);
                int m = res.size();
                for(int j=0; j<m; j++){
                    if(res[j]=="") ans.push_back(t);
                    else{
                        string k = t + ' ' + res[j];
                        ans.push_back(k);
                    }
                }
            }
        }
        return dp[i] = ans;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        dp.clear();
        return solve(s,0,st);
    }
};