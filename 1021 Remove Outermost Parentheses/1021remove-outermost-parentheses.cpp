class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=-1;
        int n= s.length();
        string k="";
        for(int i=0; i<n; i++){
            if(s[i]=='(') count++;
            else count--;
            if(s[i]=='(' && count>0){
                k += '(';
            }
            else if(s[i]==')' && count>-1){
                k += ')';
            }
        }
        return k;

    }
};