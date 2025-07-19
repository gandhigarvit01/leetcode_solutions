class Solution {
public:
    string solve(int n){
        if(n==1){
            return "1";
        }
        string s = solve(n-1);
        string k="";
        int i=0;
        int m=s.size();
        while(i<m){
            char curr = s[i];
            int count = 0;
            while(i<m && s[i]==curr){
                count++;
                i++;
            }
            k.push_back(count+'0');
            k.push_back(curr);
        }
        return k;
    }
    string countAndSay(int n) {
        return solve(n);
    }
};