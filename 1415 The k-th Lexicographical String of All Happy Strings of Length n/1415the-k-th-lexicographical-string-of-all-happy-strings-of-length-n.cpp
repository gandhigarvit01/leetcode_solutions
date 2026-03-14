class Solution {
public:
    set<string> st;
    int m;
    void solve(string& s, int n){
        if(n==0){
            for(int i=1; i<m; i++){
                if(s[i]==s[i-1]) return;
            }
            st.insert(s);
            return;
        }
        s.push_back('a');
        solve(s,n-1);
        s.pop_back();
        s.push_back('b');
        solve(s,n-1);
        s.pop_back();
        s.push_back('c');
        solve(s,n-1);
        s.pop_back();
        return;
    }
    string getHappyString(int n, int k) {
        string s = "";
        m = n;
        solve(s,n);
        string ans;
        if(k>st.size()) return "";
        auto it = st.begin();
        advance(it,k-1);
        ans = *it;
        return ans;
    }
};