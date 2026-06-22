class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size();
        unordered_map<char,int> mpp;
        for(int i=0; i<n; i++){
            if(text[i]=='b' || text[i]=='a' || text[i]=='l' || text[i]=='o' || text[i]=='n'){
                mpp[text[i]]++;
            }
        }
        int ans = INT_MAX;
        ans = min(ans, mpp['a']);
        ans = min(ans, mpp['b']);
        ans = min(ans, mpp['l']/2);
        ans = min(ans, mpp['o']/2);
        ans = min(ans, mpp['n']);
        return ans;
    }
};