class Solution {
public:
    int wavy(int n){
        string s = to_string(n);
        if(s.size()<=2) return 0;
        int m = s.size();
        int res = 0;
        for(int i=1; i<m-1; i++){
            if(s[i]>s[i-1] && s[i]>s[i+1]) res++;
            else if(s[i]<s[i-1] && s[i]<s[i+1]) res++;
        }
        return res;
    }
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for(int i=num1; i<=num2; i++){
            ans += wavy(i);
        }
        return ans;
    }
};