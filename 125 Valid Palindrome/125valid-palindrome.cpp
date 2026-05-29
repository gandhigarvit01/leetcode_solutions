class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string k;
        for(int i=0; i<n; i++){
            char c = s[i];
            if(isalnum(c)){
                if(isupper(c)) c = tolower(c);
                k.push_back(c);
            }
        }
        int l=0, r=k.size()-1;
        while(l<r){
            if(k[l]==k[r]){
                l++;
                r--;
            }
            else return false;
        }
        return true;
    }
};