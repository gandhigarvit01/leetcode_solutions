class Solution {
public:
    int n,m;
    bool solve(string& s, string& p, int i, int j){
        if(i>=n && j>=m) return true;
        if(j>=m) return false;
        if(p[j]=='.'){
            if((j+1<m && p[j+1]!='*') || j==m-1){
                if(i>=n) return false;
                return solve(s,p,i+1,j+1);
            }
            bool not_take = solve(s,p,i,j+2);
            bool take = false;
            if(i<n) take = solve(s,p,i+1,j);
            return not_take || take;
        }
        if((j+1<m && p[j+1]!='*') || j==m-1){
            if(i>=n || p[j]!=s[i]) return false;
            return solve(s,p,i+1,j+1);
        }
        bool not_take = solve(s,p,i,j+2);
        bool take = false;
        if(i<n && s[i]==p[j]){
            take = solve(s,p,i+1,j);
        }
        return not_take || take;
    }
    bool isMatch(string s, string p) {
        n = s.size();
        m = p.size();
        return solve(s,p,0,0);
    }
};