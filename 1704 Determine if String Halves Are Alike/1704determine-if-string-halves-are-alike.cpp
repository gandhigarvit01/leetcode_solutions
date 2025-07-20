class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        int i=0;
        int j=n/2;
        int vow1=0,vow2=0;
        while(i<n/2 && j<n){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                vow1++;
            }
            if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'||s[j]=='A'||s[j]=='E'||s[j]=='I'||s[j]=='O'||s[j]=='U'){
                vow2++;
            }
            i++;
            j++;
        }
        return vow1==vow2;
    }
};