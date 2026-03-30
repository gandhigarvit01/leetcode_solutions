class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int l=0, r=n-1;
        int ans = 0;
        while(l<r){
            if(s[l]==s[r]){
                while(l+1<r && s[l+1]==s[l]){
                    l++;
                }
                while(r-1>l && s[r-1]==s[r]){
                    r--;
                }
                ans = (l+1) + (n-r);
                l++;
                r--;
            }
            else{
                break;
            }
        }
        return n-ans;
    }
};