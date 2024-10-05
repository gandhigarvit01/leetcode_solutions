class Solution {
public:
    bool checkRecord(string s) {
        int n=s.length();
        int x=0,y=0;
        for(int i=0; i<n; i++){
            if(s[i]=='A'){
                x++;
            }
            if(i<n-2 && s[i]=='L' && s[i+1]=='L' && s[i+2]=='L'){
                return false;
                
            }
        }
        if(x<2) return true;
        else return false;
    }
};