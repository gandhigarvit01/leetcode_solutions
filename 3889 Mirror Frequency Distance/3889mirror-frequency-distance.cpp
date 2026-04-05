class Solution {
public:
    int mirrorFrequency(string s) {
        int n = s.size();
        vector<int> digit(10,0);
        vector<int> letter(26,0);
        for(int i=0; i<n; i++){
            if(isalpha(s[i])){
                letter[s[i]-'a']++;
            }
            else{
                digit[s[i]-'0']++;
            }
        }
        int ans = 0;
        for(int i=0; i<=4; i++){
            ans += abs(digit[i] - digit[9-i]);
        }
        for(int i=0; i<=12; i++){
            ans += abs(letter[i] - letter[25-i]);
        }
        return ans;
    }
};