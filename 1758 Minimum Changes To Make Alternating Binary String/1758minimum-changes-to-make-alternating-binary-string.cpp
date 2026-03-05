class Solution {
public:
    int n;
    int operation(string& t){
        n = t.size();
        int ans = 0;
        for(int i=1; i<n; i++){
            if(t[i]==t[i-1]){
                ans++;
                t[i] = t[i]=='0'?'1':'0';
            }
        }
        return ans;
    }
    int minOperations(string s) {
        int ans = 0;
        string t = s;
        if(n==1) return 0;
        ans = operation(t);
        s[0] = s[0]=='0'?'1':'0';
        ans = min(ans, operation(s)+1);
        return ans;
    }
};