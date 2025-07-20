class Solution {
public:
////////////////////////////////    using KMP Algorithm    ////////////////////////////////////////////
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        vector<int> LPS(m,0);

        LPS[0] = 0;
        int len = 0;
        int i = 1;
        while(i<m){
            if(needle[i]==needle[len]){
                len++;
                LPS[i] = len;
                i++;
            }
            else{
                if(len!=0){
                    len = LPS[len-1];
                }else{
                    LPS[i] = 0;
                    i++;
                }
            }
        }
        i=0; int j=0;
        while(i<n && j<m){
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }
            else{
                if(j!=0){
                    j = LPS[j-1];
                }
                else{
                    i++;
                }
            }
        }
        if(j==m){
            return i-m;
        }
        return -1;

    }
};