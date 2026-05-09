class Solution {
public:
    int minFlips(string s) {
        //0 ones, 1 ones, 2 ones (at first and last), all ones,
        int n = s.size();
        int ones = 0, zeros = 0;
        for(int i = 0;i<n;i++) {
            if(s[i]=='1') ones++;
            if(s[i]=='0') zeros++;
        }
        bool twocase = 0;
        if(s[0]=='1' && s[n-1]=='1') twocase = true;
        if(ones==0 || ones==1) return 0;
        int allzero = 0, allone = 0;
        if(twocase) {
            allzero = ones - 2;
        }
        else allzero = ones - 1;
        allone = zeros;
        return min(allzero,allone);
    }
};