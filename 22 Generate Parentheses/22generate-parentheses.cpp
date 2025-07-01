class Solution {
public:
    vector<string> vec;
    void solve(string s, int op, int cl){
        if(op==0 && cl==0){
            vec.push_back(s);
            return;
        }
        if(op>0){
        solve(s+'(',op-1,cl);
        }
        if(cl>op){
            solve(s+')',op,cl-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vec.clear();
        solve("",n,n);
        return vec;
    }
};