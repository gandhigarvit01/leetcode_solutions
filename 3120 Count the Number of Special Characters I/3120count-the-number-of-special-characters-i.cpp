class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans = 0;
        vector<int> small(26,0);
        vector<int> big(26,0);
        int n = word.size();
        for(int i=0; i<n; i++){
            if(islower(word[i])){
                small[word[i]-'a']++;
            }
            else{
                big[word[i]-'A']++;
            }
        }
        for(int i=0; i<26; i++){
            if(small[i]>0 && big[i]>0) ans++;
        }
        return ans;
    }
};