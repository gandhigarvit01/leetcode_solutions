class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        int k = n-(numFriends-1);
        if(numFriends==1) return word;
        string ans(k,'a');
        for(int i=0; i<n; i++){
            if(word.substr(i,min(k,n-i))>ans){
                ans = word.substr(i,k);
            }
        }
        return ans;
    }
};