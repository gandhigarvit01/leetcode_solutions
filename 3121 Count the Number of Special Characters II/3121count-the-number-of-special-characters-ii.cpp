class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        int ans = 0;
        vector<int> small(26,-1);
        vector<int> big(26,-1);
        for(int i=0; i<n; i++){
            if(islower(word[i])){
                small[word[i]-'a'] = i;
            }
            else{
                if(big[word[i]-'A'] == -1) big[word[i]-'A'] = i;
            }
        }
        for(int i=0; i<26; i++){
            if(small[i]!=-1 && big[i]!=-1 && small[i]<big[i]) ans++;
        }
        return ans;
    }
};