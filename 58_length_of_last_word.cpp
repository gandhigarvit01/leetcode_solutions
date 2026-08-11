class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int idx = n-1;
        while(idx>=0 && s[idx]==' ') idx--;
        int len = 0;
        while(idx>=0 && s[idx]!=' '){
            len++;
            idx--;
        }
        return len;
    }
};