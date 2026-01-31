class Solution {
public:
    string reverseByType(string s) {
        int n = s.size();
        int r = n-1;
        int l = 0;
        while(l<r){
            if(islower(s[l])){
                l++;
            }
            else if(islower(s[r])){
                r--;
            }
            else{
                char temp = s[r];
                s[r] = s[l];
                s[l] = temp;
                l++;
                r--;
            }
        }
        l = 0;
        r = n-1;
        while(l<r){
            if(!islower(s[l])){
                l++;
            }
            else if(!islower(s[r])){
                r--;
            }
            else{
                char temp = s[r];
                s[r] = s[l];
                s[l] = temp;
                l++;
                r--;
            }
        }
        return s;
    }
};