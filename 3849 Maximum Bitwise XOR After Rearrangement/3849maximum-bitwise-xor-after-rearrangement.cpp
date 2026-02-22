class Solution {
public:
    string maximumXor(string s, string t) {
        int n = s.size();
        int setbits = 0;
        for(int i=0; i<n; i++){
            if(t[i]=='1') setbits++;
        }
        int unsetbits = n - setbits;
        string ans = "";
        for(int i=0; i<n; i++){
            if(s[i]=='1'){
                if(unsetbits>0){
                    unsetbits--;
                    ans += '1';
                }
                else{
                    setbits--;
                    ans += '0';
                }
            }
            else{
                if(setbits>0){
                    setbits--;
                    ans += '1';
                }
                else{
                    unsetbits--;
                    ans += '0';
                }
            }
        }
        return ans;
    }
};