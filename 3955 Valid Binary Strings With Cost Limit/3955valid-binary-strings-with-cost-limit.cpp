class Solution {
public:
    vector<string> vec;
    void solve(string s, int i, int n, int k){
        if(i==n){
            int cost = 0;
            for(int i=1; i<n; i++){
                if(s[i]=='1' && s[i-1]=='1') return;
                if(s[i]=='1') cost += i;
            }
            if(cost <= k) vec.push_back(s);
            return;
        }
        s.push_back('0');
        solve(s,i+1,n,k);
        s.pop_back();
        s.push_back('1');
        solve(s,i+1,n,k);
    }
    vector<string> generateValidStrings(int n, int k) {
        string s = "";
        solve(s,0,n,k);
        return vec;
    }
};