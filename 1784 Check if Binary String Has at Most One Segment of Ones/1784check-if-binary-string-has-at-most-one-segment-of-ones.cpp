class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        int segments = 0;
        if(s[0]=='1') segments++;
        for(int i=1; i<n; i++){
            if(s[i]=='1' && s[i-1]=='0'){
                segments++;
                if(segments>1) return false;
            }
        }
        return true;
    }
};