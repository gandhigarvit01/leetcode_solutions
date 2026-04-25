class Solution {
public:
    bool validDigit(int n, int x) {
        string s = to_string(n);
        int m = s.size();
        int occurence = 0;
        if(s[0]-'0' == x) return false;
        for(int i=0; i<m; i++){
            if(s[i]-'0' == x) return true;
        }
        return false;
    }
};