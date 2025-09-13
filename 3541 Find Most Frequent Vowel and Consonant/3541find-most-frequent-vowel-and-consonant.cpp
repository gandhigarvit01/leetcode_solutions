class Solution {
public:
    int maxFreqSum(string s) {
        int n = s.size();
        int vowels = 0;
        int cons = 0;
        vector<int> count(26,0);
        for(int i=0; i<n; i++){
            count[s[i]-'a']++;
        }
        for(int i=0; i<26; i++){
            if(i==0 || i==4 || i==8 || i==14 || i==20){
                vowels = max(vowels,count[i]);
            }
            else{
                cons = max(cons,count[i]);
            }
        }
        return vowels+cons;
    }
};