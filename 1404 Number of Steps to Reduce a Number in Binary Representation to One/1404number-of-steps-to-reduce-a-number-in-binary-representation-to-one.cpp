class Solution {
public:
    int numSteps(string s) {
        int n = s.size();
        int l = 0, r = n-1;
        int steps = 0;
        while(l<r){
            if(s[r]=='0'){
                r--;
                steps++;
            }
            else{
                int i = r;
                while(i>=l && s[i]=='1'){
                    if(i==l){
                        steps += r-l+2;
                        return steps;
                    }
                    s[i] = '0';
                    i--;
                }
                s[i] = '1';
                steps++;
            }
        }
        return steps;
    }
};